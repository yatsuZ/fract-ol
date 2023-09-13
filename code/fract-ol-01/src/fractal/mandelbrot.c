/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:32:00 by yassine           #+#    #+#             */
/*   Updated: 2023/09/13 15:33:25 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	ft_mandelbrot(t_window *w, int i, int j)
{
	t_point	c;
	t_point	z0;

	c.x = ((float)(i - w->len_x / 2) / w->plan->unite) \
	* (w->plan->xmax - w->plan->xmin) \
	* w->plan->zoom + w->plan->x_decallage - 0.5;
	c.y = ((float)(w->len_y / 2 - j) / w->plan->unite) \
	* (w->plan->ymax - w->plan->ymin) \
	* w->plan->zoom + w->plan->y_decallage - 0.1;
	c.iteration = 0;
	z0.x = 0;
	z0.y = 0;
	z0.iteration = 0;
	z0.iteration = calcul_de_suite(w, z0, c);
	put_color(w, i, j, z0.iteration);
}

void	camera_mandelbrot(t_plan *p)
{
	p->xmin = -1.25;
	p->xmax = 1.25;
	p->ymin = -1.25;
	p->ymax = 1.25;
}

void	creat_mandelbrot_fractal(void *w_c)
{
	t_window	*w;

	w = (t_window *) w_c;
	camera_mandelbrot(w->plan);
	for_each_pixel(w, ft_mandelbrot);
}