#include "ft_printf.h"

static char	*argtoa(t_form* form, va_list *list)
{
	char *str;
	t_arg arg;

	str = 0;
	if (form->signe == -1)
		str = ft_strdup("c");
	else if (form->signe == -2)
		str = ft_strdup("str");
	else if (form->signe == 0)
	{
		arg.uli = va_arg(*list, unsigned long int);
		str = uitoa_base(arg.uli, form->base);
	}
	else if (form->signe == 1)
	{
		arg.li = va_arg(*list, long int);
		if (form->size == 4)
			str = itoa_4(arg.li);
	}
	return (str);
}

static	void	read_base(const char **fmt, t_form *form)
{
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
		ft_putendl("error");
	if (**fmt == 'D' || **fmt == 'U' || **fmt == 'O' || **fmt == 'X')
		form->maj = 1;
	(*fmt)++;
}

static	void	read_flag2(const char **fmt, t_form *form)
{
	if (ft_strncmp(*fmt, "hh", 2) == 0)
		form->size = sizeof(char);
	else if (ft_strncmp(*fmt, "ll", 2) == 0)
		form->size = sizeof(long long int);
	else if (ft_strncmp(*fmt, "h", 1) == 0)
		form->size = sizeof(short int);
	else if (ft_strncmp(*fmt, "l", 1) == 0)
		form->size = sizeof(long int);
	else if (ft_strncmp(*fmt, "j", 1) == 0)
		form->size = sizeof(intmax_t);
	else if (ft_strncmp(*fmt, "z", 1) == 0)
		form->size = sizeof(size_t);
	if (ft_strncmp(*fmt, "hh", 2) == 0 || ft_strncmp(*fmt, "ll", 2) == 0)
		(*fmt) += 2;
	else if (ft_strncmp(*fmt, "h", 1) == 0 || ft_strncmp(*fmt, "l", 1) == 0 ||
			ft_strncmp(*fmt, "j", 1) == 0 || ft_strncmp(*fmt, "z", 1) == 0 )
		(*fmt)++;
}


static void	read_flag(const char **fmt, t_form *form)
{
	while (**fmt == '#' || **fmt == '0' || **fmt == ' ' || **fmt == '-' ||
			**fmt == '+')
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
		(*fmt)++;
	}
}

static int	print_arg(const char **fmt, va_list *list)
{
	t_form	form;
	char *str;

	(*fmt)++;
	ft_bzero(&form, sizeof(t_form));
	read_flag(fmt, &form);
	read_flag2(fmt, &form);
	read_base(fmt, &form);
	str = argtoa(&form, list);
	ft_putstr(str);
	return (ft_strlen(str));
}


int	ft_printf(const char *fmt, ...)
{
	va_list list;
	va_start(list, fmt);
	int l;

	l = 0;
	while (*fmt != 0)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
			l += print_arg(&fmt, &list);
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			ft_putchar('%');
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
