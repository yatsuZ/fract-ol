/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 03:14:21 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/14 17:46:54 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	ft_deplacement(t_window *w, int i, int j)
{
	t_plan	*p;
	float	x;
	float	y;

	p = w->plan;
	x = i - w->len_x / 2;
	y = j - w->len_y / 2;
	p->x_decallage += (x / p->unite) * (p->xmax - p->xmin) * p->zoom;
	p->y_decallage -= (y / p->unite) * (p->ymax - p->ymin) * p->zoom;
}

void	ft_deplacement_fleche(t_window *w, int direction)
{
	t_plan	*p;
	float	x;
	float	y;

	p = w->plan;
	x = w->len_x / 10 - w->len_x / 2;
	y = w->len_y / 10 - w->len_y / 2;
	if (direction == 1)
		p->x_decallage += (x / p->unite) * (p->xmax - p->xmin) * p->zoom;
	if (direction == 2)
		p->x_decallage -= (x / p->unite) * (p->xmax - p->xmin) * p->zoom;
	if (direction == 3)
		p->y_decallage -= (y / p->unite) * (p->ymax - p->ymin) * p->zoom;
	if (direction == 4)
		p->y_decallage += (y / p->unite) * (p->ymax - p->ymin) * p->zoom;
	change_img(w, w->plan->f_fractal);
}
