/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:59:13 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/16 23:36:35 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	recursive_bucle(int n, int fd)
{
	if (n > 9)
	{
		recursive_bucle(n / 10, fd);
		recursive_bucle(n % 10, fd);
	}
	if (n < 10)
	{
		n = n + 48;
		write(fd, &n, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	recursive_bucle(n, fd);
}
