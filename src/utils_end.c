/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:42:10 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/15 21:36:19 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack);
void	ft_free_split(char **split);
void	exit_error(t_stack *stack_a, t_stack *stack_b);


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

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

