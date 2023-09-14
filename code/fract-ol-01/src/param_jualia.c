/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_jualia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:02:13 by yzaoui            #+#    #+#             */
/*   Updated: 2023/09/14 23:03:17 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

float	ft_atof2(char *str, size_t i, int *error)
{
	float nbr;

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
	int			signe;

	if (*(error) || !(nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
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

int	get_param_julia(char *arg, t_point **julia)
{
	int		s;
	int		error;
	t_point	*j;

	error = 0;
	j = ft_calloc(sizeof(t_point), 1);
	if (!j)
		return (1);
	if (!(arg[0] == '-' || arg[0] == '+'))
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
