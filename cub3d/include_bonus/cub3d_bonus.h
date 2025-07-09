/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analba-s <analba-s@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:14:37 by nporras-          #+#    #+#             */
/*   Updated: 2025/07/07 12:29:47 by analba-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# define WIDTH 1920
# define HEIGHT 1080
# define FOV 60.0
# define MOVE_SPEED 0.05
# define ROT_SPEED 2.0
# define MAP_CHARS "01NSEW "
# define MINIMAP_SCALE 7
# define MINI_OFFSET 15

typedef unsigned int	t_uint;

typedef enum e_elements
{
	EMPTY = '0',
	WALL = '1',
	NORTH = 'N',
	SOUTH = 'S',
	EAST = 'E',
	WEST = 'W',
	SPACE = ' '
}						t_elements;

typedef struct s_position
{
	double				x;
	double				y;
}						t_position;

typedef struct s_textures
{
	mlx_texture_t		*north;
	mlx_texture_t		*south;
	mlx_texture_t		*west;
	mlx_texture_t		*east;
	uint32_t			floor_color;
	uint32_t			ceiling_color;
}						t_textures;

typedef struct s_map
{
	char				**grid;
	t_uint				width;
	t_uint				height;
	t_uint				players;
	char				*north_path;
	char				*south_path;
	char				*west_path;
	char				*east_path;
	int					floor_rgb[3];
	int					ceiling_rgb[3];
}						t_map;

typedef struct s_player
{
	t_position			pos;
	double				angle;
	bool				up;
	bool				down;
	bool				left;
	bool				right;
	bool				rot_left;
	bool				rot_right;
	double				dir_x;
	double				dir_y;
}						t_player;

typedef struct s_render
{
	int					x;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				side_dist_x;
	double				side_dist_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	double				perp_wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	mlx_texture_t		*texture;
	double				wall_x;
	int					tex_x;
	int					tex_y;
	int					d;
	uint32_t			color;
	int					y;
}						t_render;

typedef struct s_game
{
	mlx_t				*mlx;
	mlx_image_t			*image;
	t_textures			textures;
	t_map				map;
	t_player			player;
	t_uint				move_flag;
	t_render			*render;
}						t_game;

int						init_game(t_game *game, char *map_path);
void					init_player(t_game *game);
int						read_map(t_game *game, char *file);
int						validate_map(t_game *game);
void					render_frame(t_game *game);

char					*skip_textures_and_find_map(int fd, t_game *game,
							int parse_textures);
t_uint					count_map_lines(char *file, t_game *game);
int						read_map_lines(t_game *game, int fd, char *first_line);
void					calculate_map_dimensions(t_game *game);
int						is_map_line(char *line);
void					parse_texture_line(t_game *game, char *line);
int						is_texture_line(char *line, t_game *game);
char					*strdup_trimmed_line(char *line, t_game *game);

void					handle_player_element(t_game *game, char element,
							t_uint i, t_uint j);
char					**create_temp_map(t_game *game);
void					flood_fill(char **map, int x, int y, t_game *game);
int						check_flood_bounds(char **temp, t_game *game);
void					free_temp_map(char **temp, t_uint height);

void					handle_keys(mlx_key_data_t keydata, void *param);
void					handle_keypress(mlx_key_data_t keydata, void *param);
void					handle_keyrelease(mlx_key_data_t keydata, void *param);
void					handle_close(void *param);
void					update_game(void *param);

void					ft_error_game(t_game *game, char *message);
void					close_game(t_game *game);
void					parse_rgb_color(char *str, int rgb[3], t_game *game,
							char *line);

void					move_forward(t_game *game);
void					move_backward(t_game *game);
void					strafe_left(t_game *game);
void					strafe_right(t_game *game);
void					rotate_left(t_game *game);
void					rotate_right(t_game *game);

void					ray_direction(t_game *game, t_render *r);
void					dda_1(t_game *game, t_render *r);
void					distance_to_wall(t_game *game, t_render *r);
void					draw_textures(t_game *game, t_render *r);

void					draw_minimap(t_game *game);

#endif
