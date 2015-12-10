#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i = 8;

	i = ft_printf("%x %o %d", 250, 250, 250);
	printf("\n ft_printf retourne : %d caracteres \n", i);
	return (0);
}
