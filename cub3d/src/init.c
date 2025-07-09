/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/07 12:14:18 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_texture_t	*load_texture(char *path, t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error_game(game, "Failed to load texture");
	return (texture);
}

static int	load_textures(t_game *game)
{
	game->textures.north = load_texture(game->map.north_path, game);
	game->textures.south = load_texture(game->map.south_path, game);
	game->textures.west = load_texture(game->map.west_path, game);
	game->textures.east = load_texture(game->map.east_path, game);
	game->textures.floor_color = (game->map.floor_rgb[0] << 24)
		| (game->map.floor_rgb[1] << 16)
		| (game->map.floor_rgb[2] << 8) | 0xFF;
	game->textures.ceiling_color = (game->map.ceiling_rgb[0] << 24)
		| (game->map.ceiling_rgb[1] << 16)
		| (game->map.ceiling_rgb[2] << 8) | 0xFF;
	if (!game->textures.north || !game->textures.south || !game->textures.west
		|| !game->textures.east)
		return (0);
	return (1);
}

static int	init_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		return (0);
	game->image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->image)
		return (0);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) < 0)
		return (0);
	return (1);
}

int	init_game(t_game *game, char *map_path)
{
	if (MOVE_SPEED > 1.0)
	{
		ft_error_game(game, "Error: MOVE_SPEED too high, maximum allowed is 1.0");
		return (0);
	}
	if (!read_map(game, map_path))
		return (0);
	if (!validate_map(game))
		return (0);
	if (!init_window(game))
		return (0);
	if (!load_textures(game))
		return (0);
	init_player(game);
	game->move_flag = 0;
	game->player.up = false;
	game->player.down = false;
	game->player.left = false;
	game->player.right = false;
	game->player.rot_left = false;
	game->player.rot_right = false;
	render_frame(game);
	return (1);
}
