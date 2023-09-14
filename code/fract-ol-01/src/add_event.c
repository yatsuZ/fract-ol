/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:39:25 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/14 17:59:54 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	ft_press_key(int key, void *w_v)
{
	t_window	*w;

	w = (t_window *) w_v;
	if (w == NULL)
		return (1);
	if (key == ESC)
		mlx_loop_end(w->mlx_ptr);
	else if (key == LEFT)
		ft_deplacement_fleche(w, 1);
	else if (key == RIGHT)
		ft_deplacement_fleche(w, 2);
	else if (key == TOP)
		ft_deplacement_fleche(w, 3);
	else if (key == BOT)
		ft_deplacement_fleche(w, 4);
	else if (key == KEY_C)
		ft_change_color(w);
	else if (key == KEY_F)
		ft_change_fractal(w);
	ft_printf("%d\n", key);
	return (0);
}

int	ft_close_with_x(void *w_v)
{
	t_window	*w;

	w = (t_window *) w_v;
	if (w == NULL)
		return (1);
	ft_printf("Fermer avec la souris avec X !\n");
	return (mlx_loop_end(w->mlx_ptr), 0);
}

int	ft_mousse_click(int button, int x, int y, void *w_v)
{
	t_window	*w;

	w = (t_window *) w_v;
	if (button == LEFT_MOUSSE)
		ft_deplacement(w, x, y);
	else if (button == TOP_MOLETTE)
		ft_zoom(w->plan, -1);
	else if (button == BOT_MOLETTE)
		ft_zoom(w->plan, 1);
	else if (button == MOLETTE)
		reset_camera(w->plan);
	else if (button == RIGHT_MOUSSE)
		ft_printf(" | click Droit\t\t|");
	else
		ft_printf("| JSP\t\t\t\t|");
	change_img(w, w->plan->f_fractal);
	return (0);
}

void	ft_add_event(t_window *w)
{
	mlx_hook(w->win_ptr, KEYPRESS, KEYPRESSMASK, ft_press_key, w);
	mlx_hook(w->win_ptr, DESTROYNOTIF_X, PAS_DE_MASQUE, ft_close_with_x, w);
	mlx_hook(w->win_ptr, CLICK_MOUSSE, CLICK_MOUSSE_MASK, ft_mousse_click, w);
}
