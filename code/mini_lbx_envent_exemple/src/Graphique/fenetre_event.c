/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fenetre_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:57:03 by yatsu             #+#    #+#             */
/*   Updated: 2023/06/14 12:01:22 by yatsu            ###   ########.fr       */
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

int testFocusIn(void *data_v)
{
	(void) data_v;
    ft_printf("La fenêtre a obtenu le focus\n");
    // Faites ce que vous voulez lorsque la fenêtre obtient le focus
    return (0);
}

int testFocusOut(void *data_v)
{
	(void) data_v;
    ft_printf("La fenêtre a perdu le focus\n");
    // Faites ce que vous voulez lorsque la fenêtre perd le focus
    return (0);
}

int test_keymapNotify(void *data_v)
{
	(void) data_v;
    ft_printf("Modification de la table de mappage des touches du clavier\n");
    // Faites ce que vous voulez lorsque la table de mappage des touches est modifiée
    return (0);
}

int test_Expose(void *data_v)
{
	(void) data_v;
    
    ft_printf("La fenêtre a été exposée\n");
    // Faites ce que vous voulez lorsque la fenêtre est exposée
    
    return (0);
}

int testGraphicsExpose(void *data_v)
{
    (void)data_v;

    ft_printf("GraphicsExpose event\n");
    // Effectuez les actions souhaitées en réponse à l'événement GraphicsExpose

    return (0);
}

int testNoExpose(void *data_v)
{
    (void)data_v;

    ft_printf("NoExpose event\n");
    // Effectuez les actions souhaitées en réponse à l'événement NoExpose

    return (0);
}

int testVisibilityNotify(int visibility, void *data_v)
{
    (void)data_v;

    ft_printf("VisibilityNotify event with visibility: %d\n", visibility);
    // Effectuez les actions souhaitées en réponse à l'événement VisibilityNotify

    return (0);
}

int testCreateNotify(void *data_v)
{
    (void)data_v;

    ft_printf("CreateNotify event\n");
    // Effectuez les actions souhaitées en réponse à l'événement CreateNotify

    return (0);
}

int testUnmapNotify(void *data_v)
{
    (void)data_v;
    ft_printf("UnmapNotify event triggered\n");

    // Code de gestion de l'événement UnmapNotify

    return 0;
}

int testMapNotify(void *data_v)
{
    (void)data_v;
    ft_printf("MapNotify event triggered\n");

    // Code de gestion de l'événement MapNotify

    return 0;
}

int testMapRequest(void *data_v)
{
    (void)data_v;
    ft_printf("MapRequest event triggered\n");

    // Code de gestion de l'événement MapRequest

    return 0;
}

int testReparentNotify(void *data_v)
{
    (void)data_v;
    ft_printf("ReparentNotify event triggered\n");

    // Code de gestion de l'événement ReparentNotify

    return 0;
}

int testConfigureRequest(void *data_v)
{
    (void)data_v;
    ft_printf("ConfigureRequest event triggered\n");

    // Code de gestion de l'événement ConfigureRequest

    return 0;
}

int testGravityNotify(void *data_v)
{
    (void)data_v;
    ft_printf("GravityNotify event triggered\n");

    // Code de gestion de l'événement GravityNotify

    return 0;
}

int testResizeRequest(void *data_v)
{
    (void)data_v;
    ft_printf("ResizeRequest event triggered\n");

    // Code de gestion de l'événement ResizeRequest

    return 0;
}

int testCirculateNotify(void *data_v)
{
    (void)data_v;
    ft_printf("CirculateNotify event triggered\n");

    // Code de gestion de l'événement CirculateNotify

    return 0;
}

// Fonction pour le redimensionnement de la fenêtre
int testConfigureNotify(int x, int y, void *data_v)
{
    (void)data_v;

    printf("Window se deplace voici sa position x, y %d %d.\n", x, y);
    return (0);
}

int handleConfigureNotify(int x, int y, int width, int height, void *data_v)
{
    (void)x;
    (void)y;
    (void)data_v;

    printf("Window is resized: width = %d, height = %d\n", width, height);
    // Ajoutez ici le code que vous souhaitez exécuter lors du redimensionnement de la fenêtre

    return 0;
}

// Continuez de définir les fonctions pour les autres événements


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
	mlx_hook(data->win_ptr, FocusIn, FocusChangeMask, testFocusIn, data);					// quand la fenere est visible
	mlx_hook(data->win_ptr, FocusOut, FocusChangeMask, testFocusOut, data);					// quand la fenere est caché
	mlx_hook(data->win_ptr, KeymapNotify, 0, test_keymapNotify, data);						// ?
	mlx_hook(data->win_ptr, Expose, ExposureMask, test_Expose, data);

    // mlx_hook(data->win_ptr, GraphicsExpose, 0, testGraphicsExpose, data);					// ?
    // mlx_hook(data->win_ptr, NoExpose, 0, testNoExpose, data);								// ?
    // mlx_hook(data->win_ptr, VisibilityNotify, VisibilityChangeMask, testVisibilityNotify, data); // ?
    mlx_hook(data->win_ptr, CreateNotify, 0, testCreateNotify, data);
	mlx_hook(data->win_ptr, DestroyNotify, NO_MASK_EVENT, close_with_x, data);

    mlx_hook(data->win_ptr, UnmapNotify, 0, testUnmapNotify, data);                 // Quand la fenêtre est désappairée
    mlx_hook(data->win_ptr, MapNotify, 0, testMapNotify, data);                     // Quand la fenêtre est appairée
    mlx_hook(data->win_ptr, MapRequest, 0, testMapRequest, data);                   // Demande d'appariement de fenêtre
    mlx_hook(data->win_ptr, ReparentNotify, 0, testReparentNotify, data);           // Quand la fenêtre est reparentée
    mlx_hook(data->win_ptr, ConfigureNotify, StructureNotifyMask, testConfigureNotify, data);   // Lorsque la fenêtre est redimensionnée

    mlx_hook(data->win_ptr, ConfigureRequest, StructureNotifyMask, testConfigureRequest, data);    // ConfigureRequest event
    mlx_hook(data->win_ptr, GravityNotify, StructureNotifyMask, testGravityNotify, data);          // GravityNotify event
    mlx_hook(data->win_ptr, ResizeRequest, StructureNotifyMask, testResizeRequest, data);          // ResizeRequest event
    mlx_hook(data->win_ptr, CirculateNotify, StructureNotifyMask, testCirculateNotify, data);      // CirculateNotify event

	mlx_hook(data->win_ptr, ConfigureNotify, StructureNotifyMask, handleConfigureNotify, data);
	// mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask, souris_deplacement, data);
}
