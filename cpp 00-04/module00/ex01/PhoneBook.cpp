/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:47:09 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/16 12:47:10 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_contactCount = 0;
	_oldestIndex = 0;
}

std::string PhoneBook::truncateStr(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::displayContactList()
{
	if (_contactCount == 0)
	{
		std::cout << "No contacts saved" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "FirstName" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << std::setw(10) << i + 1  << "|"
				  << std::setw(10) << truncateStr(_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << truncateStr(_contacts[i].getLastName()) << "|" 
				  << std::setw(10) << truncateStr(_contacts[i].getNickname()) <<
				  "|" 
				  << std::endl;
	}
}

void PhoneBook::displayContact(int index)
{
	if (index < 0 || index > _contactCount - 1)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "First name: " << _contacts[index].getFirstName() << std::endl
			  << "Last name: " << _contacts[index].getLastName() << std::endl
			  << "Nickname: " << _contacts[index].getNickname() << std::endl
			  << "Phone number: " << _contacts[index].getNumber() << std::endl
			  << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::add()
{
	std::string fn, ln, nn, num, ds;

	do {
		std::cout << "Enter your first name: ";
		std::getline(std::cin, fn);
		if (std::cin.eof())
			return ;
		if (fn.empty())
			std::cout << "Field can't be empty. Try again.\n";
	} while (fn.empty());
	do
	{
		std::cout << "Enter your last name: ";
		std::getline(std::cin, ln);
		if (std::cin.eof())
			return ;
		if (ln.empty())
			std::cout << "Field can't be empty. Try again.\n";
	} while (ln.empty());
	do
	{
		std::cout << "Enter your nickname: ";
		std::getline(std::cin, nn);
		if (std::cin.eof())
			return ;
		if (nn.empty())
			std::cout << "Field can't be empty. Try again.\n";
	} while (nn.empty());
	do
	{
		std::cout << "Enter your number: ";
		std::getline(std::cin, num);
		if (std::cin.eof())
			return ;
		if (num.empty())
			std::cout << "Field can't be empty. Try again.\n";
	} while (num.empty());
	do
	{
		std::cout << "Enter your darkest secret: ";
		std::getline(std::cin, ds);
		if (std::cin.eof())
			return ;
		if (ds.empty())
			std::cout << "Field can't be empty. Try again.\n";
	} while (ds.empty());
	
	if (_contactCount < 8)
	{
		_contacts[_contactCount] = Contact(fn, ln, nn, num, ds);
		_contactCount++;
	}
	else
	{
		_contacts[_oldestIndex] = Contact(fn, ln, nn, num, ds);
		_oldestIndex++;
		if (_oldestIndex == 8)
			_oldestIndex = 0;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::search()
{
	std::string	input;
	int	index;

	displayContactList();
	if (_contactCount == 0)
		return ;
	std::cout << "Enter the contact index" << std::endl;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	index = std::atoi(input.c_str());
	if (index <= 0 || index > _contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	displayContact(index - 1);
}
