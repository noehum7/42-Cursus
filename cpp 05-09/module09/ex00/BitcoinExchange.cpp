/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:10:27 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/16 18:28:30 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : _map(std::map<std::string, float>()) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _map(copy._map) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (this != &copy)
		this->_map = copy._map;
	return (*this);
}

bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int	y, m, d;
	if (sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d) != 3)
		return (false);
	if (y < 2009 || m < 1 || m > 12 || d < 1 || d > 31)
		return (false);
	static const int	days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int	max_day = days_in_month[m - 1];

	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
		max_day = 29;
	if (d > max_day)
		return (false);
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string &value) const
{
	char	*end;
	double	val = std::strtod(value.c_str(), &end);
	if (*end != '\0')
		return (false);
	if (val < 0)
		return (false);
	if (val > 1000)
		return (false);
	return (true);
}

void	BitcoinExchange::printError(const std::string &error) const
{
	std::cout << "Error: " << error << std::endl;
}

void	BitcoinExchange::loadDataBase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());

	if (!file)
	{
		printError("couldn't open database file.");
		return ;
	}
	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream	ss(line);
		std::string	date, rate;
		if (!std::getline(ss, date, ',') || !std::getline(ss, rate))
			continue ;
		_map[date] = static_cast<float>(std::atof(rate.c_str()));
	}
}

void	BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream	file(filename.c_str());

	if (!file)
	{
		printError("couldn't open file.");
		return ;
	}
	std::string	line;
	if (!std::getline(file, line))
		return ;
	if (line != "date | value")
	{
		printError("the first line must be \"date | value\".");
		return ;
	}
	while (std::getline(file, line))
	{
		std::istringstream	iss(line);
		std::string	date, pipe, value, extra;

		if (!(iss >> date >> pipe >> value) || (iss >> extra))
		{
			printError("bad input => " + line);
			continue ;
		}
		if (pipe != "|")
		{
			printError("bad input => " + line);
			continue ;
		}
		if (!isValidDate(date))
		{
			printError("bad input => " + line);
			continue ;
		}
		if (!isValidValue(value))
		{
			double	val = std::strtod(value.c_str(), NULL);
			if (val < 0)
				printError("not a positive number.");
			else if (val > 1000)
				printError("too large a number.");
			else
				printError("bad input => " + line);
			continue ;
		}
		double	val = std::strtod(value.c_str(), NULL);
		float	rate = getRateForDate(date);

		if (rate < 0)
			continue ;
		std::cout << date << " => " << value << " = " << val * rate << std::endl;
	}
}

float	BitcoinExchange::getRateForDate(const std::string &date)
{
	std::map<std::string, float>::iterator	it = _map.lower_bound(date);
	if (it != _map.end() && it->first == date)
		return (it->second);
	if (it == _map.begin())
	{
		printError("no rate available for date (too early)");
		return (-1.0f);
	}
	--it;
	return (it->second);
}
