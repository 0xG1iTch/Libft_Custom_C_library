/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-03 12:41:49 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-03 12:41:49 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst ->next != NULL)
		lst = lst->next;
	return (lst);
}

// int main()
// {
// 	char val1 = 'a', val2 = 'b', val3 = 'c';
// 	t_list	*head = ft_lstnew(&val1);
// 	head->next = ft_lstnew(&val2);
// 	head->next->next = ft_lstnew(&val3);
// 	t_list	*last_node = ft_lstlast( head);
// 	printf("%c\n", *(int *)last_node->content);
// }