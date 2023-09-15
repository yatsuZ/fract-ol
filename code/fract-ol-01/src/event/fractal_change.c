/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:51:53 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/15 18:03:45 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

void	ft_change_fractal(t_window *w)
{
	w->id_fractal += 1;
	if (w->id_fractal == 4)
		w->id_fractal = 1;
	if (w->id_fractal == 1)
		w->plan->f_fractal = creat_julia_fractal;
	else if (w->id_fractal == 2)
		w->plan->f_fractal = creat_mandelbrot_fractal;
	else if (w->id_fractal == 3)
		w->plan->f_fractal = creat_burning_sheap_fractal;
	change_img(w, w->plan->f_fractal);
}
