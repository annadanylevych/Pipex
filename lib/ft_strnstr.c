/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:55:08 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/17 19:47:11 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;

	a = 0;
	i = 0;
	if (needle[a] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		while (haystack[i + a] == needle[a] && i + a < len)
		{
			a++;
			if (needle[a] == '\0')
				return ((char *)&haystack[i]);
			else if (haystack[i + a] == '\0')
				return (0);
			else if (haystack[i + a] != needle[a])
			{
				a = 0;
				break ;
			}
		}
		i++;
	}
	return (0);
}
