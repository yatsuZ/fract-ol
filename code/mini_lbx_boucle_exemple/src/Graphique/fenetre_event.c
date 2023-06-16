/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:57:03 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/16 16:15:17 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fract_ol.h"

////////////////////////////////////////

int	deal_key(int key, void *data_v)
{
	t_data	*data;

	data = (t_data *) data_v;
	if (key == ESC)
	{
		ft_printf("Fermer avec ESC le clavier !\n");
		mlx_loop_end(data->mlx_ptr);
		return (0);
	}
	else if (key == 65361)
		data->img_x = data->img_x - 10;
	else if (key == 65362)
		data->img_y = data->img_y - 10;
	else if (key == 65363)
		data->img_x = data->img_x + 10;
	else if (key == 65364)
		data->img_y = data->img_y + 10;
	return (0);
}

int	close_with_x(t_data *data)
{
	ft_printf("Fermer avec la souris avec X !\n");
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int testButtonPress(int button, int x, int y, void *data_v)
{
	(void)	data_v;

	ft_printf("EVENT Button Release\t| X |\t");
	if (button == 1)
		ft_printf(" | click Gauche\t\t|");
	else if (button == 2)
		ft_printf(" | click Molette\t|");
	else if (button == 4)
		ft_printf(" | rouleument Haut\t|");
	else if (button == 5)
		ft_printf(" | rouleument Bas\t|");
	else if (button == 3)
		ft_printf(" | click Droit\t\t|");
	else
		ft_printf("| JSP\t\t\t\t|");
	ft_printf(" X = %d, Y = %d\n", x, y);
	return (0);
}

void	add_event(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, deal_key, data);						// Quand jeppuie sur une touche
	mlx_hook(data->win_ptr, DestroyNotify, NO_MASK_EVENT, close_with_x, data);
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, testButtonPress, data);		// Quand je relache avec la souris sur la fenetre
}
