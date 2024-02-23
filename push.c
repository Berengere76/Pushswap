/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:37:09 by blebas            #+#    #+#             */
/*   Updated: 2024/01/22 15:37:22 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return (0);
	ft_lst_add_front(dst, ft_lst_new((*src)->content, (*src)->index));
	tmp = (*src)->next;
	free(*src);
	*src = tmp;
	return (1);
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	if (ft_push(stack_b, stack_a))
		ft_printf("pa\n");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_push(stack_a, stack_b))
		ft_printf("pb\n");
}
