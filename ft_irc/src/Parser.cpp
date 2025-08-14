/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:29:54 by kmoundir          #+#    #+#             */
/*   Updated: 2025/08/13 15:51:33 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "Utils.hpp"
#include "debug.hpp"


Message::Message(){}
Message::Message(const std::string& cmd, const std::vector<std::string>& params, const std::string& trail)
{
    command = cmd;
    this->params = params;
    trailing = trail;
}

Parser::Parser(){}
Parser::Parser(const Parser& obj){(void)obj;}
Parser& Parser::operator=(const Parser& other){(void)other; return *this;}
Parser::~Parser(){}

Message Parser::parseMessage(const std::string& raw_message)
{
    DEBUG_LOG("Parsing message: '" << raw_message << "'");
    
    Message msg;
    std::string message = raw_message;
    
    message = removeIRCTerminator(message);
    DEBUG_LOG("After removing terminators: '" << message << "'");
    
    msg.prefix = extractPrefix(message);
    DEBUG_LOG("Extracted prefix: '" << msg.prefix << "'");
    
    if (!msg.prefix.empty()) {
        message = message.substr(message.find(' ') + 1);
        DEBUG_LOG("Message after prefix removal: '" << message << "'");
    }
    
    msg.command = toupperStr(extractCmd(message));
    DEBUG_LOG("Extracted command: '" << msg.command << "'");

    message = removeCMD(message);
    DEBUG_LOG("Message after command removal: '" << message << "'");
    
    msg.trailing = extractTrailing(message);
    DEBUG_LOG("Extracted trailing: '" << msg.trailing << "'");

    message = removeTrailing(message);
    DEBUG_LOG("Message after trailing removal: '" << message << "'");
    
    msg.params = splitParams(message);
    if (g_debugMode) {
        std::stringstream ss;
        ss << "Extracted params: [";
        for (size_t i = 0; i < msg.params.size(); ++i) {
            if (i > 0) ss << ", ";
            ss << "'" << msg.params[i] << "'";
        }
        ss << "]";
        DEBUG_LOG(ss.str());
    }
    
    return msg; 
}

std::string Parser::removeIRCTerminator(const std::string& raw_message)
{
    std::string message = raw_message;
    if(message.length() >= 2 && message.substr(message.length() - 2) == "\r\n")
    {
        message = message.substr(0, message.length() - 2);
    }
    return message;
}

std::string Parser::extractPrefix(const std::string& message)
{
    
    if(!message.empty() && message[0] == ':')
    {
        size_t space_pos = message.find(' ');
        if(space_pos != std::string::npos)
            return  message.substr(1,space_pos - 1);        
        else
            return message.substr(1);
    }
    return "";
}

std::string Parser::extractCmd(const std::string& message)
{
   
    size_t space_pos = message.find(' ');

    if(space_pos != std::string::npos)
        return message.substr(0, space_pos);
    return message;
}

std::string Parser::toupperStr(const std::string& command)
{
    std::string msg = command;
    for(size_t i = 0; i < msg.length(); i ++)
		msg[i] = toupper(msg[i]);   
    return msg; 
}

std::string Parser::extractTrailing(const std::string& message)
{
    size_t pos_colon = message.find(" :");
    if(pos_colon != std::string::npos)
        return message.substr(pos_colon + 2);
    return "";
}

std::vector<std::string> Parser::splitParams(const std::string& params)
{
    std::vector<std::string>  vectParams ;   
    if(!params.empty())
        vectParams = split(params, ' ');
    return vectParams;
}

std::string Parser::removeCMD(const std::string& message)
{
     size_t cmdPos = message.find(' ');
    if (cmdPos != std::string::npos) 
        return message.substr(cmdPos + 1);
    return "";
}

std::string Parser::removeTrailing(const std::string& message)
{
    size_t trailPos = message.find(" :");
    if (trailPos != std::string::npos)
       return message.substr(0, trailPos);
    return message;
}

bool Parser::isValidNickname(const std::string& nickname)
{
    if (nickname.empty() || nickname.length() > 9)
        return false;
    const std::string special = "[]\\`_^{|}";
    char first = nickname[0];
    if (!std::isalpha(first) && special.find(first) == std::string::npos)
        return false;
    for (size_t i = 1; i < nickname.length(); ++i)
    {
        char c = nickname[i];
        if (!std::isalnum(c) && special.find(c) == std::string::npos && c != '-')
            return false;
        if (std::isspace(c) || c == ',' || std::iscntrl(c))
            return false;
    }
    return true;
}

bool Message::isValid() const
{
    if(command.empty())
        return false;
    return true;
}

bool	Parser::isValidChannelName(const std::string& channel)
{
    if (channel.empty() || (channel[0] != '#' && channel[0] != '&'))
        return false;
    if (channel.length() <= 1)
        return false;
    for (size_t i = 1; i < channel.length(); ++i)
    {
        char c = channel[i];
        if (std::isspace(c) || c == ',' || c == '\a' || std::iscntrl(c))
            return false;
    }
    return true;
}