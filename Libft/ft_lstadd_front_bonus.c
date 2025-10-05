/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-02 17:23:51 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-02 17:23:51 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main()
// {
// 	t_list	*list = NULL;
// 	char val1 = 'a';

// 	t_list *node1 = ft_lstnew(&val1);
//  t_list *node2 = ft_lstnew(&val2);
//  t_list *node3 = ft_lstnew(&val3);
// 	ft_lstadd_front(NULL, node1);
// 	ft_lstadd_front(&list, node2);
// 	ft_lstadd_front(&list, node3);
// 	t_list *current = list;
// 	while (current != NULL)
// 	{
// 		printf ("%c ", *(char *)current->content);
// 		current = current->next;
// 	}
// }