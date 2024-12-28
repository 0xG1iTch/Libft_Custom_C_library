/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-29 20:22:49 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-10-29 20:22:49 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n < 1)
		return (0);
	if (*(unsigned char *)s != (unsigned char )c)
		return (ft_memchr(s + 1, c, n - 1));
	return ((void *)s);
}
