/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:39:18 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/08 13:07:28 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "./struct.h"

t_data_mlx	*cree_fenetre(char *titre_fenetre, int len_x, int len_y);
t_data_mlx	*free_data(t_data_mlx *data);
void		add_event(t_data_mlx *data);

#endif