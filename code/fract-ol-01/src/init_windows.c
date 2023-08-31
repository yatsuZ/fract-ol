/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:27:57 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/01 01:35:40 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

//Si titre est dans la HEAP je dois free bref sa depend a verifier pour plus tard
t_window	*free_win(t_window *w)
{
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

t_window	*ft_init_window(char *nom){
	t_window	*win;

	win = ft_calloc(1, sizeof(t_window));
	if (!win)
		return ((free(win)), NULL);
	win->titre = nom;
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (free_win(win));
	mlx_get_screen_size(win->mlx_ptr, &win->len_x, &(win->len_y));
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->len_x, win->len_y, win->titre);
	if (!win->win_ptr)
		return (free_win(win));
	return (win);
}