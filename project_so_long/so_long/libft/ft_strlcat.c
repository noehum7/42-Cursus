/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:28:49 by nporras-          #+#    #+#             */
/*   Updated: 2024/12/03 13:24:26 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	length_src;
	size_t	length_dest;

	length_src = ft_strlen(src);
	length_dest = ft_strlen(dst);
	if (size == 0)
		return (length_src);
	if (size <= length_dest)
		return (size + length_src);
	i = 0;
	j = length_dest;
	while (src[i] && j < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (length_dest + length_src);
}
