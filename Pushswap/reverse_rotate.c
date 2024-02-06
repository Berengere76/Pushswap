/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:02:20 by blebas            #+#    #+#             */
/*   Updated: 2024/01/22 15:02:22 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*before_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	first = *stack;
	last = ft_lst_last(first);
	before_last = ft_lst_before_last(first);
	*stack = last;
	(*stack)->next = first;
	before_last->next = NULL;
	return (1);
}

void	ft_rra(t_stack **stack_a)
{
	if (ft_reverse_rotate(stack_a))
		ft_printf("rra\n");
}

void	ft_rrb(t_stack **stack_b)
{
	if (ft_reverse_rotate(stack_b))
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_reverse_rotate(stack_a) && ft_reverse_rotate(stack_b))
		ft_printf("rrr\n");
}
