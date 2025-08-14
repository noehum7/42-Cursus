/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:30:19 by kmoundir          #+#    #+#             */
/*   Updated: 2025/08/13 15:56:57 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Client.hpp"
#include "headers.hpp"
#include "Utils.hpp"
#include "Parser.hpp"
#include "Commands.hpp"
#include "debug.hpp"

Server::Server(int port, std::string password):_port(port),_password(password){}
Server::Server(const Server& other):_port(other._port),_password(other._password){}

Server& Server::operator=(const Server& other)
{
    if(this != &other)
    {
        _port = other._port;
        _password = other._password;
    }
    return  *this;
}

Server::~Server()
{
   stop();
}

void  Server::start()
{
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) 
    {
        std::cerr<<"Error: socket creating failure"<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    fcntl(server_socket, F_SETFL, O_NONBLOCK);
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    std::string port_str = to_string(_port);
    
    int status = getaddrinfo(NULL, port_str.c_str(), &hints, &result);
    if(status != 0)
    {
        std::cerr << "getaddrinfo error" <<gai_strerror(status) << std::endl;
        exit(EXIT_FAILURE);
    }   
    int opt = 1;
    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        std::cerr <<"Error: setsockopt failed"<<std::endl;
        exit(EXIT_FAILURE);
    }
    fcntl(server_socket, F_SETFL, O_NONBLOCK);
    if(bind(server_socket, result->ai_addr, result->ai_addrlen) != 0)
    {
        std::cerr <<"Error: bind failure"<<std::endl;
         freeaddrinfo(result);
        exit(EXIT_FAILURE); 
    }
    if(listen(server_socket, 1024) != 0)
    {
        std::cerr <<"Error: listen failure" <<std::endl;
        freeaddrinfo(result);
        exit(EXIT_FAILURE); 
    }
    std::cout <<"Server started successfully on port "<<_port <<std::endl;
    freeaddrinfo(result);
}

void Server::run()
{
    pollfd serverPfd;
    serverPfd.fd = server_socket;
    serverPfd.events = POLLIN;
    serverPfd.revents = 0;
    pollFds.push_back(serverPfd);
    
    while(true)
    {
        int newFd = poll(pollFds.data(), pollFds.size(),-1);
        if(newFd > 0)
        {
            for(size_t i = 0; i < pollFds.size(); i++)
            {
                if(pollFds[i].revents & POLLIN)
                {
                    if(pollFds[i].fd == server_socket)
                        handleNewConnection();
                    else
                        handleClientMessage(pollFds[i].fd);    
                }
            }
        }
    }
}

void Server::handleNewConnection()
{
    sockaddr_storage their_addr;
    socklen_t addr_size = sizeof(their_addr);
    int clientFd = accept(server_socket, (sockaddr*)&their_addr, &addr_size);
    
    if(clientFd < 0)
    {
        std::cerr <<"ERROR: accept new user failed!"<<std::endl;
        return ;
    }
    char clientIP[INET6_ADDRSTRLEN];
    if (their_addr.ss_family == AF_INET) {
        struct sockaddr_in *ipv4 = (struct sockaddr_in *)&their_addr;
        inet_ntop(AF_INET, &(ipv4->sin_addr), clientIP, INET6_ADDRSTRLEN);
    } else {
        struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)&their_addr;
        inet_ntop(AF_INET6, &(ipv6->sin6_addr), clientIP, INET6_ADDRSTRLEN);
    }
    
    fcntl(clientFd, F_SETFL, O_NONBLOCK);
    pollfd clientPollFd;
    clientPollFd.fd = clientFd;
    clientPollFd.events = POLLIN;
    clientPollFd.revents = 0;
    pollFds.push_back(clientPollFd);
	clients[clientFd] = new Client(clientFd, std::string(clientIP));
    std::cout << "New client connected on fd: " << clientFd << std::endl;
}
void Server::handleClientMessage(int fd)
{
	char buffer[1024];
    memset(buffer, 0,sizeof(buffer));
    int bytes_received = recv(fd, buffer, sizeof(buffer) - 1, 0);
    if(bytes_received <= 0)
    {
        if(bytes_received == 0)
            std::cout <<"CLient with fd = "<< fd <<" disconnected" <<std::endl;
        else
            std::cout<<"Error receiving from client "<< fd << std::endl;
        removeClient(fd);
        return ;
    }
    else
    {
        buffer[bytes_received] = '\0';
        Client* client = clients[fd];
        std::string data(buffer);
        
        DEBUG_LOG_SERVER("Received " << bytes_received << " bytes from client " << fd);
        client->appendToBuffer(data);
        while (clients.find(fd) != clients.end() && client->hasCompleteMessage()) 
        {
            std::string line = client->extractMessage();
            line = trim(line);
            if (!line.empty()) 
            {
                DEBUG_LOG_SERVER("Processing complete message: '" << line << "'");
                Parser parser;
                Message msg = parser.parseMessage(line);
                Commands::execute(msg, client, this);
            
                if (clients.find(fd) == clients.end()) {
                    DEBUG_LOG_SERVER("Client was removed during command execution, stopping processing");
                    return ;
                }
            } 
            else 
                DEBUG_LOG_SERVER("Skipping empty message");
        }
    }
}

void Server::removeClient(int fd)
{
    std::cout << "removing client " << fd << " from server" << std::endl;
    std::map<int, Client*>::iterator client_it = clients.find(fd);
    if (client_it != clients.end())
    {
        Client* client = client_it->second;
        if (client->isRegistered())
        {
            std::string prefix = ":" + client->getNickname() + "!" + client->getUsername() + "@" + client->getHostname();
            std::string quitMsg = prefix + " QUIT :Connection lost\r\n";
            for (std::map<std::string, Channel*>::iterator it = channels.begin(); it != channels.end(); ++it) 
            {
                Channel* channel = it->second;
                if (channel->isUserInChannel(client))
                {
                    std::vector<Client*> users = channel->getUsers();
                    for (size_t i = 0; i < users.size(); ++i)
                    {
                        if (users[i] != client)
                            users[i]->sendMessage(quitMsg);
                    }
                    channel->removeUser(client);
                }
            }
        }
        else
        {
            for (std::map<std::string, Channel*>::iterator it = channels.begin(); it != channels.end(); ++it) {
                Channel* channel = it->second;
                if (channel->isUserInChannel(client))
                    channel->removeUser(client);
            }
        }
        if (close(fd) < 0)
            std::cerr << "Error closing socket fd " << fd << std::endl;
        delete client;
        clients.erase(client_it);
    }
    std::vector<pollfd>::iterator it = pollFds.begin();
    for (; it != pollFds.end(); ++it)
    {
        if (it->fd == fd)
        {
            pollFds.erase(it);
            break;
        }
    }
}

Channel* Server::createChannel(std::string name) 
{
    DEBUG_LOG_SERVER("Creating channel: '" << name << "'");
    if (channels.find(name) != channels.end()) {
        DEBUG_LOG_SERVER("Channel '" << name << "' already exists");
        return  channels[name];
    }
    Channel* newChannel = new Channel(name);
    channels[name] = newChannel;
    DEBUG_LOG_SERVER("Channel '" << name << "' created successfully");
    return  newChannel;
}



void Server::stop()
{
    DEBUG_LOG_SERVER("Server shutting down...");
    std::cout << "======= Server stopping ========" << std::endl;

    for (std::map<int, Client*>::iterator it = clients.begin(); it != clients.end(); ++it)
    {
        DEBUG_LOG_CLIENT(it->second, "Closing connection");
        close(it->first);
        delete it->second;
    }
    clients.clear();
    if (server_socket != -1)
    {
        DEBUG_LOG_SERVER("Closing server socket " << server_socket);
        close(server_socket);
        server_socket = -1;
    }
    pollFds.clear();
    std::vector<pollfd>().swap(pollFds);
    for (std::map<std::string, Channel*>::iterator it = channels.begin(); it != channels.end(); ++it)
    {
        DEBUG_LOG_CHANNEL(it->second, "Deleting channel");
        delete it->second;
    }
    channels.clear();
    DEBUG_LOG_SERVER("Server shutdown complete");
}