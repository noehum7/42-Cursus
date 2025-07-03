/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:38:46 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 13:11:57 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl		harl;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			level = -1;

	if (ac != 2)
	{
		std::cout << "Usage a correct level: DEBUG, INFO, WARNING OR ERROR." << std::endl;
		return (1);
	}
	for	(int i = 0; i < 4; i++)
		if (levels[i] == av[1])
			level = i;
	switch(level)
	{
		case 0:
			harl.complain(levels[0]);
			// fall through
		case 1:
			harl.complain(levels[1]);
			// fall through
		case 2:
			harl.complain(levels[2]);
			// fall through
		case 3:
			harl.complain(levels[3]);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
	return (0);
}
