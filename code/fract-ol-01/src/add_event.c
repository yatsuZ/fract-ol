/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:39:25 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/13 04:08:08 by yatsu            ###   ########.fr       */
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
	{
		ft_printf("←");
	}
	else if (key == RIGHT)
	{
		ft_printf("→");
	}
	else if (key == TOP)
		ft_printf("↑");
	else if (key == BOT)
		ft_printf("↓");
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
	if (button == LEFT_MOUSSE || button == TOP_MOLETTE \
	|| button == BOT_MOLETTE)
		ft_deplacement(w, x, y);
	if (button == TOP_MOLETTE)
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
