/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:52:17 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/16 16:32:23 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*uinttoa_base(t_form *form, va_list *list)
{
	unsigned long int tmp;

	tmp = (unsigned long int)va_arg(*list, unsigned long int);
	if (((form->letter == 'o'|| form->letter == 'O')  && tmp == 0 && form->point == 0) || ((form->letter == 'x' || form->letter == 'X') && tmp == 0))
		form->diese = 0;
	if (form->size == 8 || form->letter == 'O' || form->letter == 'U' ||
			form->letter == 'p')
		return (uitoa_base_8(tmp, form->base));
	else if (form->size == 1)
		return (uitoa_base_1((unsigned char)tmp, form->base));
	else if (form->size == 2)
		return (uitoa_base_2((unsigned short int)tmp, form->base));
	else if (form->size == 4)
		return (uitoa_base_4((unsigned int)tmp, form->base));
	return (0);
}

static char	*inttoa(t_form *form, va_list *list)
{
	long int tmp;

	tmp = (long int)va_arg(*list, long int);
	if (form->size == 8 || ft_isupper(form->letter))
		return (itoa_8(tmp));
	else if (form->size == 1)
		return (itoa_8((char)tmp));
	else if (form->size == 2)
		return (itoa_8((short int)tmp));
	else if (form->size == 4)
		return (itoa_8((int)tmp));
	return (0);
}

static char	*stoa(t_form *form, va_list *list)
{
	char c[5];
	char *p;
	int *i;

	ft_bzero(c, 5);
	if (form->signe == -1)
	{
		c[0] = va_arg(*list, int);
		return (ft_strdup(c));
	}
	else if (form->signe == -2)
	{
		p = va_arg(*list, char *);
		if (p != 0)
		{
			p = ft_strdup(p);
			if (form->point && (ft_strlen(p) > form->precision))
				p[form->precision] = '\0';
		}
		else if (form->point == 0)
			p = ft_strdup("(null)");
		else
			p = ft_strdup("\0");
			return (p);
	}
	else if (form->signe == -3)
	{
		c[0] = form->letter;
		form->letter = 'c';
		return (ft_strdup(c));
	}
	else if (form->signe == -4)
		return (itounicode((int)va_arg(*list, int)));
	else if (form->signe == -5)
	{
		i = va_arg(*list, int *);
		if (i != 0)
			return (ltostr(i, (form->point) ? form->precision : -1));
		else if (form->point == 0)
			return (ft_strdup("(null)"));
		else
			return (ft_strdup("\0"));
	}
	return (0);
}

char		*argtoa(t_form *form, va_list *list)
{
	char *rt;

	rt = 0;
	if (form->signe >= -5 && form->signe < 0)
		rt = stoa(form, list);
	else if (form->signe == 0)
		rt = uinttoa_base(form, list);
	else if (form->signe == 1)
		rt = inttoa(form, list);
	else if (form->signe == -6)
		rt = ftoa(va_arg(*list, double), 6);
	if ((form->letter == 'c' || form->letter == 'C') && *rt == '\0')
		form->length = 1;
	else
		form->length = ft_strlen(rt);
	if ((form->signe == 0 || form->signe == 1 || form->signe == -6) && *rt == '-')
	{
		form->length--;
	}
	if ((form->signe == 0 || form->signe == 1) && form->point && *rt == '0')
	{
		free(rt);
		rt = strdup("\0");
		form->length = 0;
	}
	return (rt);
}
