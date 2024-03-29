/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:39:25 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/07 15:57:12 by yzaoui           ###   ########.fr       */
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
		if (ft_change_geometrie(w, w->fractal - 1))
			return (mlx_loop_end(w->mlx_ptr), 1);
	}
	else if (key == RIGHT)
	{
		ft_printf("→");
		if (ft_change_geometrie(w, w->fractal + 1))
			return (mlx_loop_end(w->mlx_ptr), 1);

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
	(void) w_v;
	ft_printf("EVENT Button Release\t| X |\t");
	if (button == LEFT_MOUSSE)
		ft_printf(" | click Gauche\t\t|");
	else if (button == MOLETTE)
		ft_printf(" | click Molette\t|");
	else if (button == TOP_MOLETTE)
		ft_printf(" | rouleument Haut\t|");
	else if (button == BOT_MOLETTE)
		ft_printf(" | rouleument Bas\t|");
	else if (button == RIGHT_MOUSSE)
		ft_printf(" | click Droit\t\t|");
	else
		ft_printf("| JSP\t\t\t\t|");
	ft_printf(" X = %d, Y = %d\n", x, y);
	return (0);
}

void	ft_add_event(t_window *w)
{
	mlx_hook(w->win_ptr, KEYPRESS, KEYPRESSMASK, ft_press_key, w);
	mlx_hook(w->win_ptr, DESTROYNOTIF_X, PAS_DE_MASQUE, ft_close_with_x, w);
	mlx_hook(w->win_ptr, CLICK_MOUSSE, CLICK_MOUSSE_MASK, ft_mousse_click, w);
}
