/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:54 by blebas            #+#    #+#             */
/*   Updated: 2024/02/12 14:57:58 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_index(t_stack **stack, int value)
{
	t_stack	*first;
	int		min_value;

	first = *stack;
	min_value = first->content;
	while (first->next)
	{
		first = first->next;
		if (first->content < min_value && first->content != value)
			min_value = first->content;
	}
	return (min_value);
}

void	ft_sort_three(t_stack **stack_a)
{
	if ((*stack_a)->content == ft_min_index(stack_a, -1)
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if ((*stack_a)->content
		== ft_min_index(stack_a, ft_min_index(stack_a, -1)))
	{
		if ((*stack_a)->next->content == ft_min_index(stack_a, -1))
			ft_sa(stack_a);
		else if ((*stack_a)->next->next->content == ft_min_index(stack_a, -1))
			ft_rra(stack_a);
	}
	else
	{
		if ((*stack_a)->next->content == ft_min_index(stack_a, -1))
			ft_ra(stack_a);
		else
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
	}
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_min_distance(stack_a, ft_min_index(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	if (distance == 3)
		ft_rra(stack_a);
	if (!ft_stack_is_sorted(stack_a))
	{
		ft_pb(stack_a, stack_b);
		ft_sort_three(stack_a);
		ft_pa(stack_b, stack_a);
	}
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = ft_min_distance(stack_a, ft_min_index(stack_a, -1));
	if (distance == 1)
		ft_ra(stack_a);
	if (distance == 2)
	{
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
	if (distance == 3)
	{
		ft_rra(stack_a);
		ft_rra(stack_a);
	}
	if (distance == 4)
		ft_rra(stack_a);
	if (!ft_stack_is_sorted(stack_a))
	{
		ft_pb(stack_a, stack_b);
		ft_sort_four(stack_a, stack_b);
		ft_pa(stack_b, stack_a);
	}
}

void	ft_sort_little(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_size_stack(*stack_a);
	if (ft_stack_is_sorted(stack_a) || ft_size_stack(*stack_a) <= 1)
		return ;
	if (size == 2)
		ft_sa(stack_a);
	if (size == 3)
		ft_sort_three(stack_a);
	if (size == 4)
		ft_sort_four(stack_a, stack_b);
	if (size == 5)
		ft_sort_five(stack_a, stack_b);
}
