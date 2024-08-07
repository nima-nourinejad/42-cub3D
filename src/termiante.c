/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termiante.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:23:46 by nnourine          #+#    #+#             */
/*   Updated: 2024/08/07 11:49:38 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	terminate(t_all *all, int status)
{
	if (all->fd != -1)
		close(all->fd);
	if (all->strip)
		clean_strip(all);
	if (all->map->north)
		free(all->map->north);
	if (all->map->south)
		free(all->map->south);
	if (all->map->west)
		free(all->map->west);
	if (all->map->east)
		free(all->map->east);
	if (all->map->f)
		free(all->map->f);
	if (all->map->c)
		free(all->map->c);
	if (all->map->start)
		clean_loc(all->map->start);
	if (all->map)
		free(all->map); //update this to free_map
	if (all->strmap)
		free(all->strmap);
	// if (all->render)
	// 	clean_loc(all->render); //update this to free_render
	if (status)
		ft_putendl_fd("Error", 2);
	// if (all->elems)
	// {
	// 	if (all->elems->north)
	// 		mlx_delete_image(all->window, all->elems->north);
	// 	if (all->elems->south)
	// 		mlx_delete_image(all->window, all->elems->south);
	// 	if (all->elems->west)
	// 		mlx_delete_image(all->window, all->elems->west);
	// 	if (all->elems->east)
	// 		mlx_delete_image(all->window, all->elems->east);
	// 	if (all->elems->f)
	// 		mlx_delete_image(all->window, all->elems->f);
	// 	if (all->elems->c)
	// 		mlx_delete_image(all->window, all->elems->c);
	// 	free(all->elems);
	// }
	if (all->window)
		mlx_terminate(all->window);
	free(all);
	exit(status);
}

void	check_failure(int input1, void *input2, int type, t_all *all)
{
	if ((input1 < 0 && type == 1)
		|| (type == 2 && input2 == NULL))
		terminate(all, 1);
}