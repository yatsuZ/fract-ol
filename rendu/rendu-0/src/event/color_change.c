/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:35:40 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/14 23:09:57 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	ft_change_color(t_window *w)
{
	w->color = w->color + 1;
	if (w->color == 10)
		w->color = 0;
	change_img(w, w->plan->f_fractal);
}
