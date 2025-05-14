/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:43:15 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/14 12:19:18 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack_a, int print)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->values[0];
	stack_a->values[0] = stack_a->values[1];
	stack_a->values[1] = temp;
	temp = stack_a->index[0];
	stack_a->index[0] = stack_a->index[1];
	stack_a->index[1] = temp;
	if (print)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack_b, int print)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->values[0];
	stack_b->values[0] = stack_b->values[1];
	stack_b->values[1] = temp;
	temp = stack_b->index[0];
	stack_b->index[0] = stack_b->index[1];
	stack_b->index[1] = temp;
	if (print)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_putendl_fd("ss", 1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->size == 0)
		return ;
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->values[i] = stack_a->values[i - 1];
		stack_a->index[i] = stack_a->index[i - 1];
		i--;
	}
	stack_a->values[0] = stack_b->values[0];
	stack_a->index[0] = stack_b->index[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->values[i] = stack_b->values[i + 1];
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_a->size++;
	stack_b->size--;
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->size == 0)
		return ;
	i = stack_b->size;
	while (i > 0)
	{
		stack_b->values[i] = stack_b->values[i - 1];
		stack_b->index[i] = stack_b->index[i - 1];
		i--;
	}
	stack_b->values[0] = stack_a->values[0];
	stack_b->index[0] = stack_a->index[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->values[i] = stack_a->values[i + 1];
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_b->size++;
	stack_a->size--;
	ft_putendl_fd("pb", 1);
}
