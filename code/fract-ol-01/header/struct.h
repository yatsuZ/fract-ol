/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:15:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/06 18:21:08 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "./lib_import.h"

// je definie mes structure ici.
typedef struct s_img
{
	void	*img_ptr;
	int		img_x;
	int		img_y;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*titre;
	int		len_x;
	int		len_y;
	int		fractal;
	int		color;
	t_img	*img;
}	t_window;

#endif