/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:33:05 by asohrabi          #+#    #+#             */
/*   Updated: 2024/08/29 14:50:46 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static double	start_loc_player(t_all *all, char c)
{
	t_loc	*loc;

	loc = all->map->start;
	while (loc)
	{
		if (loc->c == 'N' || loc->c == 'S' || loc->c == 'W' || loc->c == 'E')
		{
			if (c == 'x')
				return (loc->x + 0.5);
			else
				return (loc->y + 0.5);
		}
		loc = loc->next;
	}
	return (-1);
}

static double	start_angle_player(t_all *all)
{
	t_loc	*loc;

	loc = all->map->start;
	while (loc)
	{
		if (loc->c == 'N' || loc->c == 'S' || loc->c == 'W' || loc->c == 'E')
		{
			if (loc->c == 'N')
				return ((double)270);
			else if (loc->c == 'S')
				return ((double)90);
			else if (loc->c == 'W')
				return ((double)0);
			else
				return ((double)180);
		}
		loc = loc->next;
	}
	return (-1);
}

t_all	*init_all(char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		terminate(all, "Allocating memory failed", NULL, NULL);
	ft_memset(all, 0, sizeof(t_all));
	all->argv = argv[1];
	all->map = map_parser(all);
	all->floor_color = color_maker(all, 'f');
	all->ceil_color = color_maker(all, 'c');
	all->x = start_loc_player(all, 'x');
	all->y = start_loc_player(all, 'y');
	all->angle = start_angle_player(all);
	all->max_distance = max_distance(all);
	remove_unnecessary_nodes(all);
	all->window = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, argv[0], false);
	if (!all->window)
		terminate(all, "Initializing window failed", NULL, NULL);
	all->north = image_maker(all, 'N');
	all->west = image_maker(all, 'W');
	all->south = image_maker(all, 'S');
	all->east = image_maker(all, 'E');
	return (all);
}
