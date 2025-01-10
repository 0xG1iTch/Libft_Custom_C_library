/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 14:11:01 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-07 14:11:01 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	synthax_error(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	duplicated_error(t_stack *stack_a, int nbr)
{
	while (stack_a)
	{
		if (stack_a->value == nbr)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	free_(t_stack **stack_a)
{
	free_stack(*stack_a);
	write(2, "Error\n", 6);
	exit(1);
}
