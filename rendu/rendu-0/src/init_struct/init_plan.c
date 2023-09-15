/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:04:55 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/15 19:32:05 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	reset_camera(t_plan *p)
{
	p->zoom = 1;
	p->x_decallage = 0;
	p->y_decallage = 0;
}

int	ft_init_plan(t_window *w, t_point *j)
{
	w->plan = ft_calloc(1, sizeof(t_plan));
	if (w->plan == NULL)
		return (1);
	if (w->id_fractal == 1)
		w->plan->f_fractal = creat_julia_fractal;
	else if (w->id_fractal == 2)
		w->plan->f_fractal = creat_mandelbrot_fractal;
	else if (w->id_fractal == 3)
		w->plan->f_fractal = creat_burning_sheap_fractal;
	else
		return (1);
	w->plan->julia = j;
	w->plan->unite = w->len_x;
	if (w->len_x > w->len_y)
		w->plan->unite = w->len_y;
	w->plan->n_max = 225;
	reset_camera(w->plan);
	return (0);
}

void	free_plan(t_plan *p)
{
	if (p == NULL)
		return ;
	if (p->julia)
		free(p->julia);
	p->julia = 0;
	p->f_fractal = NULL;
	p->unite = 0;
	p->xmin = 0;
	p->xmax = 0;
	p->ymin = 0;
	p->ymax = 0;
	p->zoom = 0;
	p->x_decallage = 0;
	p->y_decallage = 0;
	free(p);
	p = NULL;
}

int	calcul_de_suite(t_window *w, t_point z0, t_point c)
{
	float	tmpx;
	float	tmpy;

	while (z0.x * z0.x + z0.y * z0.y < 4 && z0.iteration < w->plan->n_max)
	{
		tmpx = z0.x;
		tmpy = z0.y;
		z0.x = tmpx * tmpx - tmpy * tmpy + c.x;
		z0.y = 2 * tmpx * tmpy + c.y;
		if (z0.x == tmpx && z0.y == tmpy)
			return (w->plan->n_max);
		z0.iteration++;
	}
	return (z0.iteration);
}
