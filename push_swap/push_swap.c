/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 14:11:32 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-07 14:11:32 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_a_size)
{
	if (!stack_sorted(*stack_a))
	{
		if (stack_a_size == 2)
			swap(stack_a, 'a');
		else if (stack_a_size == 3)
			sort_3(stack_a);
		else if (stack_a_size > 3)
			sort(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len_a;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2 || (2 == ac && !av[1][0]))
		exit (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	initialize_stack(&stack_a, av + 1);
	len_a = len_stack(stack_a);
	indexing(stack_a, len_a + 1);
	push_swap(&stack_a, &stack_b, len_a);
	free_stack(stack_a);
	if (ac == 2)
		free__args(av);
}
