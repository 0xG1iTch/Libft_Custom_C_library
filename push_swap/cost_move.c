/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 14:10:28 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-07 14:10:28 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	absolut(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = len_stack(tmp_a);
	size_b = len_stack(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_position;
		if (tmp_b->target_position > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_position) * -1;
		tmp_b = tmp_b->next;
	}
}

void	rr_or_rrr(t_stack **stk_a, t_stack **stk_b, int *cost_a, int *cost_b)
{
	if (*cost_a < 0 && *cost_b < 0)
	{
		while (*cost_a < 0 && *cost_b < 0)
		{
			rrr(stk_a, stk_b);
			*cost_a += 1;
			*cost_b += 1;
		}
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		while (*cost_a > 0 && *cost_b > 0)
		{
			rr(stk_a, stk_b);
			*cost_a = *cost_a - 1;
			*cost_b = *cost_b - 1;
		}
	}
}

void	select_move(t_stack **stk_a, t_stack **stk_b, int cost_a, int cost_b)
{
	rr_or_rrr(stk_a, stk_b, &cost_a, &cost_b);
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_a > 0)
		{
			rotate(stk_a, 'a');
			cost_a--;
		}
		else if (cost_a < 0)
		{
			rotate_reverse(stk_a, 'a');
			cost_a++;
		}
		if (cost_b > 0)
		{
			rotate(stk_b, 'b');
			cost_b--;
		}
		else if (cost_b < 0)
		{
			rotate_reverse(stk_b, 'b');
			cost_b++;
		}
	}
	push(stk_b, stk_a, 'a');
}
