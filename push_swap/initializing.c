/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-31 14:46:42 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-12-31 14:46:42 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *str)
{
	long	num;
	int		i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		i++;
	if (*str == '+' || *str == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

static void	add_to_node(t_stack **stack_a, int nmbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack_a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = nmbr;
	new_node->index = 0;
	new_node->next = NULL;
	if (!(*stack_a))
		*stack_a = new_node;
	else
	{
		last_node = get_last_node(*stack_a);
		last_node->next = new_node;
	}
}

void	initialize_stack(t_stack **stack_a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (synthax_error(av[i]))
			free_(stack_a);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN || duplicated_error(*stack_a, (int)n))
			free_(stack_a);
		add_to_node(stack_a, (int)n);
		i++;
	}
}

void	indexing(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
