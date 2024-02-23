/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:53:54 by blebas            #+#    #+#             */
/*   Updated: 2024/02/02 14:53:58 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_lst_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_lst_new(int content, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lst_add_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return (NULL);
	new->next = *lst;
	*lst = new;
	return (new);
}

t_stack	*ft_lst_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*node;

	if (!lst || !new)
		return (NULL);
	if (!(*lst))
	{
		*lst = new;
		return (NULL);
	}
	node = ft_lst_last(*lst);
	node->next = new;
	return (new);
}
