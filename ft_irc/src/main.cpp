/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:44:25 by kmoundir          #+#    #+#             */
/*   Updated: 2025/08/13 15:50:09 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "headers.hpp"
#include "Utils.hpp"
#include "Server.hpp"
#include "debug.hpp"
#include <csignal>
#include "banner.hpp"

static Server* g_server = NULL;
volatile sig_atomic_t g_shutdown_req = 0;

void signal_handler(int signum) {
    std::cout << "\nReceived signal " << signum << std::endl;
    if (g_server) {
        std::cout << "Shutting down server gracefully..." << std::endl;
        g_server->stop();
    }
    exit(signum);
}

int main(int argc, char **argv)
{
    banner();
    bool debug_mode = false;
    int arg_offset = 0;
    
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    
    if (argc > 1 && std::string(argv[1]) == "--debug") {
        debug_mode = true;
        arg_offset = 1;
        enableDebugMode();
        std::cout << "Debug mode enabled" << std::endl;
    }
    
    if (argc - arg_offset != 3) {
        std::cout << "Usage: " << argv[0] << " [--debug] <port> <password>" << std::endl;
        return 1;
    }

    if(!validateInput(argv + arg_offset))
    {   
        std::cout << "ERROR: Invalid input!" << '\n';
        return 1;
    }

    int port = atoi(argv[1 + arg_offset]);
    std::string password = argv[2 + arg_offset];
    
    if (debug_mode) {
        DEBUG_LOG_SERVER("Starting IRC server on port: " << port);
        DEBUG_LOG_SERVER("Password: " << password);
    }
    
    Server server_irc(port, password);
    g_server = &server_irc;
    try {
        server_irc.start();
        server_irc.run();
    } 
    catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        server_irc.stop();
        return 1;
    }
    server_irc.stop();
    return 0;
}
