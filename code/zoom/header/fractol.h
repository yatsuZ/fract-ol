/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:13:02 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/10 16:10:10 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./struct.h"

// Toute les fonction que je compte utilise
t_window	*ft_init_window(char *nom);
t_window	*free_win(t_window *w);
void		ft_add_event(t_window *w);
int			ft_parsing(int argc, char **argv);
void		img_pixel_put(t_img *img, int x, int y, int color);
int			change_img(t_window *w, void (*f)(t_window *));
int			creat_mystere_fractal(t_window *w);
void		ft_cree_plan(t_window *w);

#endif