/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:15:30 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/13 03:55:40 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "./lib_import.h"

// je definie mes structure ici.

typedef struct s_point
{
	float	x;
	float	y;
	int		iteration;
}	t_point;

typedef struct s_plan
{
	void	(*f_fractal)(void *);
	int		n_max;
	float	unite;
	float	xmin;
	float	xmax;
	float	ymin;
	float	ymax;
	float	zoom;
	float	x_decallage;
	float	y_decallage;
}	t_plan;

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
	int		id_fractal;
	int		color;
	t_plan	*plan;
	t_img	*img;
}	t_window;

#endif