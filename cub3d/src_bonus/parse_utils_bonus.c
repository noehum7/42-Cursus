/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:00:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:40:17 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*skip_textures_and_find_map(int fd, t_game *game, int parse_textures)
{
	char	*line;
	int		textures_found;

	textures_found = 0;
	line = get_next_line(fd);
	while (line && textures_found < 6)
	{
		if (line[0] != '\n' && is_texture_line(line, game))
		{
			if (parse_textures)
				parse_texture_line(game, line);
			textures_found++;
		}
		free(line);
		line = get_next_line(fd);
	}
	while (line && (line[0] == '\n' || !is_map_line(line)))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

t_uint	count_map_lines(char *file, t_game *game)
{
	int		fd;
	char	*line;
	t_uint	map_lines;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	line = skip_textures_and_find_map(fd, NULL, 0);
	if (!line)
	{
		close(fd);
		ft_error_game(game, "Invalid map");
		return (0);
	}
	map_lines = 0;
	while (line && is_map_line(line))
	{
		if (line[0] != '\n')
			map_lines++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (close(fd), map_lines);
}

int	read_map_lines(t_game *game, int fd, char *first_line)
{
	char	*line;
	t_uint	i;

	i = 0;
	line = first_line;
	while (line && is_map_line(line))
	{
		if (line[0] == '\n' || ft_strlen(line) == 0)
		{
			free(line);
			close(fd);
			while (i > 0)
				free(game->map.grid[--i]);
			ft_error_game(game, "Extra empty line");
		}
		game->map.grid[i++] = strdup_trimmed_line(line, game);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	game->map.grid[i] = NULL;
	game->map.height = i;
	return (1);
}

void	calculate_map_dimensions(t_game *game)
{
	t_uint	i;
	t_uint	len;

	game->map.width = 0;
	i = 0;
	while (i < game->map.height)
	{
		len = ft_strlen(game->map.grid[i]);
		if (len > game->map.width)
			game->map.width = len;
		i++;
	}
}
