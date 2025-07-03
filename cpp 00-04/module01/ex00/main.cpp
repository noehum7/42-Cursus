/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:35:35 by nporras-          #+#    #+#             */
/*   Updated: 2025/05/09 10:35:36 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string nameStack;
	std::string nameHeap;
	Zombie* zombieHeap;

	std::cout << "Enter a name to the stack zombie: " << std::endl;
	std::cin >> nameStack;
	std::cout << "Enter a name to the heap zombie: " << std::endl;
	std::cin >> nameHeap;

	randomChump(nameStack);

	zombieHeap = newZombie(nameHeap);
	zombieHeap->announce();
	
	delete zombieHeap;

	return (0);
}
