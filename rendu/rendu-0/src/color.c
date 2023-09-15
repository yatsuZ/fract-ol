/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:07:56 by yassine           #+#    #+#             */
/*   Updated: 2023/09/15 18:17:13 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	black_white(t_window *w, int i, int j, int n)
{
	int	diverge;
	int	stable;

	diverge = 0xFFFFFF;
	stable = 0xFFFFFF;
	if (w->color == 8)
		stable = 0;
	else
		diverge = 0;
	if (w->plan->n_max == n)
		img_pixel_put(w->img, i, j, stable);
	else
		img_pixel_put(w->img, i, j, diverge);
}

void	put_color(t_window *w, int i, int j, int n)
{
	int	color;
	int	color_s;

	color_s = 0x0000FF;
	if (w->color > 7)
		return (black_white(w, i, j, n));
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
		color = color * 11;
	img_pixel_put(w->img, i, j, color);
}
