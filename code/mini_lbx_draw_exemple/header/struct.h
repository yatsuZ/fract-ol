/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:19:41 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/09 19:55:20 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "./lib_import.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*titre;
	int		len_x;
	int		len_y;
}	t_data;

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

#endif