/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:54:21 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/14 04:32:30 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_precision(char **str, t_form *form)
{
	int		len;
	char	*tmp;

	len = form->length;
	//if (form->signe && form->positive == 0)
	//	len--;
	if (form->devant != 0 && form->point == 0)
		len += ft_strlen(form->devant);
	if (len >= form->precision)
		return (ft_strdup("\0"));
	tmp = ft_memalloc(form->precision - len + 1);
	if (form->zero && form->moin == 0)
		ft_memset(tmp, '0', form->precision - len);
	else
		ft_memset(tmp, ' ', form->precision - len);
	form->length += ft_strlen(tmp);

	return (tmp);
}

static void	retirer_signe(char **str, t_form *form)
{
	char *tmp;

	if (**str != '-' || form->letter == 'c' || form->letter == 'C' ||
			form->letter == 's' || form->letter == 'S')
	{
		form->positive = 1;
		return ;
	}
	tmp = ft_strdup((*str) + 1);
	free(*str);
	*str = tmp;
}

static void	make_devant(t_form *form)
{
	if (form->letter == 'c' || form->letter == 's' || form->letter == 'C' ||
		form->letter == 'S')
		return ;
	if (form->positive == 0)
		form->devant = ft_strdup("-");
	else if (form->plus && form->signe && form->positive)
		form->devant = ft_strdup("+");
	else if (form->space && form->signe)
		form->devant = ft_strdup(" ");
	else if (form->diese && (form->letter == 'o' || form->letter == 'O'))
		form->devant = ft_strdup("0");
	else if ((form->diese && (form->letter == 'x' || form->letter == 'X')) ||
		form->letter == 'p')
		form->devant = ft_strdup("0x");
	else
		form->devant = 0;
}

void		insert_flag(char **str, t_form *form)
{
	char	*precision;
	char	*tmp;

	retirer_signe(str, form);
	make_devant(form);
	precision = make_precision(str, form);
	if (form->devant != 0)
		form->length += ft_strlen(form->devant);
	if (form->zero && form->moin == 0)
	{
		tmp = ft_strjoin(precision, *str);
		if (form->devant)
			tmp = ft_strjoin(form->devant, tmp);
		*str = tmp;
	}
	else
	{
		if (form->devant)
			tmp = ft_strjoin(form->devant, *str);
		else
			tmp = *str;
		if (form->zero == 0 && form->moin == 0)
			tmp = ft_strjoin(precision, tmp);
		else
			tmp = ft_strjoin(tmp, precision);
		*str = tmp;
	}
}
