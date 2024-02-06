/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:04:54 by blebas            #+#    #+#             */
/*   Updated: 2024/01/22 15:04:58 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
//# include <unistd.h>
//# include <stdio.h>
//# include <stdlib.h>

/* STRUCTURE */

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

/* OPERATIONS */

//swap.c
/* intervertit les 2 permiers elements au sommet de la pile */
int		ft_swap(t_stack **stack);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);

//push.c
int		ft_push(t_stack **src, t_stack **dst);
/* prend 1er element au sommet de b et le met sur a */
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
/* prend 1er element au sommet de a et le met sur b */
void	ft_pb(t_stack **stack_a, t_stack **stack_b);

//rotate.c
/* decale elements vers le haut (le 1er devient le dernier) */
int		ft_rotate(t_stack **stack);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);

//reverse_rotate.c
/* decale elements vers le bas (dernier devient le 1er) */
int		ft_reverse_rotate(t_stack **stack);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

/* LISTES */

//lst_utils.c
t_stack	*ft_lst_before_last(t_stack *stack);
t_stack	*ft_lst_last(t_stack *stack);
t_stack	*ft_lst_new(int content);
void	ft_lst_add_front(t_stack **lst, t_stack *new);

/* MAIN */

//push_swap.c
void print_stack(t_stack *stack);
int		main();

#endif
