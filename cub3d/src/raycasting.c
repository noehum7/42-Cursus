/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nporras- <nporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:00:00 by nporras-          #+#    #+#             */
/*   Updated: 2025/06/30 13:45:43 by nporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_3(t_game *game, t_render *r)
{
	r->hit = 0;
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (game->map.grid[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

static void	dda_2(t_game *game, t_render *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (game->player.pos.x - r->map_x)
			* r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - game->player.pos.x)
			* r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (game->player.pos.y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - game->player.pos.y)
			* r->delta_dist_y;
	}
	dda_3(game, r);
}

void	dda_1(t_game *game, t_render *r)
{
	r->map_x = (int)game->player.pos.x;
	r->map_y = (int)game->player.pos.y;
	r->delta_dist_x = fabs(1 / r->ray_dir_x);
	r->delta_dist_y = fabs(1 / r->ray_dir_y);
	dda_2(game, r);
}

void	distance_to_wall(t_game *game, t_render *r)
{
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - game->player.pos.x
				+ (1 - r->step_x) / 2) / r->ray_dir_x;
	else
		r->perp_wall_dist = (r->map_y - game->player.pos.y
				+ (1 - r->step_y) / 2) / r->ray_dir_y;
	r->line_height = (int)(HEIGHT / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + HEIGHT / 2;
	if (r->draw_end >= HEIGHT)
		r->draw_end = HEIGHT - 1;
}

void	ray_direction(t_game *game, t_render *r)
{
	r->camera_x = 2 * r->x / (double)WIDTH - 1;
	r->ray_dir_x = game->player.dir_x + r->camera_x * -game->player.dir_y;
	r->ray_dir_y = game->player.dir_y + r->camera_x * game->player.dir_x;
}
