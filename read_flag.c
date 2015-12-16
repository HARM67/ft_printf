/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 22:05:36 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/16 14:16:00 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	read_precision(const char **fmt, t_form *form, va_list *list)
{
	int tmp;

	(*fmt)++;
	if (**fmt == '*')
	{
		tmp = va_arg(*list, int);
		if (tmp >= 0)
		{
			form->precision = tmp;
			form->point = 1;
		}
		return ;
	}
	else
		form->precision = ft_atoi(*fmt);
	form->point = 1;
	while (ft_isdigit(**fmt))
		(*fmt)++;
	(*fmt)--;
}

static char	is_flag(char c)
{
	if (c == '#' || c == ' ' || c == '-' ||
			c == '+' || ft_isdigit(c) || c == 'h' ||
			c == 'l' || c == 'j' || c == 'z' || c == '.' || c == '*')
		return (1);
	return (0);
}

void		set_size(const char **fmt, t_form *form)
{
	if (form->l_flag)
	{
		if (form->l_flag % 2)
			form->size = sizeof(long int);
		else
			form->size = sizeof(long long int);
	}
	else if (form->j_flag)
		form->size = sizeof(intmax_t);
	else if (form->z_flag)
		form->size = sizeof(size_t);
	else if (form->h_flag)
	{
		if (form->h_flag % 2)
			form->size = sizeof(short int);
		else
			form->size = sizeof(char);
	}
	else
		form->size = sizeof(int);
}

void		normalize_flag(const char **fmt, t_form *form)
{
	if (form->moin)
		form->zero = 0;
	if (form->plus)
		form->space = 0;
//if (form->point)
//		form->diese = 0;
//	if (form->point)
//		form->zero = 0;
}

static void		read_longueur(const char **fmt, t_form *form, va_list *list)
{
	if (**fmt == '*')
	{
		form->longueur = va_arg(*list, int);
		if (form->longueur < 0)
		{
			form->longueur = - form->longueur;
			form->moin = 1;
		}
		return ;
	}
	else
		form->longueur = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	(*fmt)--;

}

void		read_flag(const char **fmt, t_form *form, va_list *list)
{
	while (is_flag(**fmt))
	{
		if (**fmt == '#')
			form->diese = 1;
		else if (**fmt == '0')
			form->zero = 1;
		else if (**fmt == ' ')
			form->space = 1;
		else if (**fmt == '-')
			form->moin = 1;
		else if (**fmt == '+')
			form->plus = 1;
		else if (**fmt == '.')
			read_precision(fmt, form, list);
		else if (ft_isdigit(**fmt) || **fmt == '*')
			read_longueur(fmt, form, list);
		else if (**fmt == 'l')
			form->l_flag++;
		else if (**fmt == 'j')
			form->j_flag++;
		else if (**fmt == 'h')
			form->h_flag++;
		else if (**fmt == 'z')
			form->z_flag++;
		(*fmt)++;
	}
}
