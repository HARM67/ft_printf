#include "ft_printf.h"

static char *uinttoa_base(t_form *form, va_list *list)
{
	unsigned long int tmp;

	tmp = (unsigned long int)va_arg(*list, unsigned long int);
	if (form->size == 1)
		return (uitoa_base_1((unsigned char)tmp, form->base));
	else if (form->size == 2)
		return (uitoa_base_2((unsigned short int)tmp, form->base));
	else if (form->size == 4)
		return (uitoa_base_4((unsigned int)tmp, form->base));
	else if (form->size == 8)
		return (uitoa_base_8(tmp,form->base));
	return (0);
}

static char *inttoa(t_form *form, va_list *list)
{
	long int tmp;

	tmp = (long int)va_arg(*list, long int);
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

char	*argtoa(t_form* form, va_list *list)
{
	char c[2];
	char *p;

	c[1] = 0;
	if (form->signe == -1)
	{
		c[0] = va_arg(*list, int);
		return (ft_strdup(c));
	}
	else if (form->signe == -2)
	{
		p = va_arg(*list, char *);
		if (p != 0)
			return (ft_strdup(p));
		else
			return (ft_strdup("(null)"));
	}
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

