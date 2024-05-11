/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:30:41 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 20:32:08 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strleng(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoing(char *s1, char *s2)
{
	char	*join;
	int		len1;
	int		len2;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len1 = ft_strleng(s1);
	len2 = ft_strleng(s2);
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
	{
		free(s1);
		return (NULL);
	}
	join = ft_strjoin_copy(join, s1, s2);
	free(s1);
	return (join);
}

char	*ft_strjoin_copy(char *join, char *s1, char *s2)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = ft_strleng(s1);
	len2 = ft_strleng(s2);
	while (i < len1 + len2)
	{
		if (i < len1)
			join[i] = s1[i];
		else
			join[i] = s2[i - len1];
		i++;
	}
	join[i] = '\0';
	return (join);
}

char	*ft_substrg(char *s, int start, int len)
{
	char			*sub;
	int				i;

	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
