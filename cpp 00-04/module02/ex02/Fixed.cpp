/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:36:07 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/18 13:36:07 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = copy.getRawBits();
}

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = num << _bits;
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << _bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &copy) const
{
	return (this->_value > copy.getRawBits());
}

bool Fixed::operator<(const Fixed &copy) const
{
	return (this->_value < copy.getRawBits());
}

bool Fixed::operator>=(const Fixed &copy) const
{
	return (this->_value >= copy.getRawBits());
}

bool Fixed::operator<=(const Fixed &copy) const
{
	return (this->_value <= copy.getRawBits());
}

bool Fixed::operator==(const Fixed &copy) const
{
	return (this->_value == copy.getRawBits());
}

bool Fixed::operator!=(const Fixed &copy) const
{
	return (this->_value != copy.getRawBits());
}

Fixed Fixed::operator+(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits(this->_value + copy.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	Fixed result;
	result.setRawBits(this->_value - copy.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &copy) const
{
	return Fixed(this->toFloat() * copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	return Fixed(this->toFloat() / copy.toFloat());
}

Fixed Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return (temp);
}

Fixed Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _bits));
}

int		Fixed::toInt(void) const
{
	return (this->_value >> _bits);
}

std::ostream	&operator<<(std::ostream &os, const Fixed &copy)
{
	os << copy.toFloat();
	return (os);
}
