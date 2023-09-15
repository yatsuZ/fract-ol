/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:44:18 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/15 19:01:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	ft_zoom(t_plan *p, int sens)
{
	float	unite;

	unite = 1.10;
	if (sens == -1)
		unite = 0.90;
	p->zoom *= unite;
}

void	ft_zoom_key(t_window *w, int sens)
{
	ft_zoom(w->plan, sens);
	change_img(w, w->plan->f_fractal);
}
