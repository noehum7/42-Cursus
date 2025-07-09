/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:00:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:40:15 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_player_direction(t_game *game, char direction)
{
	if (direction == 'N')
		game->player.angle = 270;
	else if (direction == 'S')
		game->player.angle = 90;
	else if (direction == 'E')
		game->player.angle = 0;
	else if (direction == 'W')
		game->player.angle = 180;
	game->player.dir_x = cos(game->player.angle * M_PI / 180);
	game->player.dir_y = sin(game->player.angle * M_PI / 180);
}

static int	is_player_character(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	init_player(t_game *game)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width && game->map.grid[y][x])
		{
			if (is_player_character(game->map.grid[y][x]))
			{
				game->player.pos.x = x + 0.5;
				game->player.pos.y = y + 0.5;
				set_player_direction(game, game->map.grid[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}
