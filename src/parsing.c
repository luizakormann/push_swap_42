/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:41:40 by lukorman          #+#    #+#             */
/*   Updated: 2025/05/15 20:34:18 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			parse_args(int argc, char **argv, t_stack *stack_a, t_stack *stack_b);
static int	count_numbers(int argc, char **argv);
static int	parse_single_arg(char *arg, t_stack *stack, int *pos);
int			is_valid_number(char *str);
int			check_duplicates(t_stack *stack);

int	parse_args(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;
	int	pos;

	size = count_numbers(argc, argv);
	if (size <= 0)
		return (0);
	init_stacks(stack_a, stack_b, size);
	i = 1;
	pos = 0;
	while (i < argc)
	{
		if (!parse_single_arg(argv[i], stack_a, &pos))
			return (0);
		i++;
	}
	stack_a->size = size;
	if (!check_duplicates(stack_a))
		return (0);
	return (1);
}

static int	count_numbers(int argc, char **argv)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			count += count_in_split(argv[i]);
		else
			count++;
		i++;
	}
	return (count);
}

static int	parse_single_arg(char *arg, t_stack *stack, int *pos)
{
	long	num;

	if (ft_strchr(arg, ' '))
		return (parse_space_separated(arg, stack, pos));
	else
	{
		if (!is_valid_number(arg))
			return (0);
		num = ft_atol(arg);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		stack->values[(*pos)++] = (int)num;
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->values[i] == stack->values[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
