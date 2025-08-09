/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:45:18 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 17:45:19 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*_elements;
		unsigned int	_size;

	public:
		Array(): _size(0)
		{
			std::cout << "Array default constructor called" << std::endl;
			this->_elements = new T[this->_size];
		}
		Array(unsigned int n) : _size(n)
		{
			std::cout << "Array constructor with parameter called" << std::endl;
			this->_elements = new T[this->_size];
		}
		Array(Array const &copy) : _elements(NULL), _size(copy._size)
		{
			std::cout << "Array copy constructor called" << std::endl;
			if (_size > 0)
			{
				_elements = new T[this->_size];
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = copy._elements[i];
			}
		}
		~Array()
		{
			std::cout << "Array destructor called" << std::endl;
			if (this->_elements)
				delete [] this->_elements;
		}

		Array	&operator=(const Array &copy)
		{
			std::cout << "Array copy assignment operator called" << std::endl;
			if (this != &copy)
			{
				delete[] _elements;
				_size = copy._size;
				_elements = NULL;

				if (_size > 0)
				{
					_elements = new T[this->_size];
					for (unsigned int i = 0; i < _size; i++)
						_elements[i] = copy._elements[i];
				}
			}
			return (*this);
		}

		T&	operator[](unsigned int index)
		{
			if (index >= _size || this->_elements == NULL)
				throw Array<T>::OutOfLimits();
			return (_elements[index]);
		}

		unsigned int	size() const {return (_size);}

		class OutOfLimits : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
char const	*Array<T>::OutOfLimits::what() const throw()
{
	return ("Index out of limits");
}
