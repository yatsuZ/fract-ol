/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystere.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:57:56 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/10 16:06:42 by yzaoui           ###   ########.fr       */
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
			else
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

int	calcul(int x, int y, int n, t_window *w)
{
	float	xc;
	float	yc;
	float		xn;
	float		yn;

	float		tmpx;
	float		tmpy;
	float		XMIN = -2;
	float		XMAX = 2; 
	float		YMIN = -2; 
	float		YMAX = 2;
	int	iter = 25;

	xc = ((float)x / (float)w->len_x) * (XMAX - XMIN) - 0.5;// - pour decaler la camere et multiplier pour zoome 
	yc = ((float)y / (float)w->len_y) * (YMAX - YMIN) - 0.5 ;
	if (xc == 0 || yc == 0)
		return (2);
	xn = 0;
	yn = 0;
	while ((xn * xn + yn * yn) < 4 && n < iter)
	{
		tmpx = xn;
		tmpy = yn;
		xn = tmpx * tmpx - tmpy * tmpy + xc;
		yn = 2 * tmpx * tmpy + yc;
		n++;
	}
	if (n == iter)
	{
		// ft_printf("%d\n", n);
		return (1);
	}
	return (0);
}


int	creat_mystere_fractal(t_window *w)
{
	int	i;
	int	j;
	int	x;  
	int	y;
	int	r;

	i = 0;
	while (i != w->len_x)
	{
		j = 0;
		while (j != w->len_y)
		{
			x = i - w->len_x / 2;
			y = j - w->len_y / 2;
			r = calcul(x, y, 0, w);
			if (!x || !y)
				img_pixel_put(w->img, i, j, 0x000000FF);
			else if (r == 1)
				img_pixel_put(w->img, i, j, 0x00FFFFFF);
			else if (r == 2)
				img_pixel_put(w->img, i, j, 0x0000FF00);
			else
				img_pixel_put(w->img, i, j, 0xFF000000);
			j++;
		}
		i++;
	}
	return (0);
}
