/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:47:16 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/12 04:07:17 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	list;
	int		l;

	l = 0;
	va_start(list, fmt);
	while (*fmt != 0)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
			print_arg(&fmt, &list, &l);
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			ft_putchar('%');
			fmt += 2;
			l++;
		}
		else
		{
			l++;
			ft_putchar(*fmt);
			fmt++;
		}
	}
	va_end(list);
	return (l);
}
