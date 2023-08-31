/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:13:02 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/01 01:35:53 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./struct.h"

// Toute les fonction que je compte utilise
t_window	*ft_init_window(char *nom);
t_window	*free_win(t_window *w);

#endif