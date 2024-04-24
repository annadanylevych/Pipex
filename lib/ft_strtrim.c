/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:54:50 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/15 21:45:25 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	i = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (ft_strlen(s1) > 0)
		trim = malloc(sizeof(char) * (end - start + 2));
	else
		trim = malloc(sizeof(char) * (end - start + 1));
	if (!trim)
		return (NULL);
	while (end > 0 && start < end + 1)
		trim[i++] = s1[start++];
	trim[i] = '\0';
	return (trim);
}
