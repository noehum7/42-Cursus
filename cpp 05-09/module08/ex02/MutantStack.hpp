/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:17:48 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/15 17:42:50 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>()
		{
			std::cout << "MutantStack default constructor called" << std::endl;
		}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy)
		{
			std::cout << "MutantStack copy constructor called" << std::endl;
		}
		~MutantStack()
		{
			std::cout << "MutantStack destructor called" << std::endl;
		}
		MutantStack &operator=(const MutantStack &copy) 
		{
			std::cout << "MutantStack copy assignment operator called" << std::endl;
			std::stack<T>::operator=(copy);
			return (*this);
		}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return (std::stack<T>::c.begin());}
		iterator end(){return (std::stack<T>::c.end());}
};
