/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:42:51 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/14 12:22:27 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *stack_a, int print)
{
	int	temp_val;
	int	temp_idx;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp_val = stack_a->values[0];
	temp_idx = stack_a->index[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->values[i] = stack_a->values[i + 1];
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->values[stack_a->size - 1] = temp_val;
	stack_a->index[stack_a->size - 1] = temp_idx;
	if (print)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *stack_b, int print)
{
	int	temp_val;
	int	temp_idx;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp_val = stack_b->values[0];
	temp_idx = stack_b->index[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->values[i] = stack_b->values[i + 1];
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->values[stack_b->size - 1] = temp_val;
	stack_b->index[stack_b->size - 1] = temp_idx;
	if (print)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putendl_fd("rr", 1);
}

void	rra(t_stack *stack_a, int print)
{
	int	temp_val;
	int	temp_idx;
	int	i;

	if (stack_a->size < 2)
		return ;
	temp_val = stack_a->values[stack_a->size - 1];
	temp_idx = stack_a->index[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->values[i] = stack_a->values[i - 1];
		stack_a->index[i] = stack_a->index[i - 1];
		i--;
	}
	stack_a->values[0] = temp_val;
	stack_a->index[0] = temp_idx;
	if (print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack_b, int print)
{
	int	temp_val;
	int	temp_idx;
	int	i;

	if (stack_b->size < 2)
		return ;
	temp_val = stack_b->values[stack_b->size - 1];
	temp_idx = stack_b->index[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->values[i] = stack_b->values[i - 1];
		stack_b->index[i] = stack_b->index[i - 1];
		i--;
	}
	stack_b->values[0] = temp_val;
	stack_b->index[0] = temp_idx;
	if (print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putendl_fd("rrr", 1);
}
