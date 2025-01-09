/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-30 13:33:19 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-12-30 13:33:19 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head, char c)
{
	t_stack	*first;
	t_stack	*second;

	if (len_stack(*head) < 2)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 'x');
	swap(stack_b, 'x');
	write(1, "ss\n", 3);
}
