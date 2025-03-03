#include "so_long.h"

int	handle_close(t_game *game)
{
	close_game(game);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	t_position	next;
	int			moved;

	next = game->player;
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		next.y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		next.y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		next.x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		next.x++;
	else
		return (0);
	moved = move_player(game, next);
	return (moved);
}
