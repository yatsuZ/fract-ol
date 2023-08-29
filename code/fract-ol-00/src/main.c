/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:45 by yatsu             #+#    #+#             */
/*   Updated: 2023/08/29 15:26:58 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fract_ol.h"

/*
TO DO :
	PARTIE		GRAPHIQUE | X
	PARTIE		FRACTAL   | X
*/

int	main(void)
{
	t_data	*data;

	ft_printf("--DEBUT--\n");
	data = cree_fenetre("TEST", 500, 500);
	if (!data)
		return (1);
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->len_x / 2, data->len_y / 2, 0xFFFFFFFF);
	add_event(data);
	mlx_loop(data->mlx_ptr);
	return (free_data(data), ft_printf("-- FIN --\n"), 0);
}
