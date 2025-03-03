/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:02:48 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/05 15:42:48 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_temp;
	unsigned char		*dest_temp;

	if (!dest && !src)
		return (NULL);
	src_temp = src;
	dest_temp = dest;
	if (dest_temp < src_temp)
		while (n--)
			*dest_temp++ = *src_temp++;
	else
	{
		src_temp += n;
		dest_temp += n;
		while (n--)
			*--dest_temp = *--src_temp;
	}
	return (dest);
}
