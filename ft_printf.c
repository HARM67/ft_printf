/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:47:16 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/16 18:36:33 by mfroehly         ###   ########.fr       */
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
			ft_strncon(&str, &tmp, l, ft_strlen(tmp), 0x1 | 0x4| 0x2 | 0x8 | 0x10);
			l += i;
		}
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			tmp = ft_strdup("%");
			ft_strncon(&str, &tmp, l, 1, 0x1 | 0x2 | 0x4 | 0x8 | 0x10);
			fmt += 2;
			l++;
		}
		else
		{
			tmp = (char*)fmt;
			ft_strncon(&str, &tmp, l, 1, 0x1 | 0x4 | 0x10);
			//str = ft_strncon(&str, &tmp, l, 1, 0x1);
			l++;
			fmt++;
		}
	}
	va_end(list);
	if (str != 0)
	{
		write(1, str, l);
		free (str);
	}
	return (l);
}
