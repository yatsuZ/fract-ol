/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:27:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/15 19:29:38 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fractol.h"

t_window	*free_win(t_window *w)
{
	free_img(w, w->img);
	free_plan(w->plan);
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

t_window	*ft_init_window(char *nom, int id_f, int color, t_point *julia)
{
	t_window	*w;

	w = ft_calloc(1, sizeof(t_window));
	if (!w)
		return ((free(w)), NULL);
	w->titre = nom;
	w->id_fractal = id_f;
	w->color = color;
	w->mlx_ptr = mlx_init();
	if (!w->mlx_ptr)
		return (free_win(w));
	mlx_get_screen_size(w->mlx_ptr, &w->len_x, &(w->len_y));
	if (ft_init_img(w) || ft_init_plan(w, julia))
		return (free_win(w));
	w->win_ptr = mlx_new_window(w->mlx_ptr, w->len_x, w->len_y, w->titre);
	if (!w->win_ptr)
		return (free_win(w));
	return (w);
}
