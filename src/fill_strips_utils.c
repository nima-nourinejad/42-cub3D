/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_strips_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:11:11 by asohrabi          #+#    #+#             */
/*   Updated: 2024/08/14 19:15:30 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_strip	*last_node_strips(t_strip *node)
{
	if (!node)
		return (0);
	while (node->next)
		node = node->next;
	return (node);
}

t_strip	*last_wall_node(t_strip *node)
{
	if (!node)
		return (0);
	while (node && node->index != (node->wall_length) - 1)
		node = node->next;
	return (node);
}

t_strip	*first_wall_node(t_strip *node)
{
	if (!node)
		return (0);
	while (node && node->index != 0)
		node = node->previous;
	return (node);
}

t_strip	*create_strips_node(t_render data_render)
{
	t_strip	*new;

	new = (t_strip *)malloc(sizeof(t_strip));
	if (!new)
		return (0);
	new->next = 0;
	new->x = data_render.x;
	new->ceil_h = data_render.ceil_height;
	new->floor_h = data_render.floor_height;
	new->wall_h = data_render.wall_height;
	new->wall = data_render.wall_texture;
	new->index = 0;
	new->wall_length = 0;
	new->next = 0;
	new->previous = 0;
	new->x_winner = data_render.x_winner;
	new->y_winner = data_render.y_winner;
	return (new);
}

void	init_strips(t_all *all, t_render data_render)
{
	t_strip	*new;
	t_strip	*old;

	old = last_node_strips(all->strip);
	new = create_strips_node(data_render);
	if (!old)
		all->strip = new;
	else
	{
		old->next = new;
		new->previous = old;
	}
	check_failure(0, new, 2, all);
}