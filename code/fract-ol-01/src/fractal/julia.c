/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:13:40 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/15 17:42:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	ft_julia(t_window *w, int i, int j)
{
	t_point	z0;

	z0.x = ((float)(i - w->len_x / 2) / w->plan->unite) \
	* (w->plan->xmax - w->plan->xmin) \
	* w->plan->zoom + w->plan->x_decallage;
	z0.y = ((float)(w->len_y / 2 - j) / w->plan->unite) \
	* (w->plan->ymax - w->plan->ymin) \
	* w->plan->zoom + w->plan->y_decallage;
	z0.iteration = 0;
	z0.iteration = calcul_de_suite(w, z0, *(w->plan->julia));
	put_color(w, i, j, z0.iteration);
}

void	camera_julia(t_plan *p)
{
	p->xmin = -2;
	p->xmax = 2;
	p->ymin = -2;
	p->ymax = 2;
}

void	creat_julia_fractal(void *w_c)
{
	t_window	*w;

	w = (t_window *) w_c;
	camera_julia(w->plan);
	printf("JULIA, %f\n%f \n\n", w->plan->julia->x, w->plan->julia->y);
	for_each_pixel(w, ft_julia);
}
