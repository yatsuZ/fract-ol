/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:45 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/14 15:05:40 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fract_ol.h"

/*
TO DO :
	PARTIE		GRAPHIQUE | X
	PARTIE		FRACTAL   | X
*/

void	img_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int degrader_de_couleur(int x, int y, int width, int height)
{
	int color;

	if (width < 0)
		width = width * -1;
	if (height < 0)
		height = height * -1;
	color = (x * 255) / width + ((((width - x) * 255) / width) << 16) + ((( y * 255) / height) << 8);
    return (color);
}

void	only_degrader(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->len_y > y)
	{
		x = -1;
		while (data->len_x > ++x)
			img_pixel_put(data, x, y, degrader_de_couleur(x, y, data->len_x, data->len_y));
		y++;
	}
}

int	main(void)
{
	t_data	*data;

	ft_printf("--DEBUT--\n");
	data = cree_fenetre("TEST", 500, 500);
	if (!data)
		return (1);
	add_event(data);
	only_degrader(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
	return (free_data(data), ft_printf("-- FIN --\n"), 0);
}
