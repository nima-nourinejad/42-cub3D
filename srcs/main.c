/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:43:59 by nnourine          #+#    #+#             */
/*   Updated: 2024/08/26 14:27:13 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// 6) delete or solve the problem of cloning mlx42 in Makefile

// 9) find good material for walls

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Invalid number of arguments", 2);
		ft_putendl_fd("Error", 2);
		exit (1);
	}
	if (!check_map_format(argv[1]))
	{
		ft_putendl_fd("Invalid map format", 2);
		ft_putendl_fd("Error", 2);
		exit (1);
	}
}

void	hooks_loops(t_all *all)
{
	mlx_key_hook(all->window, &keyboard, all);
	mlx_mouse_hook(all->window, &click, all);
	mlx_cursor_hook(all->window, &mouse, all);
	mlx_scroll_hook(all->window, &scroll, all);
	mlx_loop_hook(all->window, &animation, all);
	mlx_loop(all->window);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	check_args(argc, argv);
	all = init_all(argv);
	fill_strips(all);
	hooks_loops(all);
	terminate(all, NULL, NULL, NULL);
}
