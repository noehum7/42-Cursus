/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:17:25 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/15 16:02:44 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0), v(std::vector<int>())
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _N(n), v(std::vector<int>())
{
	std::cout << "Span constructor with parameter called" << std::endl;
}

Span::Span(const Span &copy) : _N(copy._N), v(copy.v)
{
	std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span destructor called " << std::endl;
}

Span &Span::operator=(const Span &copy)
{
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->_N = copy._N;
		this->v = copy.v;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->v.size() + 1 > this->_N)
		throw FullStoreException();
	this->v.push_back(n); 
}

void	Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	if (this->v.size() + std::distance(first, last) > this->_N)
		throw FullStoreException();
	this->v.insert(this->v.end(), first, last);
}

int	Span::shortestSpan()
{
	if (this->v.size() < 2)
		throw NoSpanException();
	std::vector<int> temp = this->v;
	std::sort(temp.begin(), temp.end());
	
	int min = temp[1] - temp[0];
	for (size_t i = 1; i < temp.size() - 1; i++)
	{
		int diff = temp[i + 1] - temp[i];
		if (diff < min)
			min = diff;
	}
	return (min);
}

int	Span::longestSpan()
{
	if (this->v.size() < 2)
		throw NoSpanException();
	std::vector<int>::iterator min = std::min_element(this->v.begin(), this->v.end());
	std::vector<int>::iterator max = std::max_element(this->v.begin(), this->v.end());
	return (*max - *min);
}

const char *Span::FullStoreException::what() const throw()
{
	return ("Error: Full vector.");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Error: Couldn't calculate span, not enough numbers.");
}
