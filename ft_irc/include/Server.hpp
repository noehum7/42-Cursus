/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:30:23 by kmoundir          #+#    #+#             */
/*   Updated: 2025/08/13 15:48:02 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include "Channel.hpp"
# include "Client.hpp"
# include "headers.hpp"

class Server
{
	private:
		int _port;
		std::string _password;
		int server_socket;
		std::vector<pollfd> pollFds;
		std::map<int, Client *> clients;
		struct addrinfo hints, *result;
		std::map<std::string, Channel *> channels;

	public:
		Server(int port, std::string password);
		~Server();
		Server(const Server &other);
		Server &operator=(const Server &other);

		void start();
		void run();
		void stop();

		void handleNewConnection();
		void handleClientMessage(int fd);
		void removeClient(int fd);
		Channel *createChannel(std::string name);
		Channel *getChannel(std::string name);
		Client *getClient(std::string nickname);
		std::map<std::string, Channel *> &getChannels();

		int getPort() const;
		std::string getPassword() const;
		void setPort(int port);
		void setPassword(const std::string &password);
};

#endif