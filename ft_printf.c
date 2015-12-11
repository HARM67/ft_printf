#include "ft_printf.h"

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
