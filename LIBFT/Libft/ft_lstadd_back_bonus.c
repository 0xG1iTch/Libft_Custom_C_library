/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-03 12:42:09 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-11-03 12:42:09 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cuu;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		cuu = *lst;
		cuu = ft_lstlast(cuu);
		cuu->next = new;
	}
}
