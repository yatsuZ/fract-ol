/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:45:37 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/14 18:33:14 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

int	ft_init_img(t_window *w)
{
	w->img = ft_calloc(1, sizeof(t_img));
	if (w->img == NULL)
		return (1);
	w->img->img_ptr = mlx_new_image(w->mlx_ptr, w->len_x, w->len_y);
	if (!w->img->img_ptr)
		return (1);
	w->img->addr = mlx_get_data_addr(w->img->img_ptr, \
	&w->img->bits_per_pixel, &w->img->line_length, &w->img->endian);
	if (!w->img->addr)
		return (1);
	return (0);
}

void	free_img(t_window *w, t_img *img)
{
	if (img == NULL)
		return ;
	img->img_x = 0;
	img->img_y = 0;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	mlx_destroy_image(w->mlx_ptr, img->img_ptr);
	img->img_ptr = NULL;
	free(w->img);
	w->img = NULL;
}

int	change_img(t_window *w, void (*f)(void *))
{
	free_img(w, w->img);
	if (ft_init_img(w))
		return (1);
	return (f(w), mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, \
	w->img->img_ptr, 0, 0), 0);
}
