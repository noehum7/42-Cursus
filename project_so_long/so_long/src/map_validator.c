#include "so_long.h"

static int	check_format(t_game *game)
{
	t_uint	i;
	size_t	len;

	i = 0;
	if (!game->map.grid || !game->map.grid[0])
		return (0);
	len = ft_strlen(game->map.grid[0]);
	while (i < game->map.height)
	{
		if (ft_strlen(game->map.grid[i]) != len)
			return (0);
		i++;
	}
	game->map.width = len;
	return (1);
}

static int	check_walls(t_game *game)
{
	t_uint	i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.grid[0][i] != '1' ||
			game->map.grid[game->map.height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i][0] != '1' ||
			game->map.grid[i][game->map.width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	count_element(t_game *game, char element, t_uint i, t_uint j)
{
	if (element == COLLECTIBLE)
		game->map.collectibles++;
	else if (element == EXIT)
		game->map.exits++;
	else if (element == PLAYER)
	{
		game->map.players++;
		game->player = (t_position){j, i};
	}
}

static int	check_elements(t_game *game)
{
	t_uint	i;
	t_uint	j;

	game->map.collectibles = 0;
	game->map.exits = 0;
	game->map.players = 0;
	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{
			if (!ft_strchr(MAP_CHARS, game->map.grid[i][j]))
				ft_error("Map contains invalid characters");
			count_element(game, game->map.grid[i][j], i, j);
		}
	}
	if (game->map.players != 1 || game->map.exits != 1
		|| game->map.collectibles < 1)
		ft_error("Map has invalid configuration");
	return (1);
}

int	validate_map(t_game *game)
{
	if (!game->map.height)
		ft_error("Map is empty");
	if (!check_format(game))
		ft_error("Map is not rectangular");
	check_elements(game);
	if (!check_walls(game))
		ft_error("Map is not surrounded by walls");
	if (!check_path(game))
		ft_error("No valid path in map");
	return (1);
}
