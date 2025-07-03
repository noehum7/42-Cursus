/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:52:27 by nporras-          #+#    #+#             */
/*   Updated: 2025/05/09 11:02:00 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	zombiesName;
	int			nZombies;
	
	do
	{
		std::cout << "Enter the name of zombies: " << std::endl;
		if (!std::getline(std::cin, zombiesName))
			return 1;
		if (zombiesName.empty())
			std::cout << "Error: Name cannot be empty!" << std::endl;
	} while (zombiesName.empty());
	
	do
	{
		std::cout << "Enter the number of zombies: " << std::endl;
		if (!(std::cin >> nZombies))
		{
			if (std::cin.eof())
				return 1;
			std::cout << "Invalid input. Enter a valid number." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		else if (nZombies <= 0)
			std::cout << "Number must be positive." << std::endl;
	} while (std::cin.fail() || nZombies <= 0);

	Zombie		*zombies = zombieHorde(nZombies, zombiesName);
	for (int i = 0; i < nZombies; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
