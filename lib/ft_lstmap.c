/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:53:14 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/21 14:50:05 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lol;
	t_list	*new;
	void	*c;

	lol = NULL;
	while (lst)
	{
		c = f(lst->content);
		if (c)
		{
			new = ft_lstnew(c);
			if (new)
				ft_lstadd_back(&lol, new);
		}
		if (!c || !new)
		{
			free(c);
			ft_lstclear(&lol, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (lol);
}
