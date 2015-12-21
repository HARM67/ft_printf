/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroehly <mfroehly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:48:48 by mfroehly          #+#    #+#             */
/*   Updated: 2015/12/17 16:35:17 by mfroehly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *decode_color(char **p, int type)
{
	int color;

	(*p) +=3;
	if (strncmp(*p, "BLACK", 5) == 0)
	{
		*p += 5;
		color = 0;
	}
	else if (strncmp(*p, "RED", 3) == 0)
	{
		*p += 3;
		color = 1;
	}
	else if (strncmp(*p, "GREEN", 5) == 0)
	{
		*p += 5;
		color = 2;
	}
	else if (strncmp(*p, "YELLOW", 6) == 0)
	{
		*p += 6;
		color = 3;
	}
	else if (strncmp(*p, "BLUE", 4) == 0)
	{
		*p += 4;
		color = 4;
	}
	else if (strncmp(*p, "PINK", 4) == 0)
	{
		*p += 4;
		color = 5;
	}
	else if (strncmp(*p, "CYAN", 4) == 0)
	{
		*p += 4;
		color = 6;
	}
	else if (strncmp(*p, "GREY", 4) == 0)
	{
		*p += 4;
		color = 7;
	}
	else
		return (ft_strdup("{"));
	return (ft_itoa(color + type));
}

static char	*decode_type(char **p)
{
	if (strncmp(*p, "FG_",  3) == 0)
		return (decode_color(p, 30));
	else if (strncmp(*p, "BG_", 3) == 0)
		return (decode_color(p, 40));
	else if (strncmp(*p, "EOC",  3) == 0)
	{	
		*p +=3;
		return (ft_strdup("0"));
	}
	else if (strncmp(*p, "BOLD", 4) == 0)
	{
		*p += 4;
		return (ft_strdup("1"));
	}
	else if (strncmp(*p, "DARK", 4) == 0)
	{
		*p += 4;
		return (ft_strdup("2"));
	}
	else if (strncmp(*p, "ITALIC", 6) == 0)
	{
		*p += 6;
		return (ft_strdup("3"));
	}
	else if (strncmp(*p, "UNDERLINE", 9) == 0)
	{
		*p += 9;
		return (ft_strdup("4"));
	}
	else if (strncmp(*p, "FLASH", 5) == 0)
	{
		*p += 5;
		return (ft_strdup("5"));
	}
	else if (strncmp(*p, "HIGHLIGHT", 9) == 0)
	{
		*p += 9;
		return (ft_strdup("7"));
	}
	return (ft_strdup("{"));
}

void		make_color(const char **fmt, char **str, int *l)
{
	char *p;
	char *tmp;
	char *tmp2;
	int i;

	i = 0;
	p = (char *)*fmt;
	p++;
	while (*p != 0 && *p == ' ')
		p++;
	tmp = decode_type(&p);
	if (*tmp == '{')
	{
		i = (*l)++;
		(*fmt)++;
		ft_strncon(str, &tmp, i, 0x40 | 0x1 | 0x4 | 0x2 | 0x8 | 0x10);
		return ;
	}
	tmp2 = ft_strdup("\033[");
	ft_strncon(&tmp2, &tmp, 0, 0x2 | 0x8 | 0x20 | 0x1 | 0x4);
	tmp2 = ft_strdup("m");
	ft_strncon(&tmp, &tmp2, 0, 0x1 | 0x4 | 0x10 | 0x2 | 0x8);
	while (*p != 0 && *p == ' ')
		p++;
	if (*p == '}')
	{
		p++;
		(*fmt) = p;
		i = *l;
		*l += ft_strlen(tmp);
		ft_strncon(str, &tmp, i, 0x40 | 0x1 | 0x4 | 0x2 | 0x8 | 0x10);
		return ;
	}
	free(tmp);
	tmp = ft_strdup("{");
	i = (*l)++;
	ft_strncon(str, &tmp, i, 0x40 | 0x1 | 0x4 | 0x2 | 0x8 | 0x10);
	*l++;
	(*fmt)++;
}
