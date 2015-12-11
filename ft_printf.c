#include "ft_printf.h"

char	*make_precision(char **str, t_form *form)
{
	int len;
	char *tmp;

	len = ft_strlen(*str);
	if (form->devant != 0)
		len += ft_strlen(form->devant);
	if (len >= form->precision)
		return ft_strdup("\0");
	tmp = ft_memalloc(form->precision - len + 1);
	if (form->zero && form->moin == 0)
		ft_memset(tmp, '0', form->precision - len);
	else
		ft_memset(tmp, ' ', form->precision - len);
	return (tmp);
}

static void	retirer_signe(char **str, t_form *form)
{
	char *tmp;

	if (**str != '-')
	{
		form->positive = 1;
		return ;
	}
	tmp = ft_strdup((*str) + 1);
	free(*str);
	*str = tmp;
}

static void make_devant(t_form *form)
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
	else if (form->diese && form->letter == 'o')
		form->devant = ft_strdup("0");
	else if ((form->diese && (form->letter == 'x' || form->letter == 'X')) ||
		form->letter == 'p')
		form->devant = ft_strdup("0x");
	else
		form->devant = 0;
}

static void insert_flag(char **str, t_form* form)
{
	char *precision;
	char *tmp;

	retirer_signe(str, form);
	make_devant(form);
	precision = make_precision(str, form);
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

static char *uinttoa_base(t_form *form, va_list *list)
{
	if (form->size == 1)
		return (uitoa_base_1((unsigned char)va_arg(*list, long int), form->base));
	else if (form->size == 2)
		return (uitoa_base_2((unsigned short int)va_arg(*list, long int), form->base));
	else if (form->size == 4)
		return (uitoa_base_4((unsigned int)va_arg(*list, long int), form->base));
	else if (form->size == 8)
		return (uitoa_base_8((unsigned long int)va_arg(*list, long int),form->base));
	return (0);
}

static char *inttoa(t_form *form, va_list *list)
{
	long int tmp;

	tmp = va_arg(*list, long int);
	if (form->size == 1)
		return (itoa_1((char)tmp));
	else if (form->size == 2)
		return (itoa_2((short int)tmp));
	else if (form->size == 4)
		return (itoa_4((int)tmp));
	else if (form->size == 8)
		return (itoa_8(tmp));
	return (0);
}

static char	*argtoa(t_form* form, va_list *list)
{
	char c[2];

	c[1] = 0;
	if (form->signe == -1)
	{
		c[0] = va_arg(*list, int);
		return (ft_strdup(c));
	}
	else if (form->signe == -2)
		return (ft_strdup(va_arg(*list, char *)));
	else if (form->signe == -3)
	{
		c[0] = form->letter;
		form->letter = 'c';
		return (ft_strdup(c));
	}
	else if (form->signe == 0)
		return (uinttoa_base(form, list));
	else if (form->signe == 1)
		return (inttoa(form, list));
	return (0);
}

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
	else 
		form->size = sizeof(int);
	if (ft_strncmp(*fmt, "hh", 2) == 0 || ft_strncmp(*fmt, "ll", 2) == 0)
		(*fmt) += 2;
	else if (ft_strncmp(*fmt, "h", 1) == 0 || ft_strncmp(*fmt, "l", 1) == 0 ||
			ft_strncmp(*fmt, "j", 1) == 0 || ft_strncmp(*fmt, "z", 1) == 0 )
		(*fmt)++;
}

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

void		read_precision(const char **fmt, t_form *form)
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

static void	read_flag(const char **fmt, t_form *form)
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
}

static void	normalize_flag(const char **fmt, t_form *form)
{
	if (form->moin)
		form->zero = 0;
	if (form->plus)
		form->space = 0;
}


static int	print_arg(const char **fmt, va_list *list)
{
	t_form	form;
	char *str;

	(*fmt)++;
	ft_bzero(&form, sizeof(t_form));
	read_flag(fmt, &form);
	normalize_flag(fmt, &form);
//	read_precision(fmt, &form);
//	read_flag2(fmt, &form);
	set_size(fmt, &form);
	read_base(fmt, &form);
	str = argtoa(&form, list);
	insert_flag(&str, &form);
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
