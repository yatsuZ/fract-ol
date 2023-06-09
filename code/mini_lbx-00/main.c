/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:38:45 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/06 16:45:14 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

void	free_mlx_and_win_ptr(void *mlx_ptr, void *win_ptr)
{
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	win_ptr = NULL;
	mlx_ptr = NULL;
}

int	deal_key(char *key, void *param)
{
	write(1, &key, 1);
	write(1, "\n", 1);
	mlx_loop_end(param);
	return (0);
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "HELLO WORLD");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFFFF);
	mlx_key_hook(win_ptr, deal_key, mlx_ptr);
	mlx_loop(mlx_ptr);
	free_mlx_and_win_ptr(mlx_ptr, win_ptr);
	return 0;
}
// compillation :
// cc -g3 -I ./minilibx-linux main.c -L ./minilibx-linux -lmlx -lXext -lX11 -lm
