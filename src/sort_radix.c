/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:55:12 by luiza             #+#    #+#             */
/*   Updated: 2025/05/15 21:34:14 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	index_stack(t_stack *stack);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

void	index_stack(t_stack *stack)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < stack->size)
	{
		count = 0;
		j = 0;
		while (j < stack->size)
		{
			if (stack->values[i] > stack->values[j])
				count++;
			j++;
		}
		stack->index[i] = count;
		i++;
	}
}

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
