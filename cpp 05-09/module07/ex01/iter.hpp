/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:45:08 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 17:45:09 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

template <typename T>
void	print(const T &content)
{
	std::cout << content << " ";
}

template <typename T, typename F>
void	iter(T *array, size_t length, F f)
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}
