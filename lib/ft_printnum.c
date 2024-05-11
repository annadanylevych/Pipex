/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:10:54 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 20:35:50 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i += 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	recursive_bucle(int n, int *err)
{
	if (n > 9)
	{
		recursive_bucle(n / 10, err);
		if (!*err)
			recursive_bucle(n % 10, err);
	}
	if (n < 10)
	{
		n = n + 48;
		if (write(1, &n, 1) == -1)
			*err = 1;
	}
}

int	ft_printnum(int n, int *err)
{
	int	i;

	i = digit(n);
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			*err = 1;
		return (i);
	}
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			*err = 1;
		n *= -1;
	}
	if (!*err)
		recursive_bucle(n, err);
	return (i);
}
