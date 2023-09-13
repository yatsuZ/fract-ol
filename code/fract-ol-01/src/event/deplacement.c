/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 03:14:21 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/13 04:07:45 by yatsu            ###   ########.fr       */
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
