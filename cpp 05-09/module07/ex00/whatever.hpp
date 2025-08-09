/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:45:06 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/14 17:45:07 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T	&min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template <typename T>
const T	&max(const T &a, const T &b)
{
	return (a > b ? a : b);
}
