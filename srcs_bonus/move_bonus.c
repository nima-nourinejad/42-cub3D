/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:51:06 by nnourine          #+#    #+#             */
/*   Updated: 2024/08/29 11:32:13 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	temp_movment45(double *new_x, double *new_y, char c)
{
	if (c == 'W')
		(*new_y) += 1;
	else if (c == 'S')
		(*new_y) -= 1;
	else if (c == 'A')
		(*new_x) += 1;
	else
		(*new_x) -= 1;
}

void	temp_movment135(double *new_x, double *new_y, char c)
{
	if (c == 'W')
		(*new_x) -= 1;
	else if (c == 'S')
		(*new_x) += 1;
	else if (c == 'A')
		(*new_y) += 1;
	else
		(*new_y) -= 1;
}

void	temp_movment225(double *new_x, double *new_y, char c)
{
	if (c == 'A')
		(*new_x) -= 1;
	else if (c == 'D')
		(*new_x) += 1;
	else if (c == 'W')
		(*new_y) -= 1;
	else
		(*new_y) += 1;
}

void	temp_movment315(double *new_x, double *new_y, char c)
{
	if (c == 'W')
		(*new_x) += 1;
	else if (c == 'S')
		(*new_x) -= 1;
	else if (c == 'A')
		(*new_y) -= 1;
	else
		(*new_y) += 1;
}

void	conditional_move(t_all *all, double new_x, double new_y)
{
	new_x = (int)(new_x - 0.5);
	new_y = (int)(new_y - 0.5);
	if (!is_wall_there(all, new_x, new_y))
	{
		clean_strips(all);
		mlx_delete_image(all->window, all->image);
		all->x = new_x + 0.5;
		all->y = new_y + 0.5;
		fill_strips(all);
	}
}
