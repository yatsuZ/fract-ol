/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:12:38 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/13 03:06:22 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	main(int argc, char **argv)
{
	t_window	*window;
	int			param;

	param = ft_parsing(argc, argv);
	if (!param)
		return (0);
	window = ft_init_window("FRACT-OL 42 BY YATSU", param % 10, param / 10);
	if (!window)
		return (0);
	ft_add_event(window);
	window->plan->f_fractal(window);
	ft_printf("FINI");
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, \
	window->img->img_ptr, 0, 0);
	mlx_loop(window->mlx_ptr);
	return (window = free_win(window), 0);
}
