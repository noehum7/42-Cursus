#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define TILE_SIZE		32
# define MAP_CHARS		"01CEP"
# define PLAYER_PATH	"textures/player.xpm"
# define WALL_PATH		"textures/wall.xpm"
# define FLOOR_PATH		"textures/floor.xpm"
# define EXIT_PATH		"textures/exit.xpm"
# define COLLECT_PATH	"textures/collectible.xpm"

typedef unsigned int	t_uint;

typedef enum e_elements
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}		t_elements;

typedef enum e_keys
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_UP = 65362,
	KEY_LEFT = 65361,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363
}		t_keys;

typedef struct s_position
{
	t_uint	x;
	t_uint	y;
}		t_position;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}		t_window;

typedef struct s_assets
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int		width;
	int		height;
}		t_assets;

typedef struct s_map_data
{
	char	**grid;
	t_uint	width;
	t_uint	height;
	t_uint	collectibles;
	t_uint	exits;
	t_uint	players;
}		t_map_data;

typedef struct s_game
{
	t_window	win;
	t_assets	assets;
	t_map_data	map;
	t_position	player;
	t_uint		moves;
	t_uint		collected;
}		t_game;

int		init_game(t_game *game, char *map_path);
int		init_window(t_game *game);
int		read_map(t_game *game, char *file);
int		validate_map(t_game *game);
int		check_path(t_game *game);
int		move_player(t_game *game, t_position next);
void	render_map(t_game *game);
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
void	close_game(t_game *game);
void	ft_error(char *message);

#endif
