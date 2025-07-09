/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:51:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:31:33 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_gnl(char **str)
{
	free(*str);
	*str = 0;
	return (NULL);
}

char	*ft_calloc_gnl(int size)
{
	char	*mem;
	int		i;

	mem = (char *)malloc(size * sizeof(char));
	i = -1;
	if (!mem)
		return (NULL);
	while (++i < size)
		mem[i] = '\0';
	return (mem);
}

static char	*ft_find_line(int fd, char *stcs)
{
	int		rd_bt;
	char	*buffer;

	rd_bt = 1;
	buffer = ft_calloc_gnl((BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_gnl(&stcs));
	while (!ft_strchr_gnl(stcs, '\n') && rd_bt != 0)
	{
		rd_bt = read(fd, buffer, BUFFER_SIZE);
		if (rd_bt == -1)
		{
			ft_free_gnl(&buffer);
			return (ft_free_gnl(&stcs));
		}
		buffer[rd_bt] = '\0';
		stcs = ft_strjoin_gnl(stcs, buffer);
		if (!stcs)
			return (ft_free_gnl(&buffer));
	}
	ft_free_gnl(&buffer);
	return (stcs);
}

char	*get_next_line(int fd)
{
	static char	*stcs;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_gnl(&stcs));
	stcs = ft_find_line(fd, stcs);
	if (!stcs)
		return (NULL);
	line = ft_get_line(stcs, &i);
	if (!line || !*line)
		return (ft_free_gnl(&stcs));
	stcs = ft_new_stcs(stcs, i);
	return (line);
}
