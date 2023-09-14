/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatsu <yatsu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:47:55 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/14 14:41:51 by yatsu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	bad_parsing(void)
{
	ft_printf("============ ERREUR PARAMETRE ============\n");
	ft_printf("\nExemple :\n\t\t\t./fractol [1] [2]\n\n");
	ft_printf("============================================\n");
	ft_printf("        [1]\t\t\t\t|         [2]\n");
	ft_printf("============================================\n");
	ft_printf("Le choix de la Fractal\t| Le choix de couleur\n");
	ft_printf("\t\t\t\t\t\t|   Peut etre vide\n");
	ft_printf("--------------------------------------------\n");
	ft_printf("===================  Choix  ===============\n");
	ft_printf("     Obligatoire\t\t|      Possible\n\n");
	ft_printf("     \"J\"\t\t\t|\t\"0\", \"1\", \"2\"\n");
	ft_printf("    \"M\"\t\t|          OU\n");
	ft_printf("    \"My\"\t\t\t|         RIEN\n");
	ft_printf("============================================\n");
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

int	find_fractol(char *arg)
{
	if (!(ft_str_cmp(arg, "J")))
		return (1);
	else if (!(ft_str_cmp(arg, "M")))
		return (2);
	else if ((!ft_str_cmp(arg, "My")))
		return (3);
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
	return (0);
}

int	ft_parsing(int argc, char **argv)
{
	int	res;

	res = 0;
	if (argc <= 1 || argc > 3)
		return (bad_parsing());
	res = find_fractol(argv[1]);
	if (!res)
		return (bad_parsing());
	return (res + find_color(argv[2]));
}
