/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:24:33 by adanylev          #+#    #+#             */
/*   Updated: 2023/12/16 20:36:09 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s, int *err)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] && !*err)
	{
		ft_printchar(s[i], err);
		i++;
	}
	return (i);
}
