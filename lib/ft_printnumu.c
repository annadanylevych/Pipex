/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:53:43 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 20:35:57 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digitu(unsigned int n)
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

static void	recursive_bucleu(unsigned int n, int *err)
{
	if (n > 9)
	{
		recursive_bucleu(n / 10, err);
		if (!*err)
			recursive_bucleu(n % 10, err);
	}
	if (n < 10)
	{
		n = n + 48;
		if (write(1, &n, 1) == -1)
			*err = 1;
	}
}

int	ft_printnumu(unsigned int n, int *err)
{
	int	i;

	i = digitu(n);
	if (!*err)
		recursive_bucleu(n, err);
	return (i);
}
