/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:07:56 by yassine           #+#    #+#             */
/*   Updated: 2023/09/14 14:49:10 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	put_color(t_window *w, int i, int j, int n)
{
	int	color;
	int	color_s;

	color_s = 0x0000FF;
	if (w->color == 1 || w->color == 5)
		color_s = color_s * 255;
	else if (w->color == 2 || w->color == 6)
		color_s = color_s * 255 * 255;
	else if (w->color == 3 || w->color == 7)
		color_s = color_s * 255 * 255 * 255;
	color = (color_s / w->plan->n_max) * n;
	if (w->plan->n_max == n)
		color = 0;
	while (n-- > 0 && w->color >= 4 && color)
		color = color * 21;
	img_pixel_put(w->img, i, j, color);
}

void	ft_change_color(t_window *w)
{
	w->color = w->color + 1;
	if (w->color == 8)
		w->color = 0;
	change_img(w, w->plan->f_fractal);
}

// Modifier le parsingf 
// Faire une derniere fractal