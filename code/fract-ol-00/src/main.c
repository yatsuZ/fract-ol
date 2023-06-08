/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:45 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/08 13:08:51 by yatsu            ###   ########.fr       */
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
	t_data_mlx	*data;

	data = cree_fenetre("TEST", 500, 500);
	if (!data)
		return (1);
	add_event(data);
	mlx_loop(data->mlx_ptr);
	return (free_data(data), 0);
}
