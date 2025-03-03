#include "so_long.h"

static void	*load_image(t_game *game, char *path, int *w, int *h)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->win.mlx, path, w, h);
	return (img);
}

static int	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	game->assets.wall = load_image(game, WALL_PATH, &width, &height);
	game->assets.floor = load_image(game, FLOOR_PATH, &width, &height);
	game->assets.player = load_image(game, PLAYER_PATH, &width, &height);
	game->assets.collectible = load_image(game, COLLECT_PATH, &width, &height);
	game->assets.exit = load_image(game, EXIT_PATH, &width, &height);
	game->assets.width = width;
	game->assets.height = height;
	if (!game->assets.wall || !game->assets.floor || !game->assets.player
		|| !game->assets.collectible || !game->assets.exit)
		return (0);
	return (1);
}

int	init_window(t_game *game)
{
	game->win.mlx = mlx_init();
	if (!game->win.mlx)
		return (0);
	game->win.width = game->map.width * TILE_SIZE;
	game->win.height = game->map.height * TILE_SIZE;
	game->win.win = mlx_new_window(game->win.mlx,
			game->win.width,
			game->win.height,
			"so_long");
	return (game->win.win != NULL);
}

int	init_game(t_game *game, char *map_path)
{
	if (!read_map(game, map_path))
		return (0);
	if (!validate_map(game))
		return (0);
	if (!init_window(game))
		return (0);
	if (!load_textures(game))
		return (0);
	game->moves = 0;
	game->collected = 0;
	render_map(game);
	return (1);
}
