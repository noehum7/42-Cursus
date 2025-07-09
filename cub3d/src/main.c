/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:13:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/07 12:16:22 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error_game(NULL, "Usage: ./cub3D <map.cub>");
	else if (ft_strlen(av[1]) < 4 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4,
			".cub", 4) != 0)
		ft_error_game(NULL, "Map must have .cub extension");
	else if (access(av[1], F_OK) != 0)
		ft_error_game(NULL, "Map file not found");
	ft_memset(&game, 0, sizeof(t_game));
	if (!init_game(&game, av[1]))
	{
		close_game(&game);
		return (1);
	}
	mlx_key_hook(game.mlx, handle_keys, &game);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_close_hook(game.mlx, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
