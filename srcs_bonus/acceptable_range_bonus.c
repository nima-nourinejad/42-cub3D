/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acceptable_range_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:19:13 by asohrabi          #+#    #+#             */
/*   Updated: 2024/08/29 11:32:13 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

double	min_x(double x_player, double angle)
{
	if (angle >= 0 && angle <= FULL_CIRCLE_DEGREES / 4)
		return (x_player);
	else if (angle > FULL_CIRCLE_DEGREES / 4
		&& angle <= FULL_CIRCLE_DEGREES * 3 / 4)
		return (0);
	else
		return (x_player);
}

double	max_x(double x_player, int x_game_size, double angle)
{
	if (angle >= 0 && angle <= FULL_CIRCLE_DEGREES / 4)
		return (x_game_size);
	else if (angle > FULL_CIRCLE_DEGREES / 4
		&& angle <= FULL_CIRCLE_DEGREES * 3 / 4)
		return (x_player);
	else
		return (x_game_size);
}

double	min_y(double y_player, double angle)
{
	if (angle >= 0 && angle < FULL_CIRCLE_DEGREES / 2)
		return (y_player);
	else
		return (0);
}

double	max_y(double y_player, int y_game_size, double angle)
{
	if (angle >= 0 && angle < FULL_CIRCLE_DEGREES / 2)
		return (y_game_size);
	else
		return (y_player);
}
