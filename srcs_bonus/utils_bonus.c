/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:15:54 by asohrabi          #+#    #+#             */
/*   Updated: 2024/08/29 11:32:13 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

int	color(int r, int g, int b, int a)
{
	if (r >= 0 && g >= 0 && b >= 0 && a >= 0
		&& r <= 255 && g <= 255 && b <= 255 && a <= 255)
		return (r << 24 | g << 16 | b << 8 | a);
	if (r < 0)
		return (color(0, g, b, a));
	if (g < 0)
		return (color(r, 0, b, a));
	if (b < 0)
		return (color(r, g, 0, a));
	if (a < 0)
		return (color(r, g, b, 0));
	if (r > 255)
		return (color(255, g, b, a));
	if (g > 255)
		return (color(r, 255, b, a));
	if (b > 255)
		return (color(r, g, 255, a));
	return (color(r, g, b, 255));
}

int	color_maker(t_all *all, char type)
{
	char	*full_color;
	char	**split;
	int		int_color;
	char	str[2];

	str[1] = '\0';
	str[0] = type;
	if (type == 'f')
		full_color = all->map->f;
	else
		full_color = all->map->c;
	if (!full_color)
		terminate(all, "There is no information for ", str,
			" identifier in the map");
	split = ft_split(full_color, ',');
	if (!split)
		terminate(all, "Splitting string failed", NULL, NULL);
	int_color = color(ft_atoi(split[0]), ft_atoi(split[1]),
			ft_atoi(split[2]), 255);
	clean_2d_char_array(split);
	return (int_color);
}

int	get_pixel(mlx_image_t *image, int i, int j)
{
	uint8_t	*pixel;

	pixel = image->pixels + 4 * (i + j * image->width);
	return (color(pixel[0], pixel[1], pixel[2], pixel[3]));
}

static char	*address_finder(t_all *all, char type)
{
	char	*address;

	if (type == 'E')
		address = all->map->east;
	else if (type == 'W')
		address = all->map->west;
	else if (type == 'S')
		address = all->map->south;
	else if (type == 'N')
		address = all->map->north;
	else if (type == 'G')
		address = GUN_PATH;
	else if (type == 'B')
		address = BLAST_PATH;
	else if (type == 'K')
		address = KNIFE_PATH;
	else if (type == 'A')
		address = AIM_PATH;
	else
		address = PLAYER_PATH;
	check_texture_exists(all, address);
	return (address);
}

mlx_image_t	*image_maker(t_all *all, char type)
{
	mlx_texture_t	*texture;
	mlx_image_t		*picture;
	char			*address;

	address = address_finder(all, type);
	texture = mlx_load_png(address);
	if (!texture)
		terminate(all, "Loading texture failed", NULL, NULL);
	picture = mlx_texture_to_image(all->window, texture);
	mlx_delete_texture(texture);
	if (!picture)
		terminate(all, "Converting texture to image failed", NULL, NULL);
	if (type == 'P')
		if (mlx_resize_image(picture, MINIMAP_SIDE / MINIMAP_COVERAGE,
				MINIMAP_SIDE / MINIMAP_COVERAGE) == 0)
			terminate(all, "Resizing image failed", NULL, NULL);
	if (type == 'B')
		if (mlx_resize_image(picture, 50, 50) == 0)
			terminate(all, "Resizing image failed", NULL, NULL);
	if (type == 'A')
		if (mlx_resize_image(picture, 100, 100) == 0)
			terminate(all, "Resizing image failed", NULL, NULL);
	return (picture);
}
