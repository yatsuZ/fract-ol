/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:12:38 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/01 01:35:46 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	main(void)
{
	t_window	*window;
	ft_printf("Hello World\n");
	window = ft_init_window("Test");
	if (!window)
		return(ft_printf("Window est null."), 0);
	ft_printf("nom de la fenetre : %s\nlonguer absisce : %d\nlonguer ordonée : %d\nmlx_ptr= %p\nwin_ptr = %p\n", window->titre, window->len_x, window->len_y, window->mlx_ptr, window->win_ptr);
	window = free_win(window);
	return (0);
}
