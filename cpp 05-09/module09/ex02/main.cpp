/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:51:19 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/15 17:51:20 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iostream>

int	main(int ac, char **av)
{
	std::vector<int>	vec;
	std::deque<int>	deq;

	if (!parseInput(ac, av, vec, deq))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	printSequence("Before:", vec);

	clock_t	start = clock();
	sortVector(vec);
	clock_t	end = clock();
	double timeVec = 1000.0 * (end - start) / CLOCKS_PER_SEC;

	start = clock();
	sortDeque(deq);
	end = clock();
	double	timeDeq = 1000.0 * (end - start) / CLOCKS_PER_SEC;

	printSequence("After:", vec);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << timeVec << " ms" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << timeDeq << " ms" << std::endl;
}
