/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:15:25 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/13 12:15:31 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_length(int nb)
{
	int	length;

	length = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		length += 1;
	while (nb)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*nb;
	unsigned int	num;
	int				length;

	length = ft_num_length(n);
	nb = malloc(sizeof(char) * (length + 1));
	if (!nb)
		return (NULL);
	nb[length] = '\0';
	if (n < 0)
	{
		nb[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		nb[0] = '0';
	while (num)
	{
		length--;
		nb[length] = (num % 10) + '0';
		num /= 10;
	}
	return (nb);
}
