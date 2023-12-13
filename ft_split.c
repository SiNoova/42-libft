/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoutate <akoutate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:12:13 by akoutate          #+#    #+#             */
/*   Updated: 2023/12/06 00:36:37 by akoutate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		in;

	i = 0;
	count = 0;
	in = 0;
	while (s[i])
	{
		if (s[i] != c && in == 0)
		{
			in = 1;
			count++;
		}
		else if (s[i] == c && in == 1)
			in = 0;
		i++;
	}
	return (count);
}

static void	*free_all(char **all_words, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(all_words[i]);
		i++;
	}
	free(all_words);
	return (NULL);
}

static char	*allocate_word(char const *s, size_t start, size_t end)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, end - start + 1);
	return (word);
}

static char	**split_words(char const *s, char c, size_t word_count)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**all_words;

	all_words = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!all_words)
		return (NULL);
	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		all_words[j] = allocate_word(s, start, i);
		if (!all_words[j])
			return (free_all(all_words, j));
		j++;
	}
	all_words[j] = NULL;
	return (all_words);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**empty;

	if (!s || !*s)
	{
		empty = (char **)malloc(sizeof(char *));
		if (!empty)
			return (NULL);
		empty[0] = NULL;
		return (empty);
	}
	word_count = ft_count(s, c);
	return (split_words(s, c, word_count));
}
