/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:07:19 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/15 21:54:48 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		b;

	count = 0;
	b = 0;
	while (*s)
	{
		if (*s != c && b == 0)
		{
			b = 1;
			count++;
		}
		else if (*s == c && b == 1)
			b = 0;
		else if (!*s)
			break ;
		s++;
	}
	return (count);
}

char	**free_matrix(char **split, size_t p)
{
	size_t	i;

	i = 0;
	while (i < p)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**bucle_split(char const *s, char c, char **split)
{
	size_t	i;
	size_t	start;
	size_t	p;

	i = 0;
	start = 0;
	p = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		split[p++] = ft_substr(s, start, i - start);
		if (split[p - 1] == NULL)
			return (free_matrix(split, p));
		while (s[i] && s[i] == c)
			i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	num_words;

	num_words = count_words(s, c);
	split = malloc(sizeof(char *) * (num_words + 1));
	if (!split)
		return (NULL);
	if (num_words > 0)
	{
		split = bucle_split(s, c, split);
		if (split == NULL)
			return (NULL);
	}
	split[num_words] = NULL;
	return (split);
}
/*
int	main(void)
{
	char const	*s;
	char		c;
	char		**w_array;

	//int i = 0;
	s = "       ";
	c = ' ';
	w_array = ft_split(s, c);
	printf("aqui %s\n", w_array[0]);
	while (*w_array)
	{
		printf("%s", *w_array);
		w_array++;
	}
	return (0);
}
*/
