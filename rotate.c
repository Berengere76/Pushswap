/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:33:49 by blebas            #+#    #+#             */
/*   Updated: 2024/01/22 15:34:14 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	first = *stack;
	last = ft_lst_last(first);
	*stack = (*stack)->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

void	ft_ra(t_stack **stack_a)
{
	if (ft_rotate(stack_a))
		ft_printf("ra\n");
}

void	ft_rb(t_stack **stack_b)
{
	if (ft_rotate(stack_b))
		ft_printf("rb\n");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_rotate(stack_a) && ft_rotate(stack_b))
		ft_printf("rr\n");
}
