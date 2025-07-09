/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 13:25:08 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	trim_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (len > 1 && line[len - 2] == '\r')
		line[len - 2] = '\0';
}

int	is_map_line(char *line)
{
	int	i;

	if (!line || !line[0])
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	parse_texture_line(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->map.north_path = ft_strtrim(line + 3, " \n\r");
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->map.south_path = ft_strtrim(line + 3, " \n\r");
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->map.west_path = ft_strtrim(line + 3, " \n\r");
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->map.east_path = ft_strtrim(line + 3, " \n\r");
	else if (ft_strncmp(line, "F ", 2) == 0)
		parse_rgb_color(line + 2, game->map.floor_rgb, game, line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		parse_rgb_color(line + 2, game->map.ceiling_rgb, game, line);
}

int	is_texture_line(char *line, t_game *game)
{
	char	*space;

	space = ft_strchr(line, ' ');
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (1);
	if (space && (ft_strchr(line, '.') || ft_strchr(line, ',')))
	{
		free(line);
		ft_error_game(game,
			"Invalid texture identifier - expected: NO, SO, WE, EA, F, C");
	}
	return (0);
}

char	*strdup_trimmed_line(char *line, t_game *game)
{
	char	*dup;

	trim_newline(line);
	dup = ft_strdup(line);
	if (!dup)
		ft_error_game(game, "Memory allocation failed");
	return (dup);
}
