/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:09:20 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/11 01:49:39 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	color4(t_window *w, int i, int j)
{
	int	color;
	int	axe_x;
	int	axe_y;

	axe_x = w->len_x / 2;
	axe_y = w->len_y / 2;
	color = 255;
	if (i < axe_x)
		color = color * color * color * color;
	if (j < axe_y)
		color += color * color * color;
	img_pixel_put(w->img, i, j, color);
}

void	all_white(t_window *w, int i, int j)
{
	img_pixel_put(w->img, i, j, 0xFFFFFFFF);
}

void	for_each_pixel(t_window *w, void (*f)(t_window *w, int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < w->len_x)
	{
		j = 0;
		while (j < w->len_y)
		{
			f(w, i, j);
			j++;
		}
		i++;
	}
}

void	ft_init_camera(t_camera *c)
{
	c->xmin = -10;
	c->xmax = 10;
	c->ymin = -10;
	c->ymax = 10;
}


/////////////////////////////
#include <stdio.h>

int	draw_unite(t_window *w, int xf, int yf)
{
	float	xmax;
	float	ymax;
	float	xmin;
	float	ymin;
	float	x;
	float	y;

	xmax = 10;
	ymax = 10;
	xmin = -10;
	ymin = -10;
	x = ((float)xf / (float)w->len_x) * (xmax - xmin) * w->camera->zoom + w->camera->x_decallage;// * w->camera->zoom ;
	y = ((float)yf / (float)w->len_y) * (ymax - ymin) * w->camera->zoom + w->camera->y_decallage;// * w->camera->zoom ;
	// printf("x = %f\n", x);
	if ((x <= 0.05 && x >= -0.05 ) || (y <= 0.05 && y >= -0.05 ))
		return (1);
	if (x >= 1 && x <= 2 && y >= 1 && y <= 2)
		return (2);
	if ((y - (int) y<= 0.05 && y - (int) y>= -0.05 ) && (x <= 0.5 && x >= -0.5 ))
		return (3);
	if ((x - (int) x<= 0.05 && x - (int) x>= -0.05 ) && (y<= 0.5 && y>= -0.5 ))
		return (4);
	return (0);
}

void	ft_repere_orthonorme(t_window *w, int i, int j)
{
	int	x_de_la_fenetre;
	int	y_de_la_fenetre;
	int	r;

	x_de_la_fenetre = i - w->len_x / 2;
	y_de_la_fenetre = w->len_y / 2 - j;
	r = draw_unite(w, x_de_la_fenetre, y_de_la_fenetre);
	if(!x_de_la_fenetre || !y_de_la_fenetre)
		img_pixel_put(w->img, i, j, 0);
	if (r == 1)
		img_pixel_put(w->img, i, j, 0x00FF0000);
	else if (r == 2)
		img_pixel_put(w->img, i, j, 0x0000FF00);
	else if (r == 3)
		img_pixel_put(w->img, i, j, 0x00000FFF);
	else if (r == 4)
		img_pixel_put(w->img, i, j, 0x00785125);
}
////////////////////

void	ft_cree_plan(t_window *w)
{
	ft_init_camera(w->camera);
	for_each_pixel(w, all_white);
	for_each_pixel(w, ft_repere_orthonorme);
}
