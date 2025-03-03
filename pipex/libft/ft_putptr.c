/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:19:37 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/13 18:21:54 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthex(unsigned long n)
{
	const char	*base;
	int			count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	n;

	if (!ptr)
		return (ft_putstr("(nil)"));
	n = (unsigned long)ptr;
	count = ft_putstr("0x");
	count += ft_puthex(n);
	return (count);
}
