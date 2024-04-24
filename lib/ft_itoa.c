/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:40:14 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/16 21:52:03 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	digit(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i += 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_putnbr(char *aux, int n)
{
	int	i;
	int	len;

	len = digit(n);
	i = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		aux[len - i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	if (n < 10)
	{
		aux[len - i] = n + '0';
	}
	aux[len] = '\0';
	return (aux);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (digit(n) + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str = ft_putnbr(str, n);
	return (str);
}
