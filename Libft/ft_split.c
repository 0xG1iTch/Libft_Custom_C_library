/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamm <mel-hamm@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-31 11:41:38 by mel-hamm          #+#    #+#             */
/*   Updated: 2024-10-31 11:41:38 by mel-hamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_splits(const char *s, char c)
{
	size_t	counter;
	int		flag;

	counter = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			flag = 1;
			counter++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (counter);
}

static void	free_space(char **splits, size_t i)
{
	while (i > 0)
	{
		free(splits[i - 1]);
		i--;
	}
	free(splits);
}

static char	*word_set(const char *s, char c, size_t *index)
{
	char	*word;
	size_t	start;
	size_t	length;

	length = 0;
	while (s[*index] && s[*index] == c)
		(*index)++;
	start = *index;
	while (s[*index] && s[*index] != c)
	{
		length++;
		(*index)++;
	}
	word = (char *)malloc((length + 1) * sizeof(char));
	if (!word)
		return (NULL);
	length = 0;
	while (s[start] && s[start] != c)
	{
		word[length] = s[start];
		start++;
		length++;
	}
	word[length] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	size_t	num_words;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	num_words = count_splits(s, c);
	splits = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!splits)
		return (NULL);
	while (i < num_words)
	{
		splits[i] = word_set(s, c, &j);
		if (!splits[i])
		{
			free_space(splits, i);
			return (NULL);
		}
		i++;
	}
	splits[i] = NULL;
	return (splits);
}
