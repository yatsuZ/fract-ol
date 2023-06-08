/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:19:41 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/08 12:38:01 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "./lib_import.h"

typedef struct s_data_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*titre;
	int		len_x;
	int		len_y;
}	t_data_mlx;

#endif