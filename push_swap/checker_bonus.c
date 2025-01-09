/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 14:21:24 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-08 14:21:24 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	error(t_stack **a, t_stack **b)
{
	free_stack(*a);
	free_stack(*b);
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

static void	parse(t_stack **a, t_stack **b, char *command)
{
	if (!ft_strcmp(command, "pb\n"))
		push(a, b, 'x');
	else if (!ft_strcmp(command, "pa\n"))
		push(b, a, 'x');
	else if (!ft_strcmp(command, "sa\n"))
		swap(a, 'x');
	else if (!ft_strcmp(command, "sb\n"))
		swap(b, 'x');
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(command, "ra\n"))
		rotate(a, 'x');
	else if (!ft_strcmp(command, "rb\n"))
		rotate(b, 'x');
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(command, "rra\n"))
		rotate_reverse(a, 'x');
	else if (!ft_strcmp(command, "rrb\n"))
		rotate_reverse(b, 'x');
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b);
	else
		error(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len_a;
	int		len_b;
	char	*next_line;

	(1) && (stack_a = NULL, stack_b = NULL);
	if (ac < 2 || (2 == ac && !av[1][0]))
		exit (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	initialize_stack(&stack_a, av + 1);
	(1) && (len_a = len_stack(stack_a), next_line = get_next_line(0));
	while (next_line)
	{
		parse(&stack_a, &stack_b, next_line);
		free(next_line);
		next_line = get_next_line(0);
	}
	len_b = len_stack(stack_b);
	if (stack_sorted(stack_a) && len_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stack_a);
}
