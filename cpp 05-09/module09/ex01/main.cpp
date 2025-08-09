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

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	try
	{
		if (ac != 2)
		{
			std::cerr << "Error: Usage: ./RPN \"<expression>\"" << std::endl;
			return (1);
		}
		rpn(av[1]);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
