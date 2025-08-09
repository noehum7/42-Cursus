/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:01:10 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 13:01:11 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdint.h>

struct Data
{
	std::string	name;
	size_t		age;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer &operator=(const Serializer &copy);
	
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
