#include "so_long.h"

void	ft_error(char *message)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

static void	destroy_textures(t_game *game)
{
	if (!game->win.mlx)
		return ;
	if (game->assets.wall)
		mlx_destroy_image(game->win.mlx, game->assets.wall);
	if (game->assets.floor)
		mlx_destroy_image(game->win.mlx, game->assets.floor);
	if (game->assets.player)
		mlx_destroy_image(game->win.mlx, game->assets.player);
	if (game->assets.collectible)
		mlx_destroy_image(game->win.mlx, game->assets.collectible);
	if (game->assets.exit)
		mlx_destroy_image(game->win.mlx, game->assets.exit);
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
	destroy_textures(game);
	if (game->win.win)
		mlx_destroy_window(game->win.mlx, game->win.win);
	if (game->win.mlx)
	{
		mlx_destroy_display(game->win.mlx);
		free(game->win.mlx);
	}
	exit(0);
}
