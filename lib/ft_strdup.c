/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:44:14 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/15 21:44:08 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ps1;
	char	*start;

	ps1 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!ps1)
		return (NULL);
	start = ps1;
	while (*s1)
	{
		*ps1 = *s1;
		ps1++;
		s1++;
	}
	*ps1 = '\0';
	return (start);
}
