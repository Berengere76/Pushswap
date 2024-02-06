/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:02:08 by blebas            #+#    #+#             */
/*   Updated: 2024/01/22 15:02:12 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	main()
// {
// 	// t_stack	*stack_a;
// 	// t_stack	*stack_b;

void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        ft_putnbr(stack->content);
        ft_putchar(' ');
        stack = stack->next;
    }
    ft_putchar('\n');
}

int	main()
{
    t_stack *stack = NULL;
    for (int i = 10; i >= 1; i--)
    {
        t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
        new_node->content = i;
        new_node->next = stack;
        stack = new_node;
    }

    ft_printf("Pile avant rotation : ");
    print_stack(stack);

    ft_rotate(&stack);
    ft_printf("Pile apres rotation : ");
    print_stack(stack);

    ft_reverse_rotate(&stack);
    ft_printf("Pile apres reverse rotate : ");
    print_stack(stack);

	ft_swap(&stack);
    ft_printf("Pile apres swap : ");
    print_stack(stack);

    return 0;
}
