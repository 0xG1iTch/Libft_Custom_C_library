/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 14:10:17 by mel-hamm          #+#    #+#             */
/*   Updated: 2025-01-07 14:10:17 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct stack_node
{
	int					value;
	int					index;
	int					position;
	int					target_position;
	int					cost_a;
	int					cost_b;
	struct stack_node	*next;
}	t_stack;

int		lowest_index_position(t_stack **stack);
int		duplicated_error(t_stack *stack_a, int nbr);
int		len_stack(t_stack *stack);
int		synthax_error(char *str);
int		absolut(int nb);
int		biger_index(t_stack *stack);

void	select_move(t_stack **stk_a, t_stack **stk_b, int cost_a, int cost_b);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_a_size);
void	push(t_stack **source, t_stack **destination, char flag);
void	target_position(t_stack **stack_a, t_stack **stack_b);
void	push_all_keep_3(t_stack **stack_a, t_stack **stack_b);
void	initialize_stack(t_stack **stack_a, char **av);
void	indexing(t_stack *stack_a, int stack_size);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	cost(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rotate_reverse(t_stack **stack, int c);
void	rotate(t_stack **stack, int c);
void	swap(t_stack **head, char c);
void	free_stack(t_stack *stack);
void	sort_3(t_stack **stack_a);
void	free_(t_stack **stack_a);
void	free__args(char **av);

char	**ft_split(char *str, char separator);

bool	stack_sorted(t_stack *stack);

t_stack	*get_last_node(t_stack *stack_a);
#endif