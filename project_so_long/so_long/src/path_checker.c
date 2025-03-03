#include "so_long.h"

static char	**create_temp_map(t_game *game, t_uint *height)
{
	char	**temp;
	t_uint	i;

	i = 0;
	temp = malloc(sizeof(char *) * game->map.height);
	if (!temp)
		return (NULL);
	while (i < game->map.height)
	{
		temp[i] = ft_strdup(game->map.grid[i]);
		if (!temp[i])
		{
			while (i > 0)
				free(temp[--i]);
			free(temp);
			return (NULL);
		}
		i++;
	}
	*height = game->map.height;
	return (temp);
}

static void	fill(t_game *game, char **map, t_uint x, t_uint y)
{
	if (x >= game->map.width || y >= game->map.height)
		return ;
	if (map[y][x] == WALL || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	if (x > 0)
		fill(game, map, x - 1, y);
	if (y > 0)
		fill(game, map, x, y - 1);
	if (x + 1 < game->map.width)
		fill(game, map, x + 1, y);
	if (y + 1 < game->map.height)
		fill(game, map, x, y + 1);
}

static int	check_filled(t_game *game, char **temp)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if ((game->map.grid[i][j] == COLLECTIBLE
				|| game->map.grid[i][j] == EXIT) &&
				temp[i][j] != 'F')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(t_game *game)
{
	char	**temp;
	int		valid;
	t_uint	height;

	temp = create_temp_map(game, &height);
	if (!temp)
		return (0);
	fill(game, temp, game->player.x, game->player.y);
	valid = check_filled(game, temp);
	while (height > 0)
		free(temp[--height]);
	free(temp);
	return (valid);
}
