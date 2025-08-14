/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:41:11 by nporras-          #+#    #+#             */
/*   Updated: 2025/08/13 15:41:31 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "headers.hpp"

class	Client;

class Channel
{
	private:
		std::string				_name;
		std::string				_topic;
		Client					*_topicSetter;
		std::vector<Client*>	_users;
		std::set<Client*>		_operators;
		std::set<Client*>		_invited;
		bool					_inviteOnly;
		bool					_topicRestricted;
		std::string				_key;
		bool					_hasKey;
		int						_userLimit;
		bool					_hasUserLimit;

	public:
		Channel(const std::string& name);
		~Channel();

		const std::string& getName() const;
		const std::string& getTopic() const;
		const std::string& getKey() const;
		int getUserLimit() const;
		Client* getTopicSetter() const;
		std::vector<Client*> getUsers() const;

		bool isInviteOnly() const;
		bool isTopicRestricted() const;
		bool hasKey() const;
		bool isUserInChannel(Client* user) const;
		bool isOperator(Client* user) const;
		bool isInvited(Client* user) const;

		void setInviteOnly(bool value);
		void setTopicRestricted(bool value);
		void setKey(const std::string& key);
		void removeKey();
		void setUserLimit(int limit);
		void removeUserLimit();

		void setTopic(const std::string& topic, Client* setter);
		void clearTopic();

		bool addUser(Client* user, const std::string& key = "");
		void removeUser(Client* user);

		void addOperator(Client* user);
		void removeOperator(Client* user);

		void inviteUser(Client* user);
		void removeInvite(Client* user);
};

#endif