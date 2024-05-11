/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:18:58 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 20:35:29 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digithex(unsigned int a)
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

static void	hex_bucle(unsigned int a, char *base, int *err)
{
	if (a > 15)
	{
		hex_bucle(a / 16, base, err);
		if (!*err)
			hex_bucle(a % 16, base, err);
	}
	if (a < 16)
	{
		if (write(1, &base[a], 1) == -1)
			*err = 1;
	}
}

int	ft_printhex(unsigned int a, char *base, int *err)
{
	int	ndigit;

	ndigit = digithex(a);
	if (a == 0)
	{
		if (write(1, "0", 1) == -1)
			*err = -1;
	}
	else
		hex_bucle(a, base, err);
	return (ndigit);
}
