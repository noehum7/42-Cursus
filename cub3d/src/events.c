/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:09:35 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/07 12:24:03 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game)
{
	if (game->player.up)
		move_forward(game);
	if (game->player.down)
		move_backward(game);
	if (game->player.left)
		strafe_left(game);
	if (game->player.right)
		strafe_right(game);
	if (game->player.rot_left)
		rotate_left(game);
	if (game->player.rot_right)
		rotate_right(game);
}

void	update_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->move_flag)
	{
		render_frame(game);
		move_player(game);
	}
}
