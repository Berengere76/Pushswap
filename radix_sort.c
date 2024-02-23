/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:54 by blebas            #+#    #+#             */
/*   Updated: 2024/02/12 14:57:58 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index_list(t_stack *stack)
{
	t_stack		*first;
	t_stack		*tmp;
	int			index;

	index = 0;
	first = stack;
	while (stack)
	{
		tmp = first;
		while (tmp)
		{
			if (tmp->content < stack->content)
				index++;
			tmp = tmp->next;
		}
		stack->index = index;
		stack = stack->next;
		index = 0;
	}
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;
	int	max_num;
	int	i;
	int	j;

	size = ft_size_stack(*stack_a);
	max_num = size - 1;
	max_bits = 0;
	i = -1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (++i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_size_stack(*stack_b) != 0)
			ft_pa(stack_b, stack_a);
	}
}
