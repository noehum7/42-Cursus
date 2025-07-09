/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:49:09 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:40:09 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate_left(t_game *game)
{
	game->player.angle -= ROT_SPEED;
	if (game->player.angle < 0)
		game->player.angle += 360;
	game->player.dir_x = cos(game->player.angle * M_PI / 180);
	game->player.dir_y = sin(game->player.angle * M_PI / 180);
}

void	rotate_right(t_game *game)
{
	game->player.angle += ROT_SPEED;
	if (game->player.angle >= 360)
		game->player.angle -= 360;
	game->player.dir_x = cos(game->player.angle * M_PI / 180);
	game->player.dir_y = sin(game->player.angle * M_PI / 180);
}
