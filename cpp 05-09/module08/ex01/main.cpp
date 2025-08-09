/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:16:55 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/15 16:04:22 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}

// int	main(void)
// {
// 	std::cout << "🟢 Basic subject test:" << std::endl;
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << "🔹 shortestSpan: " << sp.shortestSpan() << std::endl;
// 	std::cout << "🔹 longestSpan: " << sp.longestSpan() << std::endl;

// 	std::cout << "\n🟠 Exception test: adding more than allowed:" << std::endl;
// 	try
// 	{
// 		sp.addNumber(42);
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "⚠️  Exception caught: " << e.what() << std::endl;
// 	}

// 	std::cout << "\n🟣 Exception test: calculating spans with too few numbers:" << std::endl;
// 	try
// 	{
// 		Span sp2(1);
// 		sp2.addNumber(10);
// 		std::cout << sp2.shortestSpan() << std::endl;
// 	}
// 	catch (const std::exception &e)
// 	{
// 		std::cout << "⚠️  Exception caught: " << e.what() << std::endl;
// 	}

// 	std::cout << "\n🔵 Range add test:" << std::endl;
// 	Span sp3(10);
// 	std::vector<int> vec;
// 	vec.push_back(1);
// 	vec.push_back(2);
// 	vec.push_back(3);
// 	vec.push_back(4);
// 	vec.push_back(5);
// 	sp3.addNumber(vec.begin(), vec.end());
// 	std::cout << "🔹 shortestSpan: " << sp3.shortestSpan() << std::endl;
// 	std::cout << "🔹 longestSpan: " << sp3.longestSpan() << std::endl;

// 	std::cout << "\n🟤 Test with many numbers (10,000):" << std::endl;
// 	Span sp4(10000);
// 	for (int i = 0; i < 10000; ++i)
// 		sp4.addNumber(i * 2);
// 	std::cout << "🔹 shortestSpan: " << sp4.shortestSpan() << std::endl;
// 	std::cout << "🔹 longestSpan: " << sp4.longestSpan() << std::endl;

// 	return (0);
// }