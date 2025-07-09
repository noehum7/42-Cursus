/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:49:09 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/24 13:51:07 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_collision(t_game *game, double x, double y)
{
	double	offset;

	offset = 0.1;
	if (game->map.grid[(int)(y - offset)][(int)(x - offset)] == '1')
		return (1);
	if (game->map.grid[(int)(y - offset)][(int)(x + offset)] == '1')
		return (1);
	if (game->map.grid[(int)(y + offset)][(int)(x - offset)] == '1')
		return (1);
	if (game->map.grid[(int)(y + offset)][(int)(x + offset)] == '1')
		return (1);
	return (0);
}

void	move_forward(t_game *game)
{
	t_position	next;

	next.x = game->player.pos.x + game->player.dir_x * MOVE_SPEED;
	next.y = game->player.pos.y + game->player.dir_y * MOVE_SPEED;
	if (!check_collision(game, next.x, game->player.pos.y))
		game->player.pos.x = next.x;
	if (!check_collision(game, game->player.pos.x, next.y))
		game->player.pos.y = next.y;
}

void	move_backward(t_game *game)
{
	t_position	next;

	next.x = game->player.pos.x - game->player.dir_x * MOVE_SPEED;
	next.y = game->player.pos.y - game->player.dir_y * MOVE_SPEED;
	if (!check_collision(game, next.x, game->player.pos.y))
		game->player.pos.x = next.x;
	if (!check_collision(game, game->player.pos.x, next.y))
		game->player.pos.y = next.y;
}

void	strafe_left(t_game *game)
{
	t_position	next;
	double		perp_x;
	double		perp_y;

	perp_x = game->player.dir_y;
	perp_y = -game->player.dir_x;
	next.x = game->player.pos.x + perp_x * MOVE_SPEED;
	next.y = game->player.pos.y + perp_y * MOVE_SPEED;
	if (!check_collision(game, next.x, game->player.pos.y))
		game->player.pos.x = next.x;
	if (!check_collision(game, game->player.pos.x, next.y))
		game->player.pos.y = next.y;
}

void	strafe_right(t_game *game)
{
	t_position	next;
	double		perp_x;
	double		perp_y;

	perp_x = -game->player.dir_y;
	perp_y = game->player.dir_x;
	next.x = game->player.pos.x + perp_x * MOVE_SPEED;
	next.y = game->player.pos.y + perp_y * MOVE_SPEED;
	if (!check_collision(game, next.x, game->player.pos.y))
		game->player.pos.x = next.x;
	if (!check_collision(game, game->player.pos.x, next.y))
		game->player.pos.y = next.y;
}
