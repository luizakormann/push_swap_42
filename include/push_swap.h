/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:13:49 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/19 15:15:23 by lukorman         ###   ########.fr       */
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
	int		count;
}	t_stack;

int		parse_args(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
int		count_in_split(char *arg);
void	init_stacks(t_stack *a, t_stack *b, int size);
void	init_stack(t_stack *stack, int size);
int		parse_space_separated(char *arg, t_stack *stack, int *pos);
int		is_valid_number(char *str);
int		check_duplicates(t_stack *stack);
int		is_sorted(t_stack *stack);
void	swap(t_stack *stack);
void	sa(t_stack *stack_a, int print);
void	push(t_stack *from, t_stack *to);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a, int print);
void	rev_rotate(t_stack *stack);
void	rra(t_stack *stack_a, int print);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	until_three(t_stack *stack);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
void	index_stack(t_stack *stack);
void	free_stack(t_stack *stack);
void	exit_error(t_stack *stack_a, t_stack *stack_b);
long	ft_atol(const char *str);
void	ft_free_split(char **split);

#endif
