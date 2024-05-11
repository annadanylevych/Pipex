/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:47:51 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 20:36:03 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digithexl(unsigned long a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

static void	hexl_bucle(unsigned long a, char *base, int *err)
{
	if (a > 15)
	{
		hexl_bucle(a / 16, base, err);
		if (!*err)
			hexl_bucle(a % 16, base, err);
	}
	if (a < 16)
		if (write(1, &base[a], 1) == -1)
			*err = 1;
}

int	ft_printhexl(unsigned long a, char *base, int *err)
{
	int	ndigit;

	ndigit = digithexl(a);
	if (a == 0)
		ft_printchar('0', err);
	else
		hexl_bucle(a, base, err);
	return (ndigit);
}

int	ft_printptr(void *ptr, int *err)
{
	unsigned long	new_ptr;
	char			*base;
	int				written;

	written = 0;
	base = "0123456789abcdef";
	new_ptr = (unsigned long)ptr;
	if (!*err)
		written = ft_printstr("0x", err);
	if (!*err)
		written += ft_printhexl(new_ptr, base, err);
	return (written);
}
