/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/08/14 17:43:36 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define VAOV 90.0
# define HAOV 90.0
# define PERSON 1.8
# define WALL 3.0
# define EPSILON 0.00001
# define DISTANCE_FROM_WALL 1.5

enum	e_general_constants
{
	FULL_CIRCLE_DEGREES = 360,
	TURN_INTERVAL = 10,
};

enum	e_dimensions
{
	WINDOW_HEIGHT = 900,
	WINDOW_WIDTH = 1600
};

typedef struct s_loc
{
	int					x;
	int					y;
	char				c;
	int					x0;
	int					y0;
	int					x1;
	int					y1;
	double				x_mid;
	double				y_mid;
	double				sx;
	double				sy;
	double				ex;
	double				ey;
	double				wx;
	double				wy;
	double				nx;
	double				ny;
	struct s_loc		*next;
	struct s_loc		*previous;
}						t_loc;

typedef struct s_render
{
	double				ceil_height;
	double				floor_height;
	double				wall_height;
	char				wall_texture;
	int					x;
	double				x_winner;
	double				y_winner;

}						t_render;

typedef struct s_map
{
	char				*north;
	char				*south;
	char				*west;
	char				*east;
	char				*f;
	char				*c;
	t_loc				*start;
}						t_map;

typedef struct s_elem
{
	mlx_image_t			*north;
	mlx_image_t			*west;
	mlx_image_t			*south;
	mlx_image_t			*east;
	mlx_image_t			*f;
	mlx_image_t			*c;
}						t_elem;

typedef struct s_image
{
	mlx_image_t			*image;
	struct s_data		*next;
}						t_image;

typedef struct s_strip
{
	int					x;
	char				wall;
	double				wall_h;
	double				ceil_h;
	double				floor_h;
	int					wall_length;
	int					index;
	double				x_winner;
	double				y_winner;
	int					nb_blocks;
	struct s_strip		*previous;
	struct s_strip		*next;
}						t_strip;

typedef struct s_possible
{
	t_loc				*loc;
	double				sn_winner_distance;
	double				ew_winner_distance;
	char				sn_winner_texture;
	char				ew_winner_texture;
	double				sn_winner_x;
	double				sn_winner_y;
	double				ew_winner_x;
	double				ew_winner_y;
	struct s_possible	*previous;
	struct s_possible	*next;
}						t_possible;

typedef struct s_winner
{
	t_possible			*pos;
	char				texture;
	double				x_winner;
	double				y_winner;

}						t_winner;

typedef struct s_range
{
	int					x_min;
	int					x_max;
	int					y_min;
	int					y_max;
}						t_range;

typedef struct s_all
{
	t_map				*map;
	int					floor_color;
	int					ceil_color;
	double				x;
	double				y;
	double				angle;
	double				left_distance;
	double				right_distance;
	int					distance_flag;
	t_possible			*possible;
	double				map_width;
	double				map_height;
	double				max_distance;
	int					fd;
	char				*strmap;
	char				*argv;
	mlx_t				*window;
	t_strip				*strip;
	mlx_image_t			*image;
	mlx_image_t			*north;
	mlx_image_t			*west;
	mlx_image_t			*south;
	mlx_image_t			*east;
}						t_all;

int						color(int r, int g, int b, int a);
t_map					*map_parser(t_all *all);
void					terminate(t_all *all, int status);
void					check_failure(int input1, void *input2, int type,
							t_all *all);
void					reader(t_all *all);
void					create_loc(t_all *all);
t_loc					*create_loc_node(char temp, int x, int y);
t_loc					*clean_loc(t_loc *first);
void					init_strip(t_all *all, t_render data_render);
void					fill_index_strip(t_all *all);
void					fill_length_strip(t_all *all);
void					clean_strip(t_all *all);
mlx_image_t				*image_maker(t_all *all, char type);
int						color_maker(t_all *all, char type);
void					strip_to_image(t_all *all);
void					press_key(mlx_key_data_t keydata, void *param);
void					render(t_all *all);
double					under_full_circle(double angle);
t_possible				*clean_possibility(t_possible *first);
void					create_possibility(t_all *all, t_range range);
void					find_winner_surface(t_all *all);
void					ignore_inside_surface(t_all *all);
int						game_size(t_all *all, char c);
double					max_distance(t_all *all);
void					update_strips(t_all *all);
int						same_double(double d1, double d2);
void					clean_2d_char_array(char **array);
void					temp_movment225(double *new_x, double *new_y, char c);
void					temp_movment135(double *new_x, double *new_y, char c);
void					temp_movment45(double *new_x, double *new_y, char c);
void					temp_movment315(double *new_x, double *new_y, char c);
void					conditional_move(t_all *all, double new_x,
							double new_y);
int						is_wall_there(t_all *all, int x, int y);
void					fill_number_of_blocks(t_all *all);
int						get_pixel(mlx_image_t *image, int i, int j);
char					*custom_strdup(t_all *all, char *found, char *str);
void					remove_white_space(t_all *all);
void					check_valid_color(t_all *all, char type);

#endif // CUB3D_H
