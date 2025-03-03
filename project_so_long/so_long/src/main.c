#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_error("You must use: ./so_long <map.ber>");
	else if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		ft_error("Map must have .ber extension");
	ft_memset(&game, 0, sizeof(t_game));
	if (!init_game(&game, av[1]))
	{
		close_game(&game);
		return (1);
	}
	mlx_hook(game.win.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win.win, 17, 0, handle_close, &game);
	mlx_loop(game.win.mlx);
	return (0);
}
