/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:47:55 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/15 19:12:21 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	bad_parsing(void)
{
	ft_printf("============ ERREUR PARAMETRE ============\n");
	ft_printf("\nExemple :\n\t\t\t./fractol [1] [2] [3]\n\n");
	ft_printf("============================================\n");
	ft_printf(" [1] est obligatoire quel fractal a afficher, choix possible : \n");
	ft_printf("\t\t- \"M\" = Fractol de Mandelbrot.\n");
	ft_printf("\t\t- \"J\" = Fractol de Julia valeur par defaut -> -1+0.5i\n");
	ft_printf("\t\t- \"B\" = Fractol du Burning Ship.\n");
	ft_printf("============================================\n");
	ft_printf(" [2] Non obligatoire pour modifier julia, exemple : \n");
	ft_printf("\t-0.5+0.75i\n\t+0+0i\n\t-1-0.987654i\nETC respecter la forme\n");
	ft_printf("max 6 chiffre apres la virgule.\n");
	ft_printf("============================================\n");
	ft_printf(" [3] Non obligatoire choix des couleur : \n\n");
	ft_printf("Il y a 10 couleur il faut metre une valeur entre 0 et 9.\n");
	ft_printf("Valeur par defaut 0\n");
	ft_printf("============================================\n");
	ft_printf("Commande:\n\tOn peut se deplace avec les fleche ou clique gauche de la souris.\n");
	ft_printf("\tZOOME avec la molete de la souris ou le signe + -.\n");
	ft_printf("\tappuyer sur \"f\" pour changer de fractal et \"c\"pour changer de couleur.\n");
	return (0);
}

int	ft_str_cmp(char *s1, char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i] || !s2[i])
			return (1);
		i++;
	}
	return (s1[i] != s2[i]);
}

int	find_fractol(char **arg_v, int argc, t_point **julia)
{
	char	*arg;

	arg = arg_v[1];
	if (get_param_julia(arg_v, julia, argc))
		return (0);
	if (!(ft_str_cmp(arg, "J")))
		return (1);
	else if (!(ft_str_cmp(arg, "M")))
		return (2);
	else if ((!ft_str_cmp(arg, "B")))
		return (3);
	if (argc == 2)
		return (0);
	return (0);
}

int	find_color(char *arg)
{
	if ((!ft_str_cmp(arg, "1")))
		return (10);
	else if ((!ft_str_cmp(arg, "2")))
		return (20);
	else if ((!ft_str_cmp(arg, "3")))
		return (30);
	else if ((!ft_str_cmp(arg, "4")))
		return (40);
	else if ((!ft_str_cmp(arg, "5")))
		return (50);
	else if ((!ft_str_cmp(arg, "6")))
		return (60);
	else if ((!ft_str_cmp(arg, "7")))
		return (70);
	else if ((!ft_str_cmp(arg, "8")))
		return (80);
	else if ((!ft_str_cmp(arg, "9")))
		return (90);
	return (0);
}

int	ft_parsing(int argc, char **argv, t_point **julia)
{
	int		res;
	char	*arg;

	res = 0;
	if (argc <= 1 || argc > 4)
		return (bad_parsing());
	res = find_fractol(argv, argc, julia);
	if (!res)
		return (bad_parsing());
	if (argc <= 2)
		return (res);
	if (argc == 3)
		arg = argv[2];
	else
		arg = argv[3];
	return (res + find_color(arg));
}
