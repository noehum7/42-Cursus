/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:47:04 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/16 12:47:05 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string input = "";
	PhoneBook phonebook;

	while (true)
	{
		std::cout << "=============== WELCOME ===============" << std::endl
				  << "Please enter a command: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
	}
	std::cout << "Thank you for using my application. CU soon!:)" << std::endl;
	return (0);
}
