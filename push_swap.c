/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:02:08 by blebas            #+#    #+#             */
/*   Updated: 2024/02/22 17:59:58 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_putchar('\n');
}

void	print_index(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d ", stack->index);
		stack = stack->next;
	}
	ft_putchar('\n');
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stack_is_sorted(stack_a))
		return ;
	if (ft_size_stack(*stack_a) <= 5)
		ft_sort_little(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (check_error(argc, argv) == 0)
	{
		ft_init_stack(&stack_a, argv);
		ft_index_list(stack_a);
		print_index(stack_a);
		ft_sort_stack(&stack_a, &stack_b);
		print_stack(stack_a);
		print_index(stack_a);
		free_stack(&stack_a);
		free_stack(&stack_b);
		free(stack_a);
		free(stack_b);
	}
	return (0);
}

// int	main()
// {
//     t_stack *stack = NULL;
//     t_stack *stack_dst = NULL;
//     for (int i = 10; i >= 5; i--)
//     {
//         t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
//         new_node->content = i;
//         new_node->next = stack;
//         stack = new_node;
//     }

//     ft_index_list(stack);
//     ft_printf("%d\n", stack->index);
//     ft_printf("%d\n", stack->next->index);
//     ft_printf("%d\n", stack->next->next->index);
//     ft_printf("%d\n", stack->next->next->next->index);
//     ft_printf("%d\n", stack->next->next->next->next->index);
//     ft_printf("%d\n", stack->next->next->next->next->next->index);

//     ft_printf("Pile avant rotation : ");
//     print_stack(stack);

//     ft_rotate(&stack);
//     ft_printf("Pile apres rotation : ");
//     print_stack(stack);

//     ft_reverse_rotate(&stack);
//     ft_printf("Pile apres reverse rotate : ");
//     print_stack(stack);

//     ft_swap(&stack);
//     ft_printf("Pile apres swap : ");
//     print_stack(stack);

//     ft_push(&stack, &stack_dst);
//     ft_printf("Pile source après push : ");
//     print_stack(stack);
//     ft_printf("Pile destination après push : ");
//     print_stack(stack_dst);

//     return 0;
// }

// // int main() 
// // {
// //     t_stack *stack_a = NULL;
// //     t_stack *stack_b = NULL;

// //     stack_a = ft_lst_add_front(&stack_a, ft_lst_new(100));
// //     stack_a = ft_lst_add_front(&stack_a, ft_lst_new(60));
// //     stack_a = ft_lst_add_front(&stack_a, ft_lst_new(111));
// //     stack_a = ft_lst_add_front(&stack_a, ft_lst_new(12));
// //     stack_a = ft_lst_add_front(&stack_a, ft_lst_new(90));
// //     stack_a = ft_lst_add_front(&stack_a, ft_lst_new(43));
// //     stack_a = ft_lst_add_front(&stack_a, ft_lst_new(70));

// //     ft_index_stack(&stack_a);
// //     ft_printf("%d\n", stack_a->index);
// //     ft_printf("%d\n", stack_a->next->index);

// //     ft_printf("Avant le tri :\n");
// //     print_stack(stack_a);

// //     ft_sort_stack(&stack_a, &stack_b);

// //     ft_printf("Après le tri :\n");
// //     print_stack(stack_a);

// //     return 0;
// // }
