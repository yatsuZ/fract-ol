/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:47:28 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/13 15:08:31 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	img_pixel_put(t_img *img, int i, int j, int color)
{
	char	*dst;

	dst = img->addr + (j * img->line_length + i * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	for_each_pixel(t_window *w, void (*f)(t_window *w, int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < w->len_x)
	{
		j = 0;
		while (j < w->len_y)
		{
			f(w, i, j);
			j++;
		}
		i++;
	}
}
