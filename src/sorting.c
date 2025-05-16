/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:43:38 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/15 21:31:18 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		until_three(t_stack *stack);
static void	sort_two(t_stack *stack);
static void	sort_three(t_stack *stack, int a, int b, int c);
void		sort_small(t_stack *stack_a, t_stack *stack_b);
int			find_min_pos(t_stack *stack);

void	until_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->size < 2)
		return ;
	if (stack->size == 2)
	{
		sort_two(stack);
		return ;
	}
	a = stack->values[0];
	b = stack->values[1];
	c = stack->values[2];
	sort_three(stack, a, b, c);
}

static void	sort_two(t_stack *stack)
{
	if (stack->values[0] > stack->values[1])
		sa(stack, 1);
}

static void	sort_three(t_stack *stack, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		sa(stack, 1);
	else if (a > b && b > c)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;
	int	moves;

	while (stack_a->size > 3)
	{
		pos = find_min_pos(stack_a);
		if (pos <= stack_a->size / 2)
		{
			while (pos-- > 0)
				ra(stack_a, 1);
		}
		else
		{
			moves = stack_a->size - pos;
			while (moves-- > 0)
				rra(stack_a, 1);
		}
		pb(stack_a, stack_b);
	}
	until_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

int	find_min_pos(t_stack *stack)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = INT_MAX;
	pos = 0;
	while (i < stack->size)
	{
		if (stack->values[i] < min)
		{
			min = stack->values[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
