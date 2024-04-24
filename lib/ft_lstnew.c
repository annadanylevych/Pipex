/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 20:16:13 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/20 11:28:26 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*lol;

	lol = (t_list *)malloc(sizeof(t_list));
	if (!lol)
		return (NULL);
	lol->content = content;
	lol->next = NULL;
	return (lol);
}
