/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometrie_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:31:51 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/06 19:38:33 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	blue_square(t_window *w)
{
	int	i;
	int	j;
	int	max;

	max = w->len_x / 4;
	i = 0;
	while (i <= max)
	{
		j = 0;
		while (j <= max)
		{
			img_pixel_put(w->img, i, j, 0x000000FF);
			j++;
		}
		i++;
	}
}

void	green_triangle(t_window *w)
{
	int	i;
	int	j;
	int	max;

	max = w->len_x / 4;
	i = 0;
	while (i <= max)
	{
		j = 0;
		while (j <= max)
		{
			if (i + j > max)
				img_pixel_put(w->img, i + 2 * max, j, 0x000FF00);
			j++;
		}
		i++;
	}
}

void	draw_yellow_circle(t_window *w)
{
	int	center_x = w->len_x / 2; // Coordonnée x du centre du 
	int	center_y = w->len_y / 2; // Coordonnée y du centre du cercle
	int	radius = w->len_y / 4; // Rayon du cercle
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
				img_pixel_put(w->img, x, y, 0x00FFFF00);
			x++;
		}
		y++;
	}
}