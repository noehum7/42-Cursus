/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:42:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/08/13 15:42:01 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "headers.hpp"
#include "Parser.hpp"
#include "Client.hpp"
#include "Server.hpp"
#include "Channel.hpp"
#include "ModeHandler.hpp"

class Commands
{
	public:
		static void execute(const Message &msg, Client *client, Server *server);
	
	private:
		static std::string getPrefix(Client *client);
		static void handlePass(const Message &msg, Client *client, Server *server);
		static void handleNick(const Message &msg, Client *client, Server *server);
		static void handleUser(const Message &msg, Client *client, Server *server);
		static void handleJoin(const Message &msg, Client *client, Server *server);
		static void handlePart(const Message &msg, Client *client, Server *server);
		static void handlePrivmsg(const Message &msg, Client *client, Server *server);
		static void handleQuit(const Message &msg, Client *client, Server *server);
		static void handleKick(const Message &msg, Client *client, Server *server);
		static void handleInvite(const Message &msg, Client *client, Server *server);
		static void handleTopic(const Message &msg, Client *client, Server *server);
		static void handleMode(const Message &msg, Client *client, Server *server);
};

#endif