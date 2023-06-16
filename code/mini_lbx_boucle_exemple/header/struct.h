/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:19:41 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/16 00:37:07 by yatsu            ###   ########.fr       */
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
	int		img_x;
	int		img_y;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

#endif