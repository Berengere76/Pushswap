/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:02:29 by blebas            #+#    #+#             */
/*   Updated: 2024/01/22 15:02:31 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **stack)
{
	int		tmp;
	int		tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	tmp2 = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp2;
	return (1);
}

void	ft_sa(t_stack **stack_a)
{
	if (ft_swap(stack_a))
		ft_printf("sa\n");
}

void	ft_sb(t_stack **stack_b)
{
	if (ft_swap(stack_b))
		ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_swap(stack_a) && ft_swap(stack_b))
		ft_printf("ss\n");
}
