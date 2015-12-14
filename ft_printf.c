/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:47:16 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/14 06:46:17 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	list;
	int		l;
	int i;
	char *str;
	char *tmp;

	l = 0;
	i = 0;
	str = 0;
	va_start(list, fmt);
	while (*fmt != 0)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
		{
			tmp = print_arg(&fmt, &list, &i);
			ft_strncon(&str, tmp, l, i);
			ft_bzero (tmp, i);
			free (tmp);
			tmp = 0;
			l += i;
		}
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			ft_strncon(&str, "%", l, 1);
			fmt += 2;
			l++;
		}
		else
		{
			ft_strncon(&str, fmt, l, 1);
			l++;
			fmt++;
		}
	}
	va_end(list);
	if (str != 0)
		ft_putstr(str);
	return (l);
}
