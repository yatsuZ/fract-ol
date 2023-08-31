/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:12:38 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/01 01:38:45 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	main(void)
{
	t_window	*window;

	ft_printf("Hello World\n");
	window = ft_init_window("Test");
	if (!window)
		return (0);
	return (window = free_win(window), 0);
}
