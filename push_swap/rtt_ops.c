/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-02 15:58:23 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-02 15:58:23 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int c)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (len_stack(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last_node = get_last_node(*stack);
	tmp->next = NULL;
	last_node->next = tmp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'x');
	rotate(stack_b, 'x');
	write(1, "rr\n", 3);
}

static t_stack	*before_last_node(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	rotate_reverse(t_stack **stack, int c)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*before_last;

	if (len_stack(*stack) < 2)
		return ;
	if (*stack == NULL || (*stack)->next == NULL)
		exit(1);
	last = get_last_node(*stack);
	before_last = before_last_node(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	before_last->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rotate_reverse(stack_a, 'x');
	rotate_reverse(stack_b, 'x');
	write(1, "rrr\n", 4);
}
