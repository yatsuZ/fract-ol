/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:57:03 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/12 00:59:49 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/fract_ol.h"


int	close_with_x(t_data *data)
{
	ft_printf("Fermer avec la souris avec X !\n");
	mlx_loop_end(data->mlx_ptr);
	return (0);
}
int	souris_deplacement(int x,int y, t_data *data)
{
	ft_printf("Mouse moving in %s, at %dx%d.\n", data->titre, x, y);
	return (0);
}

int	deal_key(int key, void *data_v)
{
	t_data	*data;

	data = (t_data *) data_v;
	if (key == ESC)
	{
		ft_printf("Fermer avec ESC le clavier !\n");
		mlx_loop_end(data->mlx_ptr);
	}
	return (0);
}

int	deal_key_release(int key, void *data_v)
{
	(void)	data_v;

	ft_printf("La touche %c à etais relacher\n", key);
	return (0);
}

int testButtonPress(int button, int x, int y, void *data_v)
{
	(void)	data_v;

	ft_printf("EVENT Button presse \t| O |\t");
	if (button == 1)
		ft_printf(" | click Gauche\t\t|");
	else if (button == 2)
		ft_printf(" | click Molette\t|");
	else if (button == 4)
		ft_printf(" | rouleument Haut\t|");
	else if (button == 5)
		ft_printf(" | rouleument Bas\t|");
	else if (button == 3)
		ft_printf(" | click Droit\t\t|");
	else
		ft_printf("| JSP\t\t\t\t|");
	ft_printf(" X = %d, Y = %d\n", x, y);
	return (0);
}

int testButtonRelease(int button, int x, int y, void *data_v)
{
	(void)	data_v;

	ft_printf("EVENT Button Release\t| X |\t");
	if (button == 1)
		ft_printf(" | click Gauche\t\t|");
	else if (button == 2)
		ft_printf(" | click Molette\t|");
	else if (button == 4)
		ft_printf(" | rouleument Haut\t|");
	else if (button == 5)
		ft_printf(" | rouleument Bas\t|");
	else if (button == 3)
		ft_printf(" | click Droit\t\t|");
	else
		ft_printf("| JSP\t\t\t\t|");
	ft_printf(" X = %d, Y = %d\n", x, y);
	return (0);
}

int test_motionNotify(int x, int y, void *data_v) {
	// Convertir data_v en pointeur vers votre structure de données appropriée (t_data)
	(void)	data_v;
	(void)	x;
	(void)	y;

	ft_printf("La souris se deplace\n");
	return 0;
}

int	testEnternotify(int x, int y, void *data_v)
{
	(void)	data_v;
	(void)	x;
	(void)	y;

	ft_printf("\n\n\n!!! La souris viens de rentrée OU DE SORTIR ? de la fentre !!!!!\n");
	return (0);
}

int	testLeaveNotify(int x, int y, void *data_v)
{
	(void) data_v;
	(void)	x;
	(void)	y;
	
	ft_printf("La souris a quitté la fenêtre à la position (%d, %d)\n", x, y);
	// Faites ce que vous voulez avec les coordonnées x et y
	
	return (0);
}


void	add_event(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, deal_key, data);						// Quand jeppuie sur une touche
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, deal_key_release, data);			// Quand je relache la touche // JE oeux changer le mask
	// mlx_key_hook(data->win_ptr, deal_key, data);// fusion des deux
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, testButtonPress, data);			// Quand jappuye avec la souris
	mlx_hook(data->win_ptr, ButtonRelease, ButtonReleaseMask, testButtonRelease, data);		// Quand je relache avec la souris sur la fenetre
	mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask, test_motionNotify, data);		// quand la souris se deplace dans la fenetre
	mlx_hook(data->win_ptr, EnterNotify, EnterWindowMask, testEnternotify, data);			// quand la souris rentre ou sort de la fenetre
	mlx_hook(data->win_ptr, LeaveNotify, LeaveWindowMask, testLeaveNotify, data);			// quand la souris sort de la fenetre
	// mlx_hook(data->win_ptr, X_ON_EVENT, NO_MASK_EVENT, close_with_x, data);
	// mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask, souris_deplacement, data);
}
