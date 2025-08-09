/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:10:40 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/16 18:10:41 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility>

bool	parseInput(int ac, char **av, std::vector<int> &v, std::deque<int> &d)
{
	if (ac < 2)
		return (false);

	for (int i = 1; i < ac; ++i)
	{
		std::string			arg(av[i]);
		std::istringstream	iss(arg);
		int					num;

		if (!(iss >> num) || num < 0 || !iss.eof())
			return (false);
		v.push_back(num);
		d.push_back(num);
	}
	return (true);
}

void	printSequence(const std::string &msg, const std::vector<int> &seq)
{
	std::cout << msg;
	for (size_t i = 0; i < seq.size(); ++i)
		std::cout << " " << seq[i];
	std::cout << std::endl;
}

static void	splitPairsVec(const std::vector<int> &input, std::vector<int> &mainChain, std::vector<int> &pending)
{
	std::vector<std::pair<int, int> >	pairs;
	size_t								i = 0;

	for (; i + 1 < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}
	if (i < input.size())
		pending.push_back(input[i]);
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		mainChain.push_back(pairs[j].first);
		pending.push_back(pairs[j].second);
	}
}

static void	fordJohnsonSortVec(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return ;

	std::vector<int>	main;
	std::vector<int>	pending;

	splitPairsVec(vec, main, pending);
	fordJohnsonSortVec(main);
	for (size_t i = 0; i < pending.size(); ++i)
	{
		std::vector<int>::iterator	pos =
			std::lower_bound(main.begin(), main.end(), pending[i]);
		main.insert(pos, pending[i]);
	}
	vec = main;
}

void	sortVector(std::vector<int> &v)
{
	fordJohnsonSortVec(v);
}

static void	splitPairsDeque(const std::deque<int> &input, std::deque<int> &main, std::deque<int> &pending)
{
	std::deque<std::pair<int, int> >	pairs;
	size_t							i = 0;

	for (; i + 1 < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
		else
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
	}
	if (i < input.size())
		pending.push_back(input[i]);
	for (size_t j = 0; j < pairs.size(); ++j)
	{
		main.push_back(pairs[j].first);
		pending.push_back(pairs[j].second);
	}
}

static void	fordJohnsonSortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return ;
	std::deque<int>	mainChain;
	std::deque<int>	pending;

	splitPairsDeque(deq, mainChain, pending);
	fordJohnsonSortDeque(mainChain);
	for (size_t i = 0; i < pending.size(); ++i)
	{
		std::deque<int>::iterator pos =
			std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
		mainChain.insert(pos, pending[i]);
	}
	deq = mainChain;
}

void	sortDeque(std::deque<int> &deq)
{
	fordJohnsonSortDeque(deq);
}
