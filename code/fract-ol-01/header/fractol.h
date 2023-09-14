/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:13:02 by yatsu             #+#    #+#             */
/*   Updated: 2023/09/14 23:19:47 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./struct.h"

// PARSING
int			ft_parsing(int argc, char **argv, t_point **julia);
int			get_param_julia(char *arg, t_point **j);

// INIT STRUCT
t_window	*ft_init_window(char *nom, int id_f, int color, t_point *julia);
t_window	*free_win(t_window *w);

int			ft_init_img(t_window *w);
void		free_img(t_window *w, t_img *img);

int			ft_init_plan(t_window *w, t_point *julia);
void		free_plan(t_plan *p);

void		reset_camera(t_plan *p);

// DESSINER
void		for_each_pixel(t_window *w, void (*f)(t_window *w, int, int));
void		img_pixel_put(t_img *img, int x, int y, int color);
void		put_color(t_window *w, int i, int j, int n);
void		ft_change_color(t_window *w);

// EVENT
void		ft_add_event(t_window *w);
int			change_img(t_window *w, void (*f)(void *));
void		ft_zoom(t_plan *p, int sens);
void		ft_deplacement(t_window *w, int i, int j);
void		ft_deplacement_fleche(t_window *w, int direction);
void		ft_change_fractal(t_window *w);

// FRACTAL
int			calcul_de_suite(t_window *w, t_point z0, t_point c);
void		creat_julia_fractal(void *w_v);
void		creat_mandelbrot_fractal(void *w_v);

#endif