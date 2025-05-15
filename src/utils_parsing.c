/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:28:33 by luiza             #+#    #+#             */
/*   Updated: 2025/05/15 18:40:48 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	parse_space_separated(char *arg, t_stack *stack, int *pos)
{
	char	**split;
	int		i;
	long	num;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i]))
			return (ft_free_split(split), 0);
		num = ft_atol(split[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_free_split(split), 0);
		stack->values[(*pos)++] = (int)num;
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	count_in_split(char *arg)
{
	char	**split;
	int		i;
	int		count;

	split = ft_split(arg, ' ');
	if (!split)
		return (-1);
	i = 0;
	while (split[i])
	{
		count++;
		i++;
	}
	ft_free_split(split);
	return (count);
}
