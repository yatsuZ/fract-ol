/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:45 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/09 20:45:43 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fract_ol.h"

/*
TO DO :
	PARTIE		GRAPHIQUE | X
	PARTIE		FRACTAL   | X
*/

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

#include "mlx.h"

#include "mlx.h"

void	draw_yellow_circle(t_data *data)
{
	int	center_x = data->len_x / 2; // Coordonnée x du centre du cercle
	int	center_y = data->len_y / 2; // Coordonnée y du centre du cercle
	int	radius = 100; // Rayon du cercle
	int	color = 0x00FFFF00; // Couleur jaune (format ARGB)
	int	y = center_y - radius;

	while (y <= center_y + radius)
	{
		int	x = center_x - radius;
		while (x <= center_x + radius)
		{
			int	dx = x - center_x;
			int	dy = y - center_y;
			int	distance = dx * dx + dy * dy;

			if (distance >= radius * radius)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
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
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, y_min, 0x000000FF);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, y_max, 0x000000FF);
		i++;
	}
	i = y_min;
	while (i <= y_max)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x_min, i, 0x000000FF);
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x_max, i, 0x000000FF);
		i++;
	}
}

int	main(void)
{
	t_data	*data;
	// t_img_data img;

	ft_printf("--DEBUT--\n");
	data = cree_fenetre("TEST", 500, 500);
	if (!data)
		return (1);
	// img.img = mlx_new_image(data->mlx_ptr, data->len_x, data->len_y);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.img, 0, 0);
	blue_square(data);
	draw_yellow_circle(data);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->len_x / 2, data->len_y / 2, 0xFFFFFFFF);
	add_event(data);
	mlx_loop(data->mlx_ptr);
	return (free_data(data), ft_printf("-- FIN --\n"), 0);
}
