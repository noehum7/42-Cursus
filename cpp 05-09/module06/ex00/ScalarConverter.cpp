/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:00:56 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 15:28:18 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isCharLiteral(std::string const &convert)
{
	if (convert.length() != 1)
		return (false);
	if (isdigit(convert[0]))
		return false;
	if (convert[0] < 32 || convert[0] > 126)
		return (false);
	return (true);
}

static bool isIntLiteral(std::string const &convert)
{
	if (convert.empty())
		return (false);
	size_t start = convert[0] == '-' ? 1 : 0;
	for (size_t i = start; i < convert.length(); i++)
		if (!isdigit(convert[i]))
			return (false);
	return (true);
}

static bool isFloatLiteral(std::string const &convert)
{
	if (convert == "nanf" || convert == "+inff" || convert == "-inff")
		return (true);
	if (convert.length() < 2 || convert[convert.length() - 1] != 'f')
		return (false);
	bool hasPoint = false;
	for (size_t i = 0; i < convert.length() - 1; i++)
	{
		if (convert[i] == '.' && hasPoint)
			return (false);
		else if (convert[i] == '.')
		{
			hasPoint = true;
			continue ;
		}
		if (!isdigit(convert[i]) && convert[i] != '-')
			return (false);
	}
	return (true);
}

static bool isDoubleLiteral(std::string const &convert)
{
	if (convert == "nan" || convert == "+inf" || convert == "-inf")
		return (true);
	if (convert.length() > 0 && convert[convert.length() - 1] == 'f')
		return (false);
	bool hasPoint = false;
	for (size_t i = 0; i < convert.length(); i++)
	{
		if (convert[i] == '.' && hasPoint)
			return (false);
		else if (convert[i] == '.')
		{
			hasPoint = true;
			continue ;
		}
		if (!isdigit(convert[i]) && convert[i] != '-')
			return (false);
	}
	return (hasPoint);
}

static void	convertFromChar(std::string const &convert)
{
	char	c = convert[0];

	if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	int	valueInt = static_cast<int>(c);
	std::cout << "int: " << valueInt << std::endl;

	float valueFloat = static_cast<float>(c);
	std::cout << "float: " << valueFloat << ".0f" << std::endl;

	double valueDouble = static_cast<double>(c);
	std:: cout << "double: " << valueDouble << ".0" << std::endl;
}

static void	convertFromInt(std::string const &convert)
{
	int num = atoi(convert.c_str());

	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else if (num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else 
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: " << num << std::endl;

	float numFloat = static_cast<float>(num);
	std::cout << "float: " << numFloat << ".0f" << std::endl;

	double numDouble = static_cast<double>(num);
	std::cout << "double: " << numDouble << ".0" << std::endl;
}

static void	convertFromFloat(std::string const &convert)
{
	float	num;

	if (convert == "nanf")
		num = std::numeric_limits<float>::quiet_NaN();
	else if (convert == "+inff") 
		num = std::numeric_limits<float>::infinity();
	else if (convert == "-inff")
		num = -std::numeric_limits<float>::infinity();
	else 
	{
		std::string numberPart = convert.substr(0, convert.length() - 1);
		num = std::atof(numberPart.c_str());
	}

	if (std::isnan(num) || std::isinf(num))
		std::cout << "char: impossible" << std::endl;
	else if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	
	if (std::isnan(num) || std::isinf(num))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (std::isnan(num))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(num))
		std::cout << "float: " << (num > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		if (num == static_cast<int>(num))
			std::cout << "float: " << static_cast<int>(num) << ".0f" << std::endl;
		else
			std::cout << "float: " << num << "f" << std::endl;
	}

	double valueDouble = static_cast<double>(num);
	if (std::isnan(valueDouble))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(valueDouble))
		std::cout << "double: " << (valueDouble > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		if (valueDouble == static_cast<int>(valueDouble))
			std::cout << "double: " << static_cast<int>(valueDouble) << ".0" << std::endl;
		else
			std::cout << "double: " << valueDouble << std::endl;
	}
}

static void convertFromDouble(std::string const &convert)
{
	double	num;
		
	if (convert == "nan")
		num = std::numeric_limits<double>::quiet_NaN();
	else if (convert == "+inf")
		num = std::numeric_limits<double>::infinity();
	else if (convert == "-inf")
		num = -std::numeric_limits<double>::infinity();
	else
		num = std::atof(convert.c_str());
		
	if (std::isnan(num) || std::isinf(num))
		std::cout << "char: impossible" << std::endl;
	else if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		
	if (std::isnan(num) || std::isinf(num))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	float valueFloat = static_cast<float>(num);
	if (std::isnan(valueFloat))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(valueFloat))
		std::cout << "float: " << (valueFloat > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		if (valueFloat == static_cast<int>(valueFloat))
			std::cout << "float: " << static_cast<int>(valueFloat) << ".0f" << std::endl;
		else
			std::cout << "float: " << valueFloat << "f" << std::endl;
	}

	if (std::isnan(num))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(num))
		std::cout << "double: " << (num > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
        if (num == static_cast<int>(num))
			std::cout << "double: " << static_cast<int>(num) << ".0" << std::endl;
		else
			std::cout << "double: " << num << std::endl;
	}
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {(void)copy;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const &convert)
{
	if (isCharLiteral(convert))
		convertFromChar(convert);
	else if (isIntLiteral(convert))
		convertFromInt(convert);
	else if (isFloatLiteral(convert))
		convertFromFloat(convert);
	else if (isDoubleLiteral(convert))
		convertFromDouble(convert);
	else
		std::cout << "Error: Invalid literal format" << std::endl;
}
