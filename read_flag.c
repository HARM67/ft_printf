#include "ft_printf.h"

static void		set_size(const char **fmt, t_form *form)
{
	if (form->l_flag)
	{
		if (form->l_flag % 2)
			form->size = sizeof(long int);
		else
			form->size = sizeof(long long int);
	}
	else if (form->h_flag)
	{
		if (form->h_flag % 2)
			form->size = sizeof(short int);
		else
			form->size = sizeof(char);
	}
	else if (form->j_flag)
		form->size = sizeof(intmax_t);
	else if (form->z_flag)
		form->size = sizeof(size_t);
	else
		form->size = sizeof(int);
}

static void		read_precision(const char **fmt, t_form *form)
{
	form->precision = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	(*fmt)--;
}

static char is_flag(char c)
{
	if (c == '#' || c == ' ' || c == '-' ||
			c == '+' || ft_isdigit(c) || c == 'h' ||
			c == 'l' || c == 'j' || c == 'z')
			return (1);
	return (0);
}


static void	normalize_flag(const char **fmt, t_form *form)
{
	if (form->moin)
		form->zero = 0;
	if (form->plus)
		form->space = 0;
}

void	read_flag(const char **fmt, t_form *form)
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
		else if (ft_isdigit(**fmt))
			read_precision(fmt, form);
		else if (**fmt == 'l')
			form->l_flag ++;
		else if (**fmt == 'j')
			form->j_flag ++;
		else if (**fmt == 'h')
			form->h_flag ++;
		else if (**fmt == 'z')
			form->z_flag++;
		(*fmt)++;
	}
	normalize_flag(fmt, form);
	set_size(fmt, form);
}

