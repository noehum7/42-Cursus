#include "so_long.h"

static int	is_valid_move(t_game *game, t_position next)
{
	if (next.x >= game->map.width || next.y >= game->map.height)
		return (0);
	if (game->map.grid[next.y][next.x] == WALL)
		return (0);
	if (game->map.grid[next.y][next.x] == EXIT &&
		game->collected != game->map.collectibles)
		return (0);
	return (1);
}

static void	collect_item(t_game *game, t_position pos)
{
	if (game->map.grid[pos.y][pos.x] == COLLECTIBLE)
	{
		game->map.grid[pos.y][pos.x] = EMPTY;
		game->collected++;
	}
}

int	move_player(t_game *game, t_position next)
{
	char	next_tile;

	if (!is_valid_move(game, next))
		return (0);
	next_tile = game->map.grid[next.y][next.x];
	collect_item(game, next);
	game->map.grid[game->player.y][game->player.x] = EMPTY;
	game->player = next;
	game->map.grid[next.y][next.x] = PLAYER;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
	if (next_tile == EXIT && game->collected == game->map.collectibles)
	{
		ft_printf("\n¡Game completed in %d moves!\n", game->moves);
		close_game(game);
	}
	return (1);
}
