#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

void	test_f(char *str, double i)
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
void	test2(char *str, long int i, long int j)
{
	int rt;
	int rt2;

	printf("   printf(\"%s\") : '", str);
	rt = printf(str, i, j);
	printf("' = %d\n", rt);
	ft_printf("ft_printf(\"%s\") : '", str);
	rt2 = ft_printf(str, i, j);
	ft_printf("' = %d\n\n", rt2);
}

int main()
{
	setlocale(LC_ALL, "");
	int i;

i = 0;
/*
	test("%p", &i);
	test("%d", -42);
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
	test("%hd", (long int)7850);
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

	test("%d", (long int)7850);
	test("%hd", (long int)7850);
	test("%hhd", (long int)7850);
	test("%hhhd", (long int)7850);
	test("%hhhhd", (long int)7850);
	test("%o", (long int)7850);
	test("%ho", (long int)7850);
	test("%hho", (long int)7850);
	test("%hhho", (long int)7850);
	test("%hhhho", (long int)7850);
	test("%u", (long int)7850);
	test("%hu", (long int)7850);
	test("%hhu", (long int)7850);
	test("%hhhu", (long int)7850);
	test("%hhhhu", (long int)7850);
	test("%x", (long int)7850);
	test("%hx", (long int)7850);
	test("%hhx", (long int)7850);
	test("%hhhx", (long int)7850);
	test("%hhhhx", (long int)7850);

	test("%c", 1);
	test("%c df", '\0');
	test("%s", "sdf\0sdf");

	test2("%c %c", '\0', '#');
	test2("%c %c", '#', '\0');
	test2("%s %0-8d", "Salut mec", 42);
	test2("%s %0+8d", "Salut mec", 42);
	test2("%s %0+-d", "Salut mec", 42);
	test2("%s %0+-o", "Salut mec", 42);
	test2("%s %0+-x", "Salut mec", 42);
	test2("%s %0+--#xo", "Salut mec", 42);
	test2(" %0+--#xo   - + --# %s", 42, "test");
	test2(" %0+--#cxo   - + --# %s", '\0', "test");
	test2(" %0+--#cxo   - + --# %s", 1, "test");
	test("%-8c", '\0');
	test("%h-h9d", 7850);

	test("%+X", 30000000000);
	test("%+x", 30000000000);

	test("%zhu", 30000000000);
	test("%jhu", 30000000000);
	test("%hzu", 30000000000);
	test("%hU", 30000000000);

	ft_printf("%d", -42);
	test("%p", &i);
	printf("%S", L"米\n");
	test("%D", LLONG_MIN - 1);
		test("%D", LLONG_MIN - 1);
	test("%04s", "42");
	ft_printf("Salut");
	ft_printf("");
	ft_printf("%#x %#x", 42, 42);
	test("{%03.2d}", 0);
	test("{%3.2d}", 0);
	test("{%+03.2d}", 0);
	test("{%03.2d}", -3);
	test("{%.4d}", 42);
	test("{%4d}", 42);
	test("{%05.2d}", 0);
	test("{%05.2d}", -42);
	test("{%010.5d}", -42);
	test("{%10.5d}", -42);
	test("{%010d}", -42);
	test("{%10d}", -42);
	test("{%10.d}", -42);
	test("{%-010.5d}", -42);
	test("{%-10.5d}", -42);
	test("{%010.5.1d}", -42);
	test("{%10.5.1d}", -42);
	test2("%.d, %.0d", 0, 0);
	test("%#.O", 0);
	test("%#O", 0);
	test("%#.O", 1);
	test("%#O", 1);
	test("%.O", 0);
	test("%O", 0);
	test("%.O", 1);
	test("%O", 1);
	test("%.3%", 0);
	test("%.3r", 0);
	test("{%10R}", 0);
	test2("%#.x, %#.0x", 0, 0);
	test("%.4s", "42");
	test("%.4s", "42 is the answer");
	test("%.0C", L'我');
	test("%.1C", L'我');
	test("%.2C", L'"我');
	test("%.3C", L'我');
	test("%.4C", L'我');
	test("%.5C", L'我');
	test("%.S", L"我是一只猫。");
	test("%.0S", L"我是一只猫。");
	test("%.3S", L"我是一只猫。");
	test("%.4S", L"我是一只猫。");
	test("%.5S", L"我是一只猫。");
	test("%.6S", L"我是一只猫。");
	test("%.7S", L"我是一只猫。");
	test("%.8S", L"我是一只猫。");
	test("%05.c", 0);
	test("%05.C", 0);
	test("%05.s", 0);
	test("%05.S", 0);
	test("%010.s", 0);
	test("%010.S", 0);
	test("%010s", 0);
	test("%010S", 0);
	test("%#.O", 0);
	test("%#.3o", 1);
	test2("%*d", 5, 42);
	test2("%*d", 15, 42);
	test2("%*d", -5, 42);
	printf("{%c}\n", '\0');
ft_putchar('\n');
	ft_printf("{%c}", '\0');
	printf("{%c}", 0);
	*/
	//printf("{%C,}%cpoiusdf%d\n",L'米' ,0, L'米');
	//printf("%.2f",12345678912345.12611);
	//ft_printf("{%c, %hhC}", 0, L'米');
	//test_f("%f", 1.42);
	//test_f("%f", -1.42);
	//test_f("{%f}{%F}", 1444565444646.6465424242242);

	//test2("{%05.*d}", -15, 42);
	/*double a, b;

	b = a = 123456789.123456789;
	printf("%f    %f\n", a /= 10, b / 10);
	*/
	ft_printf("{%-15c}", 0);
	return (0);
}
