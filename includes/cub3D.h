/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/08/29 15:05:09 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

# define VAOV 90.0
# define HAOV 60.0
# define PERSON 1.0
# define WALL 2.0
# define EPSILON 0.00001
# define MIN_CALCULATED_DISTANCE 0.5
# define MAX_NODE 10001
# define BUFFER_SIZE 1000000
# define RENDER_INTERVAL 5
# define TURN_INTERVAL 10
# define FULL_CIRCLE_DEGREES 360
# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1000

typedef struct s_loc
{
	int				x;
	int				y;
	char			c;
	double			sx;
	double			sy;
	double			ex;
	double			ey;
	double			wx;
	double			wy;
	double			nx;
	double			ny;
	int				wet;
	double			sn_winner_distance;
	double			ew_winner_distance;
	char			sn_winner_texture;
	char			ew_winner_texture;
	double			sn_winner_x;
	double			sn_winner_y;
	double			ew_winner_x;
	double			ew_winner_y;
	int				consider;
	struct s_loc	*next;
	struct s_loc	*previous;
}					t_loc;

typedef struct s_render
{
	double			ceil_height;
	double			floor_height;
	double			wall_height;
	char			wall_texture;
	int				x;
	int				x_wall;
	int				y_wall;
	double			x_winner;
	double			y_winner;
	double			x_intersection;
	double			y_intersection;
}					t_render;

typedef struct s_map
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*f;
	char			*c;
	t_loc			*start;
}					t_map;

typedef struct s_player
{
	mlx_image_t		*image;
	double			angle;
	struct s_player	*next;
}					t_player;

typedef struct s_strip
{
	int				x;
	char			wall;
	double			wall_h;
	double			ceil_h;
	double			floor_h;
	int				wall_length;
	int				index;
	int				x_wall;
	int				y_wall;
	double			x_winner;
	double			y_winner;
	double			x_intersection;
	double			y_intersection;
	int				nb_blocks;
	struct s_strip	*previous;
	struct s_strip	*next;
}					t_strip;

typedef struct s_winner
{
	t_loc			*pos;
	char			texture;
	double			x_winner;
	double			y_winner;
	double			x_intersection;
	double			y_intersection;
	double			intersection_distance;
}					t_winner;

typedef struct s_range
{
	int				x_min;
	int				x_max;
	int				y_min;
	int				y_max;
}					t_range;

typedef struct s_pixel_bricks
{
	int				x_rs_brick;
	int				y_rs_brick;
	int				y_in_wall;
	int				x_in_brick;
	int				y_in_brick;
	int				h_rs_brick;
	int				w_rs_brick;
}					t_pixel_bricks;

typedef struct s_current_wall
{
	char			wall;
	int				x_winner;
	int				y_winner;
	int				index;
}					t_current_wall;

typedef struct s_coordinate
{
	int				x;
	int				y;
	int				index;
}					t_coordinate;

typedef struct s_rotate
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				new_x;
	int				new_y;
}					t_rotate;

typedef struct s_all
{
	int				index;
	int				ceil_color;
	int				floor_color;
	int				started_button;
	char			*argv;
	char			*strmap;
	double			x;
	double			y;
	double			angle;
	double			map_width;
	double			map_height;
	double			max_distance;
	long long		start_time;
	long long		current_time;
	t_map			*map;
	t_strip			*strip;
	t_player		*player_image;
	mlx_t			*window;
	mlx_image_t		*image;
	mlx_image_t		*north;
	mlx_image_t		*west;
	mlx_image_t		*south;
	mlx_image_t		*east;
}					t_all;

int					color(int r, int g, int b, int a);
t_map				*map_parser(t_all *all);
void				terminate(t_all *all, char *str1, char *str2, char *str3);
void				reader(t_all *all);
void				create_loc(t_all *all);
t_loc				*create_loc_node(char temp, int x, int y);
void				remove_unnecessary_nodes(t_all *all);
t_loc				*clean_loc(t_loc *first);
void				init_strips(t_all *all, t_render data_render);
void				fill_index_strips(t_all *all);
void				fill_length_strips(t_all *all);
void				clean_strips(t_all *all);
mlx_image_t			*image_maker(t_all *all, char type);
int					color_maker(t_all *all, char type);
void				strip_to_image(t_all *all);
void				keyboard(mlx_key_data_t keydata, void *param);
void				fill_strips(t_all *all);
double				under_full_circle(double angle);
void				find_winner_surface(t_all *all);
void				ignore_inside_surface(t_all *all);
int					game_size(t_all *all, char c);
double				max_distance(t_all *all);
void				clean_2d_char_array(char **array);
void				temp_movment225(double *new_x, double *new_y, char c);
void				temp_movment135(double *new_x, double *new_y, char c);
void				temp_movment45(double *new_x, double *new_y, char c);
void				temp_movment315(double *new_x, double *new_y, char c);
void				conditional_move(t_all *all, double new_x, double new_y);
int					is_wall_there(t_all *all, int x, int y);
int					get_pixel(mlx_image_t *image, int i, int j);
char				*custom_strdup(t_all *all, char *found, char *str);
void				remove_white_space(t_all *all);
void				check_valid_color(t_all *all, char type);
double				ft_tan(double a);
double				ft_cos(double a);
double				distance(double x1, double y1, double x2, double y2);
int					same(double d1, double d2);
double				height(double distance, char c);
t_winner			calculate_distance(t_all *all, t_winner final,
						double ray_angle);
int					check_map_format(char *str);
double				find_x(double angle, double x_player, double y_player,
						double y_target);
double				find_y(double angle, double x_player, double y_player,
						double x_target);
double				min_x(double x_player, double angle);
double				max_x(double x_player, int x_game_size, double angle);
double				min_y(double y_player, double angle);
double				max_y(double y_player, int y_game_size, double angle);
t_winner			find_winner(t_all *all, double ray_angle);
t_all				*init_all(char **argv);
int					find_min_x(t_all *all, int y);
int					find_max_x(t_all *all, int y);
int					find_min_y(t_all *all, int x);
int					find_max_y(t_all *all, int x);
void				compare_adjacent_walls(t_loc *temp1, t_loc *temp2);
void				link_new_node(t_all *all, t_loc *new, t_loc *old);
void				update_coordinate(t_coordinate *coordinate, char *temp);
t_strip				*last_node_strips(t_strip *node);
t_strip				*last_wall_node(t_strip *node);
t_strip				*first_wall_node(t_strip *node);
t_strip				*create_strips_node(t_render data_render);
void				ignore_upper_wall(t_all *all, t_loc *loc);
void				ignore_lower_wall(t_all *all, t_loc *loc);
void				ignore_left_wall(t_all *all, t_loc *loc);
void				ignore_right_wall(t_all *all, t_loc *loc);
void				reset_loc(t_all *all);
void				find_visible_surface(t_all *all, t_range range);
t_winner			find_specific_intersection(t_all *all, double ray_angle,
						char flag);
t_winner			set_final_x_y_winner(t_winner final);
t_winner			set_final_pos_and_texture(t_winner final, t_loc *temp_pos,
						char type);
t_winner			find_general_intersection(t_all *all, double ray_angle);
void				south_wins(t_all *all, t_loc *temp);
void				east_wins(t_all *all, t_loc *temp);
void				north_wins(t_all *all, t_loc *temp);
void				west_wins(t_all *all, t_loc *temp);
void				check_empty_map(t_all *all, char *str, char *error);
long long			ft_timestamp_milis(t_all *all);
void				check_texture_exists(t_all *all, char *address);
void				move_press(void *param, char c);
void				move_repeat(void *param, char c);
void				turn_press(void *param, char c);
void				turn_repeat(void *param, char c);
void				check_dry(t_all *all);
void				flood_map(t_all *all);
char				*finder(t_all *all, char *str);
int					node_is_inside(t_all *all, t_loc *loc);

#endif
