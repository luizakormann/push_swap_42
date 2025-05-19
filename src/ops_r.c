/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:42:51 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/19 15:14:04 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *stack_a, int print)
{
	rotate(stack_a);
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rra(t_stack *stack_a, int print)
{
	rev_rotate(stack_a);
	if (print)
		ft_putendl_fd("rra", 1);
}
