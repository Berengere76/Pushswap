/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:49:45 by blebas            #+#    #+#             */
/*   Updated: 2024/02/23 16:49:49 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_ps(char *nptr)
{
	long	res;
	int		j;
	int		k;

	res = 0;
	j = 0;
	k = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (nptr[0] == '-')
		k = -1;
	if (*nptr == '-' || *nptr == '+')
	{
		j++;
		nptr++;
		if (j >= 2)
			return (0);
	}
	while ((*nptr != '\0') && (*nptr >= '0' && *nptr <= '9'))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * k);
}

int	ft_args_nb(char *argv)
{
	int	i;

	i = 0;
	if (argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (!is_nb(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_arg_duplicate(char **argv, int num, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi_ps(argv[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi_ps(argv[i]) > INT_MAX || ft_atoi_ps(argv[i]) < INT_MIN)
		{
			ft_printf("Error");
			return (1);
		}
		if (!ft_args_nb(argv[i]))
		{
			ft_printf("Error");
			return (1);
		}
		if (!ft_arg_duplicate(argv, ft_atoi_ps(argv[i]), i))
		{
			ft_printf("Error");
			return (1);
		}
		i++;
	}
	return (0);
}
