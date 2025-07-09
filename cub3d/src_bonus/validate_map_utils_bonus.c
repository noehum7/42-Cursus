/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:39:56 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	handle_player_element(t_game *game, char element, t_uint i, t_uint j)
{
	if (element == NORTH || element == SOUTH
		|| element == EAST || element == WEST)
	{
		game->map.players++;
		game->player.pos.x = j + 0.5;
		game->player.pos.y = i + 0.5;
		if (element == NORTH)
			game->player.angle = 270;
		else if (element == SOUTH)
			game->player.angle = 90;
		else if (element == EAST)
			game->player.angle = 0;
		else if (element == WEST)
			game->player.angle = 180;
		game->player.dir_x = cos(game->player.angle * M_PI / 180);
		game->player.dir_y = sin(game->player.angle * M_PI / 180);
	}
}

char	**create_temp_map(t_game *game)
{
	char	**temp;
	t_uint	i;

	temp = malloc(sizeof(char *) * game->map.height);
	if (!temp)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		temp[i] = ft_strdup(game->map.grid[i]);
		if (!temp[i])
		{
			while (i > 0)
				free(temp[--i]);
			free(temp);
			return (NULL);
		}
		i++;
	}
	return (temp);
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (y < 0 || y >= (int)game->map.height || x < 0)
		return ;
	if (x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if ((y == 0 || y == (int)game->map.height - 1
			|| x == 0 || x == (int)ft_strlen(map[y]) - 1)
		&& map[y][x] == ' ')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x, y - 1, game);
	flood_fill(map, x, y + 1, game);
}

int	check_flood_bounds(char **temp, t_game *game)
{
	t_uint	i;
	int		j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < (int)ft_strlen(temp[i]))
		{
			if (temp[i][j] == 'F' &&
				(i == 0 || i == game->map.height - 1 ||
					j == 0 || j == (int)ft_strlen(temp[i]) - 1))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_temp_map(char **temp, t_uint height)
{
	t_uint	i;

	if (!temp)
		return ;
	i = 0;
	while (i < height)
	{
		if (temp[i])
			free(temp[i]);
		i++;
	}
	free(temp);
}
