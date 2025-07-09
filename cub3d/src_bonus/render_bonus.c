/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:00:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/02 14:40:11 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	choose_texture(t_game *g, t_render *r)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			r->texture = g->textures.east;
		else
			r->texture = g->textures.west;
	}
	else
	{
		if (r->ray_dir_y > 0)
			r->texture = g->textures.south;
		else
			r->texture = g->textures.north;
	}
	if (r->side == 0)
		r->wall_x = g->player.pos.y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_x = g->player.pos.x + r->perp_wall_dist * r->ray_dir_x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * r->texture->width);
	if ((r->side == 0 && r->ray_dir_x < 0)
		|| (r->side == 1 && r->ray_dir_y > 0))
		r->tex_x = r->texture->width - r->tex_x - 1;
}

void	render_frame(t_game *game)
{
	t_render	r;

	r.x = 0;
	while (r.x < WIDTH)
	{
		ray_direction(game, &r);
		dda_1(game, &r);
		distance_to_wall(game, &r);
		choose_texture(game, &r);
		draw_textures(game, &r);
		r.x++;
	}
	draw_minimap(game);
}
