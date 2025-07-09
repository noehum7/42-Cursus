/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:26:26 by analba-s          #+#    #+#             */
/*   Updated: 2025/07/07 12:33:07 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	close_game(game);
}

void	handle_keys(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
		handle_keypress(keydata, game);
	if (keydata.action == MLX_RELEASE)
		handle_keyrelease(keydata, game);
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		handle_close(param);
	else if (keydata.key == MLX_KEY_W)
		game->player.up = true;
	else if (keydata.key == MLX_KEY_S)
		game->player.down = true;
	else if (keydata.key == MLX_KEY_A)
		game->player.left = true;
	else if (keydata.key == MLX_KEY_D)
		game->player.right = true;
	else if (keydata.key == MLX_KEY_LEFT)
		game->player.rot_left = true;
	else if (keydata.key == MLX_KEY_RIGHT)
		game->player.rot_right = true;
	else
		return ;
	game->move_flag = 1;
}

void	handle_keyrelease(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_W)
		game->player.up = false;
	else if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_S)
		game->player.down = false;
	else if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_A)
		game->player.left = false;
	else if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_D)
		game->player.right = false;
	else if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_LEFT)
		game->player.rot_left = false;
	else if (keydata.action == MLX_RELEASE && keydata.key == MLX_KEY_RIGHT)
		game->player.rot_right = false;
	else
		return ;
	game->move_flag = 1;
}
