/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:10:35 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/16 18:10:36 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

void	rpn(const std::string &expr)
{
	std::stack<int>		stack;
	std::istringstream	input(expr);
	std::string			token;
	int					count = 0;

	while (input >> token)
	{
		if (token.size() == 1 && std::string("+-/*").find(token) != std::string::npos)
		{
			count++;
			if (stack.size() < 2)
				throw std::runtime_error("Error");
			int	b = stack.top();
			stack.pop();
			int	a = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(a + b);
			else if (token == "-")
				stack.push(a - b);
			else if (token == "*")
				stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
					throw std::runtime_error("Error");
				stack.push(a / b);
			}
		}
		else if (token.size() == 1 && isdigit(token[0]))
			stack.push(token[0] - '0');
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() != 1 || count == 0)
		throw std::runtime_error("Error");
	std::cout << stack.top() << std::endl;
}
