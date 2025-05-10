/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:42:10 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/10 17:42:18 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack *stack, int size)
{
	stack->values = (int *)malloc(sizeof(int) * size);
	if (!stack->values)
		exit(EXIT_FAILURE);
	stack->index = (int *)malloc(sizeof(int) * size);
	if (!stack->index)
	{
		free(stack->values);
		exit(EXIT_FAILURE);
	}
	stack->size = size;
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->values)
			free(stack->values);
		if (stack->index)
			free(stack->index);
		stack->values = NULL;
		stack->index = NULL;
		stack->size = 0;
	}
}

void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->values[i] > stack->values[i + 1])
			return (0);
		i++;
	}
	return (1);
}

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
