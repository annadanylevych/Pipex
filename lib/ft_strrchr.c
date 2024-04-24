/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:31:28 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/15 21:53:16 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (s[i] != (char)c && i > 0)
		i--;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
