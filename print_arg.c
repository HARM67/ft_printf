#include "ft_printf.h"

static	void	read_base(const char **fmt, t_form *form)
{
	while (**fmt == ' ')
		(*fmt)++;
	form->signe = 0;
	form->maj = 0;
	form->letter = **fmt;
	if (**fmt == 'i' || **fmt == 'd' || **fmt == 'D')
	{
		form->signe = 1;
		form->base = 10;
	}
	else if (**fmt == 'u' || **fmt == 'U')
		form->base = 10;
	else if (**fmt == 'o' || **fmt == 'O')
		form->base = 8;
	else if (**fmt == 'x' || **fmt == 'X' || **fmt == 'p')
		form->base = 16;
	else if (**fmt == 'c' || **fmt == 'C')
		form->signe = -1;
	else if (**fmt == 's' || **fmt == 'S')
		form->signe = -2;
	else
		form->signe = -3;
	if (**fmt == 'D' || **fmt == 'U' || **fmt == 'O' || **fmt == 'X')
		form->maj = 1;
	(*fmt)++;
}

int	print_arg(const char **fmt, va_list *list)
{
	t_form	form;
	char *str;

	(*fmt)++;
	ft_bzero(&form, sizeof(t_form));
	read_flag(fmt, &form);
	read_base(fmt, &form);
	str = argtoa(&form, list);
	insert_flag(&str, &form);
	ft_putstr(str);
	return (ft_strlen(str));
}

