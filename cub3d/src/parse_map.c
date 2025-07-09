/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 12:29:40 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	replace_map_grid(t_game *game, char **grid_new)
{
	int	i;

	i = 0;
	while (game->map.grid[i])
	{
		free((game->map.grid[i]));
		i++;
	}
	free((game->map.grid));
	game->map.grid = grid_new;
}

static int	fill_map_grid(t_game *game, t_uint i, t_uint j, char **grid_new)
{
	grid_new = (char **)malloc(game->map.height * sizeof(char *));
	if (!grid_new)
		return (1);
	while (game->map.height > i)
	{
		grid_new[i] = (char *)malloc((game->map.width + 1) * sizeof(char));
		if (!grid_new[i])
			return (1);
		j = 0;
		while (game->map.grid[i][j])
		{
			if (game->map.grid[i][j] == ' ')
				grid_new[i][j] = '0';
			else
				grid_new[i][j] = game->map.grid[i][j];
			j++;
		}
		while (j < game->map.width)
			grid_new[i][j++] = '0';
		grid_new[i][j] = 0;
		i++;
	}
	replace_map_grid(game, grid_new);
	return (0);
}

static int	setup_map_grid(t_game *game, char *file, int *fd, char **line)
{
	t_uint	map_lines;

	map_lines = count_map_lines(file, game);
	if (map_lines == 0)
		return (0);
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		ft_error_game(game, "Cannot open map file");
		return (0);
	}
	*line = skip_textures_and_find_map(*fd, game, 1);
	if (!*line)
	{
		close(*fd);
		return (0);
	}
	game->map.grid = malloc(sizeof(char *) * (map_lines + 1));
	if (!game->map.grid)
	{
		free(*line);
		close(*fd);
		return (0);
	}
	return (1);
}

static int	read_map_grid(t_game *game, char *file)
{
	int		fd;
	char	*line;

	if (!setup_map_grid(game, file, &fd, &line))
		return (0);
	read_map_lines(game, fd, line);
	calculate_map_dimensions(game);
	fill_map_grid(game, 0, 0, NULL);
	close(fd);
	return (1);
}

int	read_map(t_game *game, char *file)
{
	if (!read_map_grid(game, file))
		return (0);
	if (!game->map.north_path || !game->map.south_path
		|| !game->map.west_path || !game->map.east_path)
	{
		ft_error_game(game, "Missing texture paths");
		return (0);
	}
	return (1);
}
