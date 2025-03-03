#include "so_long.h"

static void	*get_texture_for_tile(t_game *game, char tile)
{
	if (tile == WALL)
		return (game->assets.wall);
	else if (tile == PLAYER)
		return (game->assets.player);
	else if (tile == COLLECTIBLE)
		return (game->assets.collectible);
	else if (tile == EXIT)
		return (game->assets.exit);
	else
		return (game->assets.floor);
}

static void	render_tile(t_game *game, t_uint x, t_uint y)
{
	void	*img;
	char	tile;

	tile = game->map.grid[y][x];
	img = get_texture_for_tile(game, tile);
	mlx_put_image_to_window(game->win.mlx,
		game->win.win,
		img,
		x * TILE_SIZE,
		y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			render_tile(game, j, i);
			j++;
		}
		i++;
	}
}
