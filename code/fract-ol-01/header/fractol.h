/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:13:02 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/13 15:34:46 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./struct.h"

// PARSING
int			ft_parsing(int argc, char **argv);

// INIT STRUCT
t_window	*ft_init_window(char *nom, int id_f, int color);
t_window	*free_win(t_window *w);

int			ft_init_img(t_window *w);
void		free_img(t_window *w, t_img *img);

int			ft_init_plan(t_window *w);
void		free_plan(t_plan *p);

void		reset_camera(t_plan *p);

// DESSINER
void		for_each_pixel(t_window *w, void (*f)(t_window *w, int, int));
void		img_pixel_put(t_img *img, int x, int y, int color);
void		put_color(t_window *w, int i, int j, int n);

// EVENT
void		ft_add_event(t_window *w);
int			change_img(t_window *w, void (*f)(void *));
void		ft_zoom(t_plan *p, int sens);
void		ft_deplacement(t_window *w, int i, int j);

// FRACTAL
int			calcul_de_suite(t_window *w, t_point z0, t_point c);
void		creat_mystere_fractal(void *w_v);
void		creat_mandelbrot_fractal(void *w_v);

#endif