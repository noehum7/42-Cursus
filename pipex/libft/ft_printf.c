/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:19:26 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/13 18:24:13 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_type(char format, va_list args)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), format));
	return (0);
}

static int	ft_process_format(char const *format, va_list args)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_type(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, format);
	length = ft_process_format(format, args);
	va_end(args);
	return (length);
}
