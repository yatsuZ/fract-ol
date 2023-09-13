/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:07:56 by yassine           #+#    #+#             */
/*   Updated: 2023/09/13 18:29:13 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	put_color(t_window *w, int i, int j, int n)
{
	int	color;

	color = 7;
	while (n > 0)
	{
		color = color * 2 ;
		n--;
	}
	if (w->plan->n_max == n)
		img_pixel_put(w->img, i, j, 0);
	else
	{
		img_pixel_put(w->img, i, j, color);
	}
}
// 0x00FFFFFF
// Choisir la coulleur