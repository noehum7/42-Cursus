/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:01:20 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/13 12:30:37 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_temp;
	unsigned char		*dest_temp;

	if (!src && !dest)
		return (NULL);
	src_temp = src;
	dest_temp = dest;
	while (n > 0)
	{
		*dest_temp = *src_temp;
		n--;
		dest_temp++;
		src_temp++;
	}
	return (dest);
}
