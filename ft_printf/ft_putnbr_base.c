/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:19:45 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/13 18:22:10 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int n, char format)
{
	const char	*base_min = "0123456789abcdef";
	const char	*base_mayus = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_base(n / 16, format);
	if (format == 'x')
		count += ft_putchar(base_min[n % 16]);
	else if (format == 'X')
		count += ft_putchar(base_mayus[n % 16]);
	return (count);
}
