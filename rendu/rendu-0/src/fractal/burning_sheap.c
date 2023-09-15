/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_sheap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:04:36 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/15 17:17:59 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

int	calcul_de_suite_burning_sheap(t_window *w, t_point z0, t_point c)
{
	float	tmpx;
	float	tmpy;

	while ((z0.x * z0.x + z0.y * z0.y) < 4 && z0.iteration < w->plan->n_max)
	{
		tmpx = z0.x;
		tmpy = z0.y;
		if (tmpy > 0)
			tmpy *= -1;
		if (tmpx < 0)
			tmpx *= -1;
		z0.x = tmpx * tmpx - tmpy * tmpy + c.x;
		z0.y = 2 * tmpx * tmpy + c.y;
		if (z0.x == tmpx && z0.y == tmpy)
			return (w->plan->n_max);
		z0.iteration++;
	}
	return (z0.iteration);
}

void	ft_burning_sheap(t_window *w, int i, int j)
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
	z0.iteration = calcul_de_suite_burning_sheap(w, z0, c);
	put_color(w, i, j, z0.iteration);
}

void	camera_burning_sheap(t_plan *p)
{
	p->xmin = -1.25;
	p->xmax = 1.25;
	p->ymin = -1.25;
	p->ymax = 1.25;
}

void	creat_burning_sheap_fractal(void *w_c)
{
	t_window	*w;

	w = (t_window *) w_c;
	camera_burning_sheap(w->plan);
	for_each_pixel(w, ft_burning_sheap);
}
