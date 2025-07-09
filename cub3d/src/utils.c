/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 13:27:42 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	destroy_textures(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->textures.north)
		mlx_delete_texture(game->textures.north);
	if (game->textures.south)
		mlx_delete_texture(game->textures.south);
	if (game->textures.west)
		mlx_delete_texture(game->textures.west);
	if (game->textures.east)
		mlx_delete_texture(game->textures.east);
}

static void	free_texture_paths(t_game *game)
{
	if (game->map.north_path)
		free(game->map.north_path);
	if (game->map.south_path)
		free(game->map.south_path);
	if (game->map.west_path)
		free(game->map.west_path);
	if (game->map.east_path)
		free(game->map.east_path);
}

static void	free_map(t_game *game)
{
	t_uint	i;

	i = 0;
	if (!game->map.grid)
		return ;
	while (i < game->map.height)
	{
		if (game->map.grid[i])
			free(game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
	game->map.grid = NULL;
}

void	close_game(t_game *game)
{
	free_map(game);
	free_texture_paths(game);
	destroy_textures(game);
	if (game->image)
		mlx_delete_image(game->mlx, game->image);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(0);
}

void	ft_error_game(t_game *game, char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	get_next_line(-1);
	if (game)
	{
		free_map(game);
		free_texture_paths(game);
		destroy_textures(game);
		if (game->image)
			mlx_delete_image(game->mlx, game->image);
		if (game->mlx)
			mlx_terminate(game->mlx);
	}
	exit(1);
}
