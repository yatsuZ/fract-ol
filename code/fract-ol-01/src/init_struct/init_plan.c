/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:04:55 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/14 12:47:21 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	reset_camera(t_plan *p)
{
	p->zoom = 1;
	p->x_decallage = 0;
	p->y_decallage = 0;
}

//modifier pour la selection des f est couleur
int	ft_init_plan(t_window *w)
{
	w->plan = ft_calloc(1, sizeof(t_plan));
	if (w->plan == NULL)
		return (1);
	if (w->id_fractal == 3)
		w->plan->f_fractal = creat_mystere_fractal;
	else if (w->id_fractal == 2)
		w->plan->f_fractal = creat_mandelbrot_fractal;
	else
		return (1);
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

float	carre(float x)
{
	return (x * x);
}

int	calcul_de_suite(t_window *w, t_point z0, t_point c)
{
	float	tmpx;
	float	tmpy;

	while ((carre(z0.x) + carre(z0.y)) < 4 \
	&& z0.iteration < w->plan->n_max)
	{
		tmpx = z0.x;
		tmpy = z0.y;
		z0.x = carre(tmpx) - carre(tmpy) + c.x;
		z0.y = 2 * tmpx * tmpy + c.y;
		if (z0.x == tmpx && z0.y == tmpy)
			return (w->plan->n_max);
		z0.iteration++;
	}
	return (z0.iteration);
}
