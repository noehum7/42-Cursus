/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:11:30 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:39:59 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_arr(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	validate_rgb_count(char **split, t_game *game, char *line)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	if (count != 3)
	{
		free_arr(split);
		free(line);
		ft_error_game(game, "RGB format must be: R,G,B");
	}
}

static void	check_rgb_numeric(char *str, char **split, t_game *game, char *line)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!ft_isdigit(str[j]) && str[j] != ' ' && str[j]
			!= '\n' && str[j] != '\r')
		{
			free_arr(split);
			free(line);
			ft_error_game(game, "Invalid RGB value - must be numeric");
		}
		j++;
	}
}

static void	parse_rgb_values(char **split, int rgb[3], t_game *game, char *line)
{
	int		i;
	char	*trimmed;

	validate_rgb_count(split, game, line);
	i = 0;
	while (i < 3)
	{
		check_rgb_numeric(split[i], split, game, line);
		trimmed = ft_strtrim(split[i], " \n\r");
		if (!trimmed)
		{
			free_arr(split);
			free(line);
			ft_error_game(game, "Memory allocation failed");
		}
		rgb[i] = ft_atoi(trimmed);
		free(trimmed);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free_arr(split);
			free(line);
			ft_error_game(game, "RGB values must be between 0-255");
		}
		i++;
	}
}

void	parse_rgb_color(char *str, int rgb[3], t_game *game, char *line)
{
	char	**split;

	split = ft_split(str, ',');
	if (!split)
	{
		free(line);
		ft_error_game(game, "Invalid color format");
	}
	parse_rgb_values(split, rgb, game, line);
	free_arr(split);
}
