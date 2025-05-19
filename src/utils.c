/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:44:01 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/19 13:47:05 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *str);
void	init_stack(t_stack *stack, int size);
void	init_stacks(t_stack *a, t_stack *b, int size);
int		is_sorted(t_stack *stack);

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	init_stack(t_stack *stack, int size)
{
	stack->values = (int *)malloc(sizeof(int) * size);
	if (!stack->values)
		return ;
	stack->index = (int *)malloc(sizeof(int) * size);
	if (!stack->index)
	{
		free(stack->values);
		stack->values = NULL;
		return ;
	}
}

void	init_stacks(t_stack *a, t_stack *b, int size)
{
	init_stack(a, size);
	init_stack(b, size);
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
