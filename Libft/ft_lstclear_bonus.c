/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-03 12:42:41 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-03 12:42:41 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !*lst)
		return ;
	ft_lstclear(&(*lst)->next, del);
	if (del && (*lst)->content)
		del((*lst)->content);
	free(*lst);
	*lst = NULL;
}

// int main ()
// {
// 	int *num1 = malloc(sizeof(int));
// 	int *num2 = malloc(sizeof(int));
// 	*num1 = 10;
// 	*num2 =20;
// 	t_list *list = ft_lstnew(num1);
// 	list->next = ft_lstclear(&list, del)
// 	if (list == NULL)
// 		printf("list cleared");
// 	else
// 		printf("nn 3amra");
// }
