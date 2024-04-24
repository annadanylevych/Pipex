/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:59:18 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/15 21:54:36 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdest;
	unsigned const char	*psrc;

	pdest = (unsigned char *)dst;
	psrc = (unsigned const char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (n == 0)
		return (dst);
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dst);
}
