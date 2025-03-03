/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:51:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/01/16 17:48:16 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_safe_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*ft_read_buffer(int fd, char *buffer_static)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (ft_safe_free(&buffer_static));
	temp[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			temp[bytes_read] = '\0';
			buffer_static = ft_strjoin(buffer_static, temp);
		}
	}
	free(temp);
	if (bytes_read == -1)
		return (ft_safe_free(&buffer_static));
	return (buffer_static);
}

static char	*ft_save_remaining(char *buffer_static)
{
	char	*new_storage;
	char	*newline_pos;
	int		length;

	newline_pos = ft_strchr(buffer_static, '\n');
	if (!newline_pos)
	{
		new_storage = NULL;
		return (ft_safe_free(&buffer_static));
	}
	else
		length = (newline_pos - buffer_static) + 1;
	if (!buffer_static[length])
		return (ft_safe_free(&buffer_static));
	new_storage = ft_substr(buffer_static, length,
			ft_strlen(buffer_static) - length);
	ft_safe_free(&buffer_static);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

static char	*ft_extract_current_line(char *buffer_static)
{
	char	*line;
	char	*pos;
	int		length;

	pos = ft_strchr(buffer_static, '\n');
	length = (pos - buffer_static) + 1;
	line = ft_substr(buffer_static, 0, length);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer_static[1024];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((buffer_static[fd] && !ft_strchr(buffer_static[fd], '\n'))
		|| !buffer_static[fd])
		buffer_static[fd] = ft_read_buffer(fd, buffer_static[fd]);
	if (!buffer_static[fd])
		return (NULL);
	line = ft_extract_current_line(buffer_static[fd]);
	if (!line)
		return (ft_safe_free(&buffer_static[fd]));
	buffer_static[fd] = ft_save_remaining(buffer_static[fd]);
	return (line);
}
