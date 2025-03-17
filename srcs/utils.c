/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bozil <bozil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:28:22 by bozil             #+#    #+#             */
/*   Updated: 2025/03/17 13:40:00 by bozil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	find_min_index(t_node *stack)
{
	int	min;
	int	min_index;
	int	index;

	if (!stack)
		return (-1);
	min = stack->value;
	min_index = 0;
	index = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_index = index;
		}
		stack = stack->next;
		index++;
	}
	return (min_index);
}

void	move_to_top(t_node **stack, int index)
{
	int	size;
	int	i;

	size = stack_size(*stack);
	if (index <= size / 2)
	{
		i = 0;
		while (i < index)
		{
			ra(stack);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (size - index))
		{
			rra(stack);
			i++;
		}
	}
}
