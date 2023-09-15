/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_jualia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:02:13 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/15 18:28:22 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

float	ft_atof2(char *str, size_t i, int *error)
{
	float	nbr;

	nbr = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (*(error) = 1, 0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!(str[i] == '\0' || str[i] == '+' || str[i] == '-' || str[i] == 'i'))
		return (*(error) = 1, 0);
	i--;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr / 10;
		nbr += str[i] - '0';
		i--;
	}
	return (nbr / 10);
}

float	ft_atof(char *nptr, size_t i, int *error)
{
	float	nbr;
	int		signe;

	if (*error || !(nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
		return (*error = 1, 0);
	nbr = 0;
	signe = 1;
	if (nptr[i] == '-')
	{
		i++;
		signe = -1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10;
		nbr += nptr[i] - '0';
		i++;
	}
	if (nptr[i++] == '.')
		nbr += ft_atof2(nptr, i, error);
	return ((float)signe * nbr);
}

void	julia_par_default(t_point *j, t_point **julia)
{
	j->x = -1;
	j->y = 0.05;
	j->iteration = 0;
	*julia = j;
}

int	init_var(int *error, char **arg, char **argv, int argc)
{
	if (argc <= 2)
		return (1);
	*error = 0;
	*arg = argv[2];
	if (!(argv[2][0] == '-' || argv[2][0] == '+'))
		return (1);
	return (0);
}

int	get_param_julia(char **arg_v, t_point **julia, int argc)
{
	char	*arg;
	int		s;
	int		error;
	t_point	*j;

	j = ft_calloc(sizeof(t_point), 1);
	if (!j)
		return (1);
	if (init_var(&error, &arg, arg_v, argc))
		return (julia_par_default(j, julia), 0);
	s = 0;
	j->x = ft_atof(arg, s, &error);
	s++;
	while (arg[s] && arg[s] != '-' && arg[s] != '+')
		s++;
	if (arg[s] == '\0')
		return (julia_par_default(j, julia), 0);
	j->y = ft_atof(arg, s, &error);
	while (arg[s] && arg[s] != 'i')
		s++;
	if (arg[s] != 'i' || error)
		return (julia_par_default(j, julia), 0);
	j->iteration = 0;
	*julia = j;
	return (0);
}
