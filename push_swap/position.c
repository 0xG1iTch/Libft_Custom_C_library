/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 14:11:14 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-07 14:11:14 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

void	target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(stack_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_position = target_pos;
		tmp_b = tmp_b->next;
	}
}

int	lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		low_index;
	int		low_pos;

	tmp = *stack;
	low_index = INT_MAX;
	get_position(stack);
	low_pos = tmp->position;
	while (tmp)
	{
		if (tmp->index < low_index)
		{
			low_index = tmp->index;
			low_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (low_pos);
}
