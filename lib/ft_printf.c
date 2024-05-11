/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:21:13 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 20:35:13 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	check(va_list ap, const char *str, int *err)
{
	int	written;

	written = 0;
	if (str[0] == 'c')
		written = ft_printchar(va_arg(ap, int), err);
	if (str[0] == 's')
		written += ft_printstr(va_arg(ap, char *), err);
	if (str[0] == 'd' || str[0] == 'i')
		written += ft_printnum(va_arg(ap, int), err);
	if (str[0] == 'u')
		written += ft_printnumu(va_arg(ap, unsigned int), err);
	if (str[0] == 'x')
		written += ft_printhex(va_arg(ap, unsigned int), "0123456789abcdef",
				err);
	if (str[0] == 'X')
		written += ft_printhex(va_arg(ap, unsigned int), "0123456789ABCDEF",
				err);
	if (str[0] == 'p')
		written += ft_printptr(va_arg(ap, void *), err);
	if (str[0] == '%')
		written += ft_printchar('%', err);
	return (written);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	int		written;
	int		err;

	i = 0;
	err = 0;
	written = 0;
	va_start(ap, str);
	while (str[i] && !err)
	{
		if (str[i] == '%')
		{
			i++;
			written += check(ap, &str[i], &err);
		}
		else
			written += ft_printchar(str[i], &err);
		i++;
	}
	va_end(ap);
	if (err)
		return (-1);
	return (written);
}
/*
int	main(void)
{
	int		a;
	int		b;
	char	*s = "fgfgfgf  ";

	a = printf("address: %s\n", s);
	b = ft_printf("address: %s\n", s);
	printf("printf original devuelve: %d\n", a);
	printf("ft_printf me devulve: %d\n", b);
	return (0);
}*/
