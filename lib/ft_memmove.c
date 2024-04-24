/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:30:43 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/15 22:53:17 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	if (psrc < pdst)
	{
		while (len > 0)
		{
			pdst[len - 1] = psrc[len - 1];
			len--;
		}
	}
	else if (psrc > pdst && len != 0)
	{
		while (i++ < len)
			pdst[i - 1] = psrc[i - 1];
	}
	return (dst);
}
