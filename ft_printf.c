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
	char tt[1024];

	l = 0;
	i = 0;
	str = 0;
	va_start(list, fmt);
	ft_bzero(tt, 1024);
	while (*fmt != 0)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
		{
			tmp = print_arg(&fmt, &list, &i);
			ft_strncon(&str, tmp, l, i);
			//free (tmp);
			l += i;
		}
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			//ft_putchar('%');
			ft_strncon(&str, "%", l, 1);
			//ft_strcat(tt, "%");
			fmt += 2;
			l++;
		}
		else
		{
			ft_strncon(&str, fmt, l, 1);
			//ft_strncat(tt, fmt, 1);
			//ft_putchar(*fmt);
			l++;
			fmt++;
		}
	}
	va_end(list);
	ft_putstr(str);
	return (l);
}
