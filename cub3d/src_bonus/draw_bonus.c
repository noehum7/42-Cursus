/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:00:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:40:33 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	uint8_t	*p;
	int		i;

	p = texture->pixels;
	i = (y * texture->width + x) * 4;
	if (!texture || x < 0 || y < 0 || x >= (int)texture->width
		|| y >= (int)texture->height)
		return (0x000000FF);
	return ((p[i] << 24) | (p[i + 1] << 16) | (p[i + 2] << 8) | p[i + 3]);
}

static void	draw_ceiling(t_game *g, t_render *r)
{
	int	y;

	y = 0;
	while (y < r->draw_start)
	{
		mlx_put_pixel(g->image, r->x, y, g->textures.ceiling_color);
		y++;
	}
}

static void	draw_floor(t_game *g, t_render *r)
{
	int	y;

	y = r->draw_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(g->image, r->x, y, g->textures.floor_color);
		y++;
	}
}

static void	draw_wall(t_game *g, t_render *r)
{
	int	y;

	y = r->draw_start;
	while (y < r->draw_end)
	{
		r->d = y * 256 - HEIGHT * 128 + r->line_height * 128;
		r->tex_y = ((r->d * r->texture->height) / r->line_height) / 256;
		r->color = get_texture_color(r->texture, r->tex_x, r->tex_y);
		mlx_put_pixel(g->image, r->x, y, r->color);
		y++;
	}
}

void	draw_textures(t_game *g, t_render *r)
{
	draw_ceiling(g, r);
	draw_wall(g, r);
	draw_floor(g, r);
}
