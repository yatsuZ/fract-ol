/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:57:03 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/08 13:37:11 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fract_ol.h"

int	deal_key(int key, void *data_v)
{
	t_data_mlx *data;

	data = (t_data_mlx *) data_v;
	if (key == 65307)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

void	add_event(t_data_mlx *data)
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 250, 250, 0xFFFFFFFF);
	mlx_key_hook(data->win_ptr, deal_key, data);
}