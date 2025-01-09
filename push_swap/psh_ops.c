/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psh_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 14:11:21 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-07 14:11:21 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **source, t_stack **destination, char flag)
{
	t_stack	*tmp;

	if (*source == NULL)
		return ;
	tmp = (*source)->next;
	(*source)->next = *destination;
	*destination = *source;
	*source = tmp;
	if (flag == 'b')
		write(1, "pb\n", 3);
	else if (flag == 'a')
		write(1, "pa\n", 3);
}

void	push_all_keep_3(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;
	int	pushed;
	int	i;

	len_a = len_stack(*stack_a);
	pushed = 0;
	i = 0;
	while (len_a > 6 && i < len_a && pushed < len_a / 2)
	{
		if ((*stack_a)->index <= len_a / 2)
		{
			push(stack_a, stack_b, 'b');
			pushed++;
		}
		else
			rotate(stack_a, 'a');
		i++;
	}
	while (len_a - pushed > 3)
	{
		push(stack_a, stack_b, 'b');
		pushed++;
	}
}
