/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:45 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/10 02:27:51 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fract_ol.h"

/*
TO DO :
	PARTIE		GRAPHIQUE | X
	PARTIE		FRACTAL   | X
*/

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	ft_printf("%s\n", data->addr);
	*(unsigned int*)dst = color;
}

int degrader_de_couleur(int x, int y, int width, int height)
{
	int color;

	if (width < 0)
		width = width * -1;
	if (height < 0)
		height = height * -1;
	color = (x * 255) / width + ((((width - x) * 255) / width) << 16) + ((( y * 255) / height) << 8);
    return (color);
}

void	only_degrader(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->len_y > y)
	{
		x = -1;
		while (data->len_x > ++x)
			img_pixel_put(data, x, y, degrader_de_couleur(x, y, data->len_x, data->len_y));
		y++;
	}
}

void	draw_yellow_circle(t_data *data)
{
	int	center_x = data->len_x / 2; // Coordonnée x du centre du cercle
	int	center_y = data->len_y / 2; // Coordonnée y du centre du cercle
	int	radius = 100; // Rayon du cercle
	int	y = center_y - radius;

	while (y <= center_y + radius)
	{
		int	x = center_x - radius;
		while (x <= center_x + radius)
		{
			int	dx = x - center_x;
			int	dy = y - center_y;
			int	distance = dx * dx + dy * dy;

			if (distance <= radius * radius)
				img_pixel_put(data, x, y, degrader_de_couleur(x, y, radius, radius));
			x++;
		}
		y++;
	}
}


void	blue_square(t_data *data)
{
	int	i;
	int	x_min;
	int	x_max;
	int	y_max;
	int	y_min;

	x_min = data->len_x / 4;
	x_max = 3 * (data->len_x / 4);
	y_min = data->len_y / 4;
	y_max = 3 * (data->len_y / 4);
	i = x_min;
	while (i <= x_max)
	{
		img_pixel_put(data, i, y_min, 0x000000FF);
		img_pixel_put(data, i, y_max, 0x000000FF);
		i++;
	}
	i = y_min;
	while (i <= y_max)
	{
		img_pixel_put(data, x_min, i, 0x000000FF);
		img_pixel_put(data, x_max, i, 0x000000FF);
		i++;
	}
}

int	main(void)
{
	t_data	*data;

	ft_printf("--DEBUT--\n");
	data = cree_fenetre("TEST", 500, 500);
	if (!data)
		return (1);
	only_degrader(data);
	img_pixel_put(data, 5, 5, 0x00FF0000);
	blue_square(data);
	draw_yellow_circle(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->len_x / 2, data->len_y / 2, 0xFFFFFFFF);
	add_event(data);
	mlx_loop(data->mlx_ptr);
	return (free_data(data), ft_printf("-- FIN --\n"), 0);
}
