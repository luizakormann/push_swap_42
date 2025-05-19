/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:43:15 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/19 15:14:53 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_putendl_fd("sa", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
