/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:27:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/07 15:51:53 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

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

//Si titre est dans la HEAP je dois 
//free bref sa depend a verifier pour plus tard
t_window	*free_win(t_window *w)
{
	free_img(w, w->img);
	if (w->mlx_ptr && w->win_ptr)
		mlx_destroy_window(w->mlx_ptr, w->win_ptr);
	if (w->mlx_ptr)
	{
		mlx_destroy_display(w->mlx_ptr);
		free(w->mlx_ptr);
	}
	w->len_x = 0;
	w->len_y = 0;
	w->titre = NULL;
	w->win_ptr = NULL;
	w->mlx_ptr = NULL;
	free(w);
	w = NULL;
	return (NULL);
}

t_window	*ft_init_window(char *nom)
{
	t_window	*w;

	w = ft_calloc(1, sizeof(t_window));
	if (!w)
		return ((free(w)), NULL);
	w->titre = nom;
	w->mlx_ptr = mlx_init();
	if (!w->mlx_ptr)
		return (free_win(w));
	mlx_get_screen_size(w->mlx_ptr, &w->len_x, &(w->len_y));
	if (ft_init_img(w))
		return (free_win(w));
	w->win_ptr = mlx_new_window(w->mlx_ptr, w->len_x, w->len_y, w->titre);
	if (!w->win_ptr)
		return (free_win(w));
	return (w);
}

int	change_img(t_window *w, void (*f)(t_window *))
{
	free_img(w, w->img);
	if (ft_init_img(w))
		return (1);
	return (f(w), mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, \
	w->img->img_ptr, 0, 0), 0);
}
