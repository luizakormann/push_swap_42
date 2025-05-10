/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:43:38 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/10 17:43:50 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		if (stack->values[0] > stack->values[1])
			sa(stack, 1);
		return ;
	}
	a = stack->values[0];
	b = stack->values[1];
	c = stack->values[2];
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

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	while (stack_a->size > 3)
	{
		pos = find_min_pos(stack_a);
		if (pos <= stack_a->size / 2)
		{
			while (pos > 0)
			{
				ra(stack_a, 1);
				pos--;
			}
		}
		else
		{
			while (pos < stack_a->size)
			{
				rra(stack_a, 1);
				pos++;
			}
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

/*
** Radix Sort implementation
** 1. Indexar todos os números (já é feito no main)
** 2. Ordenar os números usando algoritmo radix sort em base 2
*/
void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->index[0] >> i) & 1) == 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
