/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:47:11 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/16 12:47:12 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <stdlib.h>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int _contactCount;
		int _oldestIndex;
		std::string truncateStr(const std::string& str);
		void displayContactList();
		void displayContact(int index);
	
	public:
		PhoneBook(void);
		void add(void);
		void search(void);
};

#endif
