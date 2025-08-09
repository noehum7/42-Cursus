/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:10:43 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/16 18:10:44 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <vector>
# include <deque>
# include <string>

void	sortVector(std::vector<int> &v);
void	sortDeque(std::deque<int> &deq);
bool	parseInput(int ac, char** av, std::vector<int> &v, std::deque<int> &deq);
void	printSequence(const std::string &msg, const std::vector<int> &seq);
