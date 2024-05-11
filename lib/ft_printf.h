/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adanylev <adanylev@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:22:47 by adanylev          #+#    #+#             */
/*   Updated: 2023/09/27 14:26:33 by adanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(char c, int *err);
int	ft_printstr(char *s, int *err);
int	ft_printnum(int n, int *err);
int	ft_printnumu(unsigned int n, int *err);
int	ft_printhex(unsigned int a, char *base, int *err);
int	ft_printptr(void *ptr, int *err);

#endif
