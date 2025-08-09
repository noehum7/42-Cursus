/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:45:10 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 17:45:11 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	increment(int &x)
{
	x++;
}

int	main()
{
	int		numbers[] = {1, 2, 3, 4, 5};
	size_t	size = 5;

	std::cout << "🔢 Original: ";
	iter(numbers, size, print<int>);
	std::cout << std::endl;

	iter(numbers, size, increment);
	std::cout << "⬆️  After increment: ";
	iter(numbers, size, print<int>);
	std::cout << std::endl;

	std::string words[] = {"hello", "world", "test"};
	size_t wordSize = 3;
		
	std::cout << "📝 Words: ";
	iter(words, wordSize, print<std::string>);
	std::cout << std::endl;
		
	const char	letters[] = {'a', 'b', 'c', 'd'};
	size_t		charSize = 4;

	std::cout << "🔤 Letters: ";
	iter(letters, charSize, print<char>);
	std::cout << std::endl;
	return (0);
}
