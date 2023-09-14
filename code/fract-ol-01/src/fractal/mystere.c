/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystere.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:57:56 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/14 01:27:26 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	ft_mystere(t_window *w, int i, int j)
{
	t_point	c;
	t_point	z0;

	z0.x = ((float)(i - w->len_x / 2) / w->plan->unite) \
	* (w->plan->xmax - w->plan->xmin) \
	* w->plan->zoom + w->plan->x_decallage;
	z0.y = ((float)(w->len_y / 2 - j) / w->plan->unite) \
	* (w->plan->ymax - w->plan->ymin) \
	* w->plan->zoom + w->plan->y_decallage;
	z0.iteration = 0;
	c.x = -0.29436;
	c.y = -0.76214;
	c.iteration = 0;
	z0.iteration = calcul_de_suite(w, z0, c);
	put_color(w, i, j, z0.iteration);
}

void	camera_mystere(t_plan *p)
{
	p->xmin = -2;
	p->xmax = 2;
	p->ymin = -2;
	p->ymax = 2;
}

void	creat_mystere_fractal(void *w_c)
{
	t_window	*w;

	w = (t_window *) w_c;
	camera_mystere(w->plan);
	for_each_pixel(w, ft_mystere);
}
