/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:13:49 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/10 17:47:39 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft_42/include/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		*values;
	int		*index;
	int		size;
}	t_stack;

int		parse_args(int argc, char **argv, t_stack *stack_a);
int		is_valid_number(char *str);
int		check_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
void	sa(t_stack *stack_a, int print);
void	sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	index_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	exit_error(t_stack *stack_a, t_stack *stack_b);
void	init_stack(t_stack *stack, int size);




#endif
