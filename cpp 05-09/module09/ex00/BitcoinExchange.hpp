/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:52:27 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/16 18:24:19 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <map>
# include <string>
# include <iostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_map;
		bool	isValidDate(const std::string &date) const;
		bool	isValidValue(const std::string &value) const;
		void	printError(const std::string &error) const;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange &copy);
		void	loadDataBase(const std::string &filename);
		void	processInput(const std::string &filename);
		float	getRateForDate(const std::string &date);
};
