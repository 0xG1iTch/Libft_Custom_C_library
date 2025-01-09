/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 14:11:48 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-07 14:11:48 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	int		highest;

	if (stack_sorted(*stack))
		return ;
	highest = biger_index(*stack);
	if ((*stack)->index == highest)
		rotate(stack, 'a');
	else if ((*stack)->next->index == highest)
		rotate_reverse(stack, 'a');
	if ((*stack)->index > (*stack)->next->index)
		swap(stack, 'a');
}

void	move_cheap(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;
	int		cheap;

	tmp = *stack_b;
	cheap = INT_MAX;
	while (tmp)
	{
		if (absolut(tmp->cost_a) + absolut(tmp->cost_b)
			< absolut(cheap))
		{
			cheap = absolut(tmp->cost_b) + absolut(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	select_move(stack_a, stack_b, cost_a, cost_b);
}

static void	shift(t_stack **stack_a)
{
	int	low_position;
	int	stack_size;

	stack_size = len_stack(*stack_a);
	low_position = lowest_index_position(stack_a);
	if (low_position > stack_size / 2)
	{
		while (low_position < stack_size)
		{
			rotate_reverse(stack_a, 'a');
			low_position++;
		}
	}
	else
	{
		while (low_position > 0)
		{
			rotate(stack_a, 'a');
			low_position--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_keep_3(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b)
	{
		target_position(stack_a, stack_b);
		cost(stack_a, stack_b);
		move_cheap(stack_a, stack_b);
	}
	if (!stack_sorted(*stack_a))
		shift(stack_a);
}
