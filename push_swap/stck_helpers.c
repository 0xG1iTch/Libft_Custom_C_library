/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stck_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-01 10:37:54 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-01 10:37:54 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	len_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*get_last_node(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	biger_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}
