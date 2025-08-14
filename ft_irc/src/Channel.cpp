/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:40:41 by nporras-          #+#    #+#             */
/*   Updated: 2025/08/13 15:40:49 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "Client.hpp"

Channel::Channel(const std::string &name) : _name(name), _topic(""), _topicSetter(NULL), _inviteOnly(false),
_topicRestricted(false), _key(""), _hasKey(false), _userLimit(0), _hasUserLimit(false) {}

Channel::~Channel() {}

const std::string &Channel::getName() const { return _name; }
const std::string &Channel::getTopic() const { return _topic; }
const std::string &Channel::getKey() const { return _key; }
int Channel::getUserLimit() const { return _userLimit; }
bool Channel::isInviteOnly() const { return _inviteOnly; }
bool Channel::isTopicRestricted() const { return _topicRestricted; }
bool Channel::hasKey() const { return _hasKey; }

bool	Channel::addUser(Client *user, const std::string &key)
{
	(void)key;
	if (isUserInChannel(user))
		return false;
	if (_users.empty())
		addOperator(user);
	_users.push_back(user);
	removeInvite(user);
	return true;
}

void	Channel::removeUser(Client *user)
{
	removeOperator(user);
	removeInvite(user);

	for (std::vector<Client*>::iterator it = _users.begin(); it != _users.end(); ++it)
	{
		if (*it == user)
		{
			_users.erase(it);
			break ;
		}
	}
}

void	Channel::removeOperator(Client *user)
{
	_operators.erase(user);
	if (_operators.empty() && !_users.empty())
	{
		Client* newOp = NULL;
		for (size_t i = 0; i < _users.size(); ++i)
		{
			if (_users[i] != user)
			{
				newOp = _users[i];
				break ;
			}
		}
		if (!newOp && !_users.empty())
			newOp = _users.front();
		if (newOp)
		{
			addOperator(newOp);
			std::string modeMsg = ":" + newOp->getNickname() + " MODE " + _name + " +o " + newOp->getNickname() + "\r\n";
			for (size_t i = 0; i < _users.size(); ++i)
				_users[i]->sendMessage(modeMsg);
		}
	}
}

bool	Channel::isUserInChannel(Client *user) const {
	for (std::vector<Client*>::const_iterator it = _users.begin(); it != _users.end(); ++it)
		if (*it == user)
			return true;
	return false;
}

std::vector<Client *>	Channel::getUsers() const { return _users; }

void	Channel::addOperator(Client *user) { _operators.insert(user); }

bool	Channel::isOperator(Client *user) const { return _operators.find(user) != _operators.end(); }

void	Channel::inviteUser(Client *user) { _invited.insert(user); }

bool	Channel::isInvited(Client *user) const { return _invited.find(user) != _invited.end(); }

void	Channel::removeInvite(Client *user) { _invited.erase(user); }

void	Channel::setTopic(const std::string &topic, Client *setter)
{
	if (topic == ":" || topic.find_first_not_of(" :") == std::string::npos)
		_topic.clear();
	else
		_topic = topic;
	_topicSetter = setter;
}

void	Channel::clearTopic()
{
	_topic = "";
	_topicSetter = NULL;
}

Client	*Channel::getTopicSetter() const
{
	return _topicSetter;
}

void	Channel::setInviteOnly(bool value) { _inviteOnly = value; }

void	Channel::setTopicRestricted(bool value) { _topicRestricted = value; }

void	Channel::setKey(const std::string &key)
{
	_key = key;
	_hasKey = true;
}

void	Channel::removeKey()
{
	_key = "";
	_hasKey = false;
}

void	Channel::setUserLimit(int limit)
{
	_userLimit = limit;
	_hasUserLimit = true;
}

void	Channel::removeUserLimit()
{
	_userLimit = 0;
	_hasUserLimit = false;
}