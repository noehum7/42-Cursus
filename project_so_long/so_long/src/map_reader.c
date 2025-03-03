#include "so_long.h"

static void	trim_newline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

static char	*safe_strdup(char *line)
{
	char	*dup;

	trim_newline(line);
	dup = ft_strdup(line);
	if (!dup)
		ft_error("Memory allocation failed");
	return (dup);
}

static t_uint	get_rows(char *file)
{
	int		fd;
	char	*line;
	t_uint	rows;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Could not open map file");
	rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (rows == 0)
		ft_error("Map file is empty");
	return (rows);
}

static int	init_map(t_game *game, char *file)
{
	game->map.height = get_rows(file);
	if (game->map.height < 3)
		ft_error("Map is too small");
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		ft_error("Memory allocation failed");
	return (1);
}

int	read_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	t_uint	i;

	i = 0;
	if (!init_map(game, file))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Could not open map file");
	while (i < game->map.height)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error("Map has fewer lines than expected");
		game->map.grid[i] = safe_strdup(line);
		free(line);
		i++;
	}
	game->map.grid[i] = NULL;
	close(fd);
	return (1);
}
