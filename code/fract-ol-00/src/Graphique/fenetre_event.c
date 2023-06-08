/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:57:03 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/08 19:45:05 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fract_ol.h"

int	deal_key(int key, void *data_v)
{
	t_data	*data;

	data = (t_data *) data_v;
	if (key == ESC)
	{
		ft_printf("Fermer avec ESC le clavier !\n");
		mlx_loop_end(data->mlx_ptr);
	}
	return (0);
}

int	close_with_x(t_data *data)
{
	ft_printf("Fermer avec la souris avec X !\n");
	mlx_loop_end(data->mlx_ptr);
	return (0);
}
void	add_event(t_data *data)
{
	mlx_hook(data->win_ptr, X_ON_EVENT, \
	NO_MASK_EVENT, close_with_x, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
}
