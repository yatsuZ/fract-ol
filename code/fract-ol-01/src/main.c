/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:12:38 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/06 19:36:11 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_window	*window;
	int			param;

	param = ft_parsing(argc, argv);
	if (!param)
		return (0);
	window = ft_init_window(argv[1]);
	window->fractal = param % 10;
	window->color = param / 10;
	if (!window)
		return (0);
	blue_square(window);
	draw_yellow_circle(window);
	green_triangle(window);
	ft_add_event(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, \
	window->img->img_ptr, 0, 0);
	mlx_loop(window->mlx_ptr);
	return (window = free_win(window), 0);
}
