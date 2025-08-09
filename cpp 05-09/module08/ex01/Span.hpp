/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:17:23 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/15 15:25:15 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <vector>

class Span
{
	private:
		unsigned int	_N;
		std::vector<int> v;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &copy);

		void	addNumber(int n);
		int	shortestSpan();
		int	longestSpan();
		void	addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);

		class FullStoreException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
