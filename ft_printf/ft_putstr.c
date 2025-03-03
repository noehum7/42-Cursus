/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:19:42 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/13 18:22:05 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char	*str)
{
	int	length;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	length = 0;
	while (str[length])
	{
		ft_putchar(str[length]);
		length++;
	}
	return (length);
}
