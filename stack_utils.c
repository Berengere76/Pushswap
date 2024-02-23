/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:51:23 by blebas            #+#    #+#             */
/*   Updated: 2024/02/01 15:51:36 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//:Stdheader

#include "push_swap.h"

int	ft_stack_is_sorted(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	while (first->next)
	{
		if (first->content > first->next->content)
			return (0);
		first = first->next;
	}
	return (1);
}

int	ft_size_stack(t_stack *first)
{
	int	size_s;

	size_s = 0;
	while (first)
	{
		first = first->next;
		size_s++;
	}
	return (size_s);
}

int	ft_min_distance(t_stack **stack, int index)
{
	t_stack	*first;
	int		distance;

	distance = 0;
	first = *stack;
	while (first)
	{
		if (first->content == index)
			break ;
		distance++;
		first = first->next;
	}
	return (distance);
}

void	ft_init_stack(t_stack **stack_a, char **argv)
{
	t_stack	*new;
	int		i;

	i = 1;
	while (argv[i])
	{
		new = ft_lst_new(ft_atoi(argv[i]), 0);
		ft_lst_add_back(stack_a, new);
		i++;
	}
}
