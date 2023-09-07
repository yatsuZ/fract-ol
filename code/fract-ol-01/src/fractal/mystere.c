/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystere.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:57:56 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/07 17:13:50 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	color4(t_window *w, int axe_x, int axe_y, int i)
{
	int	color;
	int	j;

	j = 0;
	while (i != w->len_x)
	{
		j = 0;
		while (j != w->len_y)
		{
			if (i < axe_x && j < axe_y)
				color = 0x00FF0000;
			else if (i > axe_x && j < axe_y)
				color = 0x0000FF00;
			else if (i > axe_x && j > axe_y)
				color = 0x000000FF;
			else if (i < axe_x && j > axe_y)
				color = 0x00FF00FF;
			img_pixel_put(w->img, i, j, color);
			j++;
		}
		i++;
	}
}

void	axe_xy(t_window *w, int axe_x, int axe_y, int i)
{
	int	color;

	color = 0x00FFFFFF;
	while (i != w->len_y)
	{
		img_pixel_put(w->img, axe_x, i, color);
		img_pixel_put(w->img, axe_x + 1, i, color);
		img_pixel_put(w->img, axe_x - 1, i, color);
		i++;
	}
	i = 0;
	color = 0;
	while (i != w->len_x)
	{
		img_pixel_put(w->img, i, axe_y - 1, color);
		img_pixel_put(w->img, i, axe_y + 1, color);
		img_pixel_put(w->img, i, axe_y, color);
		i++;
	}
}

int	creat_mystere_fractal(t_window *w)
{
	int axe_x;
	int	axe_y;

	axe_y = w->len_y / 2;
	axe_x = w->len_x / 2;
	color4(w, axe_x, axe_y, 0);
	axe_xy(w, axe_x, axe_y, 0);
	return (0);
}
