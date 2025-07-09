/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:13:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:40:25 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_minimap_cell(t_game *game, int x, int y, uint32_t color)
{
	int	dx;
	int	dy;
	int	px;
	int	py;

	px = MINI_OFFSET + x * MINIMAP_SCALE;
	py = MINI_OFFSET + y * MINIMAP_SCALE;
	dy = 0;
	while (dy < MINIMAP_SCALE)
	{
		dx = 0;
		while (dx < MINIMAP_SCALE)
		{
			mlx_put_pixel(game->image, px + dx, py + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	draw_minimap_player(t_game *game)
{
	int	px;
	int	py;
	int	dx;
	int	dy;
	int	radio;

	px = (int)(game->player.pos.x * MINIMAP_SCALE);
	py = (int)(game->player.pos.y * MINIMAP_SCALE);
	radio = 3;
	dy = -radio;
	while (dy <= radio)
	{
		dx = -radio;
		while (dx <= radio)
		{
			if (dx * dx + dy * dy <= radio * radio)
				mlx_put_pixel(game->image, MINI_OFFSET + px
					+ dx, MINI_OFFSET + py + dy, 0xFF0000FF);
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *game)
{
	int			y;
	int			x;
	uint32_t	color;

	y = 0;
	while (y < (int)game->map.height)
	{
		x = 0;
		while (x < (int)game->map.width)
		{
			color = 0x000000FF;
			if (game->map.grid[y][x] == '1')
				color = 0x333333FF;
			else if (game->map.grid[y][x] == '0')
				color = 0xCCCCCCFF;
			draw_minimap_cell(game, x, y, color);
			x++;
		}
		y++;
	}
	draw_minimap_player(game);
}
