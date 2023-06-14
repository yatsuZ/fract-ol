/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:09:49 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/14 17:10:57 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fract_ol.h"

void	data_NULL(t_data *data)
{
	data->len_x = 0;
	data->len_y = 0;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->titre = NULL;
	data->addr = NULL;
	data->img = NULL;
	data->titre = NULL;
	data->win_ptr = NULL;
	data->mlx_ptr = NULL;
	free(data);
	data = NULL;
}

// free(data->titre); 
// SI le titre est dans la heap je free sinon je ne la free pas
t_data	*free_data(t_data *data)
{
	if (data->mlx_ptr && data->img)
		mlx_destroy_image(data->mlx_ptr, data->img);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	data_NULL(data);
	return (NULL);
}

t_data	*cree_fenetre(char *titre_fenetre, int len_x, int len_y)
{
	(void) len_x;
	(void) len_y;
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (free(data), NULL);
	data->titre = titre_fenetre;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free_data(data));
	mlx_get_screen_size(data->mlx_ptr, &data->len_x, &(data->len_y));
	ft_printf("%d\n%d\n", data->len_x, data->len_y);
	data->img = mlx_new_image(data->mlx_ptr, data->len_x, data->len_y);
	if (!data->img)
		return (free_data(data));
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	data->win_ptr = \
	mlx_new_window(data->mlx_ptr, data->len_x, data->len_y, data->titre);
	if (!data->win_ptr)
		return (free_data(data));
	return (data);
}
