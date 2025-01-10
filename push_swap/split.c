/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-31 14:21:32 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-12-31 14:21:32 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free__args(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		num_word;
	char	**splits;
	int		i;

	i = 0;
	num_word = count_words(str, separator);
	if (!num_word)
		exit(1);
	splits = malloc(sizeof(char *) * (size_t)(num_word + 2));
	if (NULL == splits)
		return (NULL);
	while (num_word-- >= 0)
	{
		if (0 == i)
		{
			splits[i] = malloc(sizeof(char));
			if (NULL == splits[i])
				return (NULL);
			splits[i++][0] = '\0';
			continue ;
		}
		splits[i++] = next_word(str, separator);
	}
	splits[i] = NULL;
	return (splits);
}
