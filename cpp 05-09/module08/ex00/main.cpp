/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:16:51 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 18:16:52 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "easyfind.hpp"

int	main()
{
	std::vector<int>	v;

	for (int i = 1; i <= 5; i++)
		v.push_back(i);

	std::cout << "🔎 Searching number 3..." << std::endl;
	try
	{
		std::vector<int>::const_iterator it = easyFind(v, 3);
		std::cout << "✅ Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "❌ " << e.what() << std::endl;
	}
	std::cout << "🔎 Searching number 7..." << std::endl;
	try
	{
		std::vector<int>::const_iterator it = easyFind(v, 7);
		std::cout << "✅ Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "❌ " << e.what() << std::endl;
	}
	return (0);
}
