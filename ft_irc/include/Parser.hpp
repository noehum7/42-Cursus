/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:29:44 by kmoundir          #+#    #+#             */
/*   Updated: 2025/08/13 15:47:21 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "headers.hpp"
#include "Utils.hpp"

struct Message
{    
    std::string prefix;
    std::string command;
    std::vector<std::string> params;
    std::string trailing;
    
    Message();
    Message(const std::string& cmd, const std::vector<std::string>& params, const std::string& trail);
    bool isValid() const;
};

class Parser
{
    public:    
        Parser();
        Parser(const Parser& obj);
        Parser& operator=(const Parser& other);
        ~Parser();
        
        static Message parseMessage(const std::string& raw_message);
        
        static std::vector<std::string> splitParams(const std::string& params);
        static bool isValidNickname(const std::string& nickname);
        static bool isValidChannelName(const std::string& channel);

        static std::string extractTrailing(const std::string& message);
        static std::string extractPrefix(const std::string& message);
        static std::string extractCmd(const std::string& messsage);
        static std::string toupperStr(const std::string& command);

        static std::string removeIRCTerminator(const std::string& message);
        static std::string removeCMD(const std::string& message);
        static std::string removeTrailing(const std::string& message);
};


#endif