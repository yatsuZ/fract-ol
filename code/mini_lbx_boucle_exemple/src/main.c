/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:45 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/16 16:10:47 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fract_ol.h"

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int degrader_de_couleur(int x, int y, int width, int height)
{
	int color;

	if (width < 0)
		width = width * -1;
	if (height < 0)
		height = height * -1;
	x = y;
	width = height;
	color = (y * 255) / height + ((((height - y) * 255) / height) << 16) + (((x * 255) / width) << 8);
    return (color);
}

int degrader_de_couleurY(int y, int height, int decallage)
{
	int color;

	color = (y + decallage * 255) / height + ((((height - (y)) * 255) / height) << 16);
    return (color);
}

void	only_degrader(t_data *data, int decalage)
{
	int	x;
	int	y;

	y = 0;
	while (data->len_y > y)
	{
		x = -1;
		while (data->len_x > ++x)
			img_pixel_put(data, x, y , degrader_de_couleurY(y, data->len_y, decalage));
		y++;
	}
}

void	arc_en_ciel(t_data *data, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->len_y > y)
	{
		x = -1;
		while (data->len_x > ++x)
			img_pixel_put(data, x , y, color + y);
		y++;
	}
}

void	all_one_color(t_data *data, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->len_y > y)
	{
		x = -1;
		while (data->len_x > ++x)
			img_pixel_put(data, x , y, color);
		y++;
	}
}

void	draw_yellow_circle(t_data *data)
{
	int	center_x = data->img_x; // Coordonnée x du centre du cercle
	int	center_y = data->img_y; // Coordonnée y du centre du cercle
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
				img_pixel_put(data, x, y, 0);
			x++;
		}
		y++;
	}
}

int C = 0;
int	mouve = 0;

int	render_next_frame(void *data_v)
{
	t_data	*data;

	data = (t_data *) data_v;
	if (C >= data->len_y - 50)
		mouve = -50;
	else if (C <= 0)
		mouve = 50;
	only_degrader(data, C);
	draw_yellow_circle(data);
	C = C + mouve;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}


int	main(void)
{
	t_data	*data;

	ft_printf("--DEBUT--\n");
	data = cree_fenetre("TEST", 500, 500);
	if (!data)
		return (1);
	add_event(data);
	data->img_x = data->len_x / 2;
	data->img_y = data->len_y / 2;
	mlx_loop_hook(data->mlx_ptr, render_next_frame, data);
	mlx_loop(data->mlx_ptr);
	return (free_data(data), ft_printf("-- FIN --\n"), 0);
}
