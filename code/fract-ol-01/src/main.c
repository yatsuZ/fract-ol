/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:12:38 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/01 21:11:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	main(int argc, char **argv)
{
	t_window	*window;
	int			param;

	ft_printf("Hello World\n");
	param = ft_parsing(argc, argv);
	if (!param)
		return (0);
	window = ft_init_window(argv[1]);
	if (!window)
		return (0);
	ft_add_event(window);
	mlx_loop(window->mlx_ptr);
	return (window = free_win(window), 0);
}
