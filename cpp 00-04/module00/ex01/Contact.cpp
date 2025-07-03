/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:47:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/16 12:47:01 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string n, std::string ds) : _firstName(fn), _lastName(ln), _nickname(nn), _number(n), _secret(ds) {}

std::string Contact::getFirstName() const 
{
	return _firstName;
}

std::string Contact::getLastName() const 
{
	return _lastName;
}

std::string Contact::getNickname() const 
{
	return _nickname;
}

std::string Contact::getNumber() const 
{
	return _number;
}

std::string Contact::getDarkestSecret() const 
{
	return _secret;
}
