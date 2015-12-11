#include "ft_printf.h"
#include <stdio.h>

void	test(char *str, long int i)
{
	int rt;
	int rt2;

	printf("   printf(\"%s\") : '", str);
	rt = printf(str, i);
	printf("' = %d\n", rt);
	ft_printf("ft_printf(\"%s\") : '", str);
	rt2 = ft_printf(str, i);
	ft_printf("' = %d\n\n", rt2);
}

int main()
{
	test("%d", 50);
	test("% d", 50);
	test("%+d", 50);
	test("% +d", 50);
	test("%-d", 50);
	test("%0d", 50);
	test("%0-d", 50);
	test("%-08d", 50);
	test("% 08d", 50);
	test("% -08d", 50);
	test("% -+08d", 50);
	test("% -08d", 50);
	test("% +8d", 50);
	test("% -8d", 50);
	

	test("%x", 50);
	test("% x", 50);
	test("%+x", 50);
	test("% +x", 50);
	test("%-x", 50);
	test("%0x", 50);
	test("%#0-x", 50);
	test("%-08x", 50);
	test("%# 08x", 50); // 0xconsidere comme un signe
	test("% -08x", 50);
	test("%# -+08x", 50);
	test("% -08x", 50);
	test("%# +8x", 50);
	test("%# -8x", 50);
	

	test("%o", 50);
	test("% o", 50);
	test("%+o", 50);
	test("% +o", 50);
	test("%-o", 50);
	test("%0o", 50);
	test("%#0-o", 50);
	test("%-08o", 50);
	test("%# 08o", 50);
	test("% -08o", 50);
	test("%# -+08o", 50);
	test("% -08o", 50);
	test("%# +8o", 50);
	test("%# -8o", 50);


	test("%u", 50);
	test("% u", 50);
	test("%+u", 50);
	test("% +u", 50);
	test("%-u", 50);
	test("%0u", 50);
	test("%#0-u", 50);
	test("%-08u", 50);
	test("%# 08u", 50);
	test("% -08u", 50);
	test("%# -+08u", 50);
	test("% -08u", 50);
	test("%# +8u", 50);
	test("%# -8u", 50);

	test("%p", 50);
	test("% p", 50);
	test("%+p", 50);
	test("% +p", 50);
	test("%-p", 50);
	test("%0p", 50);
	test("%#0-p", 50);
	test("%-08p", 50);
	test("%# 08p", 50);
	test("% -08p", 50);
	test("%# -+08p", 50);
	test("% -08p", 50);
	test("%# +8p", 50);
	test("%# -8p", 50);

	test("%c", 50);
	test("% c", 50);
	test("%+c", 50);
	test("% +c", 50);
	test("%-c", 50);
	test("%0c", 50);
	test("%#0-c", 50);
	test("%-08c", 50);
	test("%# 08c", 50);
	test("% -08c", 50);
	test("%# -+08c", 50);
	test("% -08c", 50);
	test("%# +8c", 50);
	test("%# -8c", 50);


	test("%s", "Mat");
	test("% s", "Mat");
	test("%+s", "Mat");
	test("% +s", "Mat");
	test("%-s", "Mat");
	test("%0s", "Mat");
	test("%#0-s", "Mat");
	test("%-08s", "Mat");
	test("%# 08s", "Mat");
	test("% -08s", "Mat");
	test("%# -+08s", "Mat");
	test("% -08s", "Mat");
	test("%# +8s", "Mat");
	test("%# -8s", "Mat");

	test("%d", (long int)7850);
	test("%hd", (long int)7850);
	test("%hhd", (long int)7850);
	test("%hhhd", (long int)7850);
	test("%hhhhd", (long int)7850);
	test("%lhhhhd", (long int)7850);
	test("%hhhhld", (long int)7850);

	test("%d", 3000000000);
	test("%ld", 3000000000);
	test("%lld", 3000000000);
	test("%llld", 3000000000);
	test("%lllld", 3000000000);
	test("%hlhld", 3000000000);
	test("%lhhhd", 3000000000);

	test("%9d", (long int)7850);
	test("%h9d", (long int)7850);
	test("%h9hd", (long int)7850);
	test("%h9hhd", (long int)7850);
	test("%hh9hhd", (long int)7850);
	test("%lhh9hhd", (long int)7850);
	test("%hh9hhld", (long int)7850);

	test("%d", (long int)7850);
	test("%h9d", (long int)7850);
	test("%hhd", (long int)7850);
	test("%h-+ hhd", (long int)7850);
	test("%hhhhd", (long int)7850);
	test("%lh-+ 9hhhd", (long int)7850);
	test("%h4h0hh9ld", (long int)7850);
	test("%lh- 9hhhd", (long int)7850);

	test("%x", (long int)7850);
	test("%h9x", (long int)7850);
	test("%hhu", (long int)7850); //
	test("%h-+ h#hx", (long int)7850);
	test("%hhhhx", (long int)7850); //
	test("%lh-+i# 9hhh  x", (long int)7850);
	test("%h4h0hh9lx", (long int)7850);
	test("%lh- 9hhhx", (long int)7850);

	test("%% %d", (long int)7850);
	test("%d %%", (long int)7850);

	test("  %s  ", 0);
	return (0);
}
