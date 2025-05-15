/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:33:45 by luiza             #+#    #+#             */
/*   Updated: 2025/05/14 16:40:10 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stack)
{
	int temp_val;
	int temp_idx;

	if (stack->size < 2)
		return ;
	temp_val = stack->values[0];
	stack->values[0] = stack->values[1];
	stack->values[1] = temp_val;

	temp_idx = stack->index[0];
	stack->index[0] = stack->index[1];
	stack->index[1] = temp_idx;
}

void	push(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	ft_memmove(&to->values[1], &to->values[0], sizeof(int) * to->size);
	ft_memmove(&to->index[1], &to->index[0], sizeof(int) * to->size);
	to->values[0] = from->values[0];
	to->index[0] = from->index[0];
	ft_memmove(&from->values[0], &from->values[1], sizeof(int) * (from->size - 1));
	ft_memmove(&from->index[0], &from->index[1], sizeof(int) * (from->size - 1));
	from->size--;
	to->size++;
}

void	rotate(t_stack *stack)
{
	int temp_val;
	int temp_idx;

	if (stack->size < 2)
		return ;
	temp_val = stack->values[0];
	temp_idx = stack->index[0];
	ft_memmove(&stack->values[0], &stack->values[1], sizeof(int) * (stack->size - 1));
	ft_memmove(&stack->index[0], &stack->index[1], sizeof(int) * (stack->size - 1));
	stack->values[stack->size - 1] = temp_val;
	stack->index[stack->size - 1] = temp_idx;
}

void	rev_rotate(t_stack *stack)
{
	int temp_val;
	int temp_idx;

	if (stack->size < 2)
		return ;

	temp_val = stack->values[stack->size - 1];
	temp_idx = stack->index[stack->size - 1];
	ft_memmove(&stack->values[1], &stack->values[0], sizeof(int) * (stack->size - 1));
	ft_memmove(&stack->index[1], &stack->index[0], sizeof(int) * (stack->size - 1));
	stack->values[0] = temp_val;
	stack->index[0] = temp_idx;
}
