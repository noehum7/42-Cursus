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

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: couldn't open file." << std::endl;
		return (1);
	}
	BitcoinExchange	btc;
	btc.loadDataBase("data.csv");
	btc.processInput(av[1]);
	return (0);
}
