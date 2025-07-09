/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 12:38:33 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_closed(t_game *game)
{
	char	**temp;
	int		result;

	temp = create_temp_map(game);
	if (!temp)
		return (0);
	flood_fill(temp, (int)game->player.pos.x, (int)game->player.pos.y, game);
	result = check_flood_bounds(temp, game);
	free_temp_map(temp, game->map.height);
	return (result);
}

static int	check_elements(t_game *game)
{
	t_uint	i;
	t_uint	j;

	game->map.players = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < ft_strlen(game->map.grid[i]))
		{
			if (!ft_strchr(MAP_CHARS, game->map.grid[i][j]))
				ft_error_game(game, "Map contains invalid characters");
			handle_player_element(game, game->map.grid[i][j], i, j);
			j++;
		}
		i++;
	}
	if (game->map.players != 1)
		ft_error_game(game,
			"Map must have exactly one player position (N, S, E, or W)");
	return (1);
}

static int	check_textures_exist(t_game *game)
{
	int	fd;

	fd = open(game->map.north_path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(game->map.south_path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(game->map.west_path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	fd = open(game->map.east_path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	validate_map(t_game *game)
{
	check_elements(game);
	if (!check_map_closed(game))
		ft_error_game(game, "Map is not surrounded by walls");
	if (!check_textures_exist(game))
		ft_error_game(game, "One or more texture files not found");
	return (1);
}
