/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometrie_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:31:51 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/07 16:16:35 by yzaoui           ###   ########.fr       */
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
	int	center_x;
	int	center_y;
	int	radius;
	int	y;
	int	x;

	center_x = w->len_x / 2;
	center_y = w->len_y / 2;
	radius = w->len_y / 4;
	y = center_y - radius;
	while (y <= center_y + radius)
	{
		x = center_x - radius;
		while (x <= center_x + radius)
		{
			if (((x - center_x) * (x - center_x) + \
			(y - center_y) * (y - center_y)) <= radius * radius)
				img_pixel_put(w->img, x, y, 0x00FFFF00);
			x++;
		}
		y++;
	}
}

int	ft_change_geometrie(t_window *w, int c)
{
	if (c > 2)
		w->fractal = 0;
	else if (c < 0)
		w->fractal = 2;
	else
		w->fractal = c;
	if (w->fractal == 0)
		return (change_img(w, blue_square));
	else if (w->fractal == 1)
		return (change_img(w, green_triangle));
	else if (w->fractal == 2)
		return (change_img(w, draw_yellow_circle));
	return (0);
}
