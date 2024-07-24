/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/07/24 14:58:07 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>  // For malloc, free, exit
# include <string.h>  // For strerror
# include <unistd.h>  // For open, close, read, write
# include <fcntl.h>   // For file control options
# include <errno.h>   // For errno
# include <stdio.h>   // For printf
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define START_IMAGE_SIZE 100
# define MIN_IMAGE_SIZE 10
# define MAX_MONITOR_USAGE 0.95
# define FULL_CIRCLE_DEGREES 360
# define VAOV 120.0
# define HAOV 180.0
# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH 800
# define HEIGHT_INTERVAL VAOV / WINDOW_HEIGHT
# define WIDTH_INTERVAL HAOV / WINDOW_WIDTH
# define PERSON 1.80
# define WALL 3.0

typedef struct s_loc
{
	int				x;
	int				y;
	char			c;
	struct s_loc	*next;
	struct s_loc	*previous;
}					t_loc;

typedef struct s_render
{
	int		ceil_height;
	int		floor_height;
	int		wall_height;
	char	wall_texture;
	int		x;
}			t_render;

typedef struct s_map
{
	char	*north;
	char	*south;
	char 	*west;
	char	*east;
	char	*f;
	char	*c;
	t_loc	*start;
}			t_map;

typedef struct s_all
{
	t_map	*map;
	t_loc	*render;
	int		fd;
	char	*strmap;
	char	*argv;
}			t_all;

t_map	*map_parser(t_all *all);
void	terminate(t_all *all, int status);
void	check_failure(int input1, void *input2, int type, t_all *all);
void	reader(t_all *all);
void	create_loc(t_all *all);
t_loc	*create_loc_node(char temp, int x, int y);
t_loc	*clean_loc(t_loc *first);
void	create_render(t_all *all, t_render data_render);

#endif // CUB3D_H