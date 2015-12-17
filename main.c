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

void	testn(char *str)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	printf(str, &i);
	ft_printf(str, &i2);
	printf("\n   printf : %d\n", i);
	printf("ft_printf : %d\n", i2);
}

void	testn2(char *str, long int l)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	printf(str, l, &i);
	ft_printf(str, l, &i2);
	printf("\n   printf : %d\n", i);
	printf("ft_printf : %d\n", i2);
}

int main()
{
	setlocale(LC_ALL, "");
	int i;

i = 0;
/*
	ft_printf("%p", &i);
	ft_printf("%d", -42);
	ft_printf("% d", 50);
	ft_printf("%+d", 50);
	ft_printf("% +d", 50);
	ft_printf("%-d", 50);
	ft_printf("%0d", 50);
	ft_printf("%0-d", 50);
	ft_printf("%-08d", 50);
	ft_printf("% 08d", 50);
	ft_printf("% -08d", 50);
	ft_printf("% -+08d", 50);
	ft_printf("% -08d", 50);
	ft_printf("% +8d", 50);
	ft_printf("% -8d", 50);
	

	ft_printf("%x", 50);
	ft_printf("% x", 50);
	ft_printf("%+x", 50);
	ft_printf("% +x", 50);
	ft_printf("%-x", 50);
	ft_printf("%0x", 50);
	ft_printf("%#0-x", 50);
	ft_printf("%-08x", 50);
	ft_printf("%# 08x", 50); // 0xconsidere comme un signe
	ft_printf("% -08x", 50);
	ft_printf("%# -+08x", 50);
	ft_printf("% -08x", 50);
	ft_printf("%# +8x", 50);
	ft_printf("%# -8x", 50);
	

	ft_printf("%o", 50);
	ft_printf("% o", 50);
	ft_printf("%+o", 50);
	ft_printf("% +o", 50);
	ft_printf("%-o", 50);
	ft_printf("%0o", 50);
	ft_printf("%#0-o", 50);
	ft_printf("%-08o", 50);
	ft_printf("%# 08o", 50);
	ft_printf("% -08o", 50);
	ft_printf("%# -+08o", 50);
	ft_printf("% -08o", 50);
	ft_printf("%# +8o", 50);
	ft_printf("%# -8o", 50);


	ft_printf("%u", 50);
	ft_printf("% u", 50);
	ft_printf("%+u", 50);
	ft_printf("% +u", 50);
	ft_printf("%-u", 50);
	ft_printf("%0u", 50);
	ft_printf("%#0-u", 50);
	ft_printf("%-08u", 50);
	ft_printf("%# 08u", 50);
	ft_printf("% -08u", 50);
	ft_printf("%# -+08u", 50);
	ft_printf("% -08u", 50);
	ft_printf("%# +8u", 50);
	ft_printf("%# -8u", 50);

	ft_printf("%p", 50);
	ft_printf("% p", 50);
	ft_printf("%+p", 50);
	ft_printf("% +p", 50);
	ft_printf("%-p", 50);
	ft_printf("%0p", 50);
	ft_printf("%#0-p", 50);
	ft_printf("%-08p", 50);
	ft_printf("%# 08p", 50);
	ft_printf("% -08p", 50);
	ft_printf("%# -+08p", 50);
	ft_printf("% -08p", 50);
	ft_printf("%# +8p", 50);
	ft_printf("%# -8p", 50);

	ft_printf("%c", 50);
	ft_printf("% c", 50);
	ft_printf("%+c", 50);
	ft_printf("% +c", 50);
	ft_printf("%-c", 50);
	ft_printf("%0c", 50);
	ft_printf("%#0-c", 50);
	ft_printf("%-08c", 50);
	ft_printf("%# 08c", 50);
	ft_printf("% -08c", 50);
	ft_printf("%# -+08c", 50);
	ft_printf("% -08c", 50);
	ft_printf("%# +8c", 50);
	ft_printf("%# -8c", 50);


	ft_printf("%s", "Mat");
	ft_printf("% s", "Mat");
	ft_printf("%+s", "Mat");
	ft_printf("% +s", "Mat");
	ft_printf("%-s", "Mat");
	ft_printf("%0s", "Mat");
	ft_printf("%#0-s", "Mat");
	ft_printf("%-08s", "Mat");
	ft_printf("%# 08s", "Mat");
	ft_printf("% -08s", "Mat");
	ft_printf("%# -+08s", "Mat");
	ft_printf("% -08s", "Mat");
	ft_printf("%# +8s", "Mat");
	ft_printf("%# -8s", "Mat");

	ft_printf("%d", (long int)7850);
	ft_printf("%hd", (long int)7850);
	ft_printf("%hhd", (long int)7850);
	ft_printf("%hhhd", (long int)7850);
	ft_printf("%hhhhd", (long int)7850);
	ft_printf("%lhhhhd", (long int)7850);
	ft_printf("%hhhhld", (long int)7850);

	ft_printf("%d", 3000000000);
	ft_printf("%ld", 3000000000);
	ft_printf("%lld", 3000000000);
	ft_printf("%llld", 3000000000);
	ft_printf("%lllld", 3000000000);
	ft_printf("%hlhld", 3000000000);
	ft_printf("%lhhhd", 3000000000);

	ft_printf("%9d", (long int)7850);
	ft_printf("%h9d", (long int)7850);
	ft_printf("%h9hd", (long int)7850);
	ft_printf("%h9hhd", (long int)7850);
	ft_printf("%hh9hhd", (long int)7850);
	ft_printf("%lhh9hhd", (long int)7850);
	ft_printf("%hh9hhld", (long int)7850);

	ft_printf("%d", (long int)7850);
	ft_printf("%h9d", (long int)7850);
	ft_printf("%hd", (long int)7850);
	ft_printf("%h-+ hhd", (long int)7850);
	ft_printf("%hhhhd", (long int)7850);
	ft_printf("%lh-+ 9hhhd", (long int)7850);
	ft_printf("%h4h0hh9ld", (long int)7850);
	ft_printf("%lh- 9hhhd", (long int)7850);

	ft_printf("%x", (long int)7850);
	ft_printf("%h9x", (long int)7850);
	ft_printf("%hhu", (long int)7850); //
	ft_printf("%h-+ h#hx", (long int)7850);
	ft_printf("%hhhhx", (long int)7850); //
	ft_printf("%lh-+i# 9hhh  x", (long int)7850);
	ft_printf("%h4h0hh9lx", (long int)7850);
	ft_printf("%lh- 9hhhx", (long int)7850);

	ft_printf("%% %d", (long int)7850);
	ft_printf("%d %%", (long int)7850);

	ft_printf("  %s  ", 0);

	ft_printf("%d", (long int)7850);
	ft_printf("%hd", (long int)7850);
	ft_printf("%hhd", (long int)7850);
	ft_printf("%hhhd", (long int)7850);
	ft_printf("%hhhhd", (long int)7850);
	ft_printf("%o", (long int)7850);
	ft_printf("%ho", (long int)7850);
	ft_printf("%hho", (long int)7850);
	ft_printf("%hhho", (long int)7850);
	ft_printf("%hhhho", (long int)7850);
	ft_printf("%u", (long int)7850);
	ft_printf("%hu", (long int)7850);
	ft_printf("%hhu", (long int)7850);
	ft_printf("%hhhu", (long int)7850);
	ft_printf("%hhhhu", (long int)7850);
	ft_printf("%x", (long int)7850);
	ft_printf("%hx", (long int)7850);
	ft_printf("%hhx", (long int)7850);
	ft_printf("%hhhx", (long int)7850);
	ft_printf("%hhhhx", (long int)7850);

	ft_printf("%c", 1);
	ft_printf("%c df", '\0');
	ft_printf("%s", "sdf\0sdf");

	ft_printf("%c %c", '\0', '#');
	ft_printf("%c %c", '#', '\0');
	ft_printf("%s %0-8d", "Salut mec", 42);
	ft_printf("%s %0+8d", "Salut mec", 42);
	ft_printf("%s %0+-d", "Salut mec", 42);
	ft_printf("%s %0+-o", "Salut mec", 42);
	ft_printf("%s %0+-x", "Salut mec", 42);
	ft_printf("%s %0+--#xo", "Salut mec", 42);
	ft_printf(" %0+--#xo   - + --# %s", 42, "ft_printf");
	ft_printf(" %0+--#cxo   - + --# %s", '\0', "ft_printf");
	ft_printf(" %0+--#cxo   - + --# %s", 1, "ft_printf");
	ft_printf("%-8c", '\0');
	ft_printf("%h-h9d", 7850);

	ft_printf("%+X", 30000000000);
	ft_printf("%+x", 30000000000);

	ft_printf("%zhu", 30000000000);
	ft_printf("%jhu", 30000000000);
	ft_printf("%hzu", 30000000000);
	ft_printf("%hU", 30000000000);

	ft_printf("%d", -42);
	ft_printf("%p", &i);
	printf("%S", L"米\n");
	ft_printf("%D", LLONG_MIN - 1);
		ft_printf("%D", LLONG_MIN - 1);
	ft_printf("%04s", "42");
	ft_printf("Salut");
	ft_printf("");
	ft_printf("%#x %#x", 42, 42);
	ft_printf("{%03.2d}", 0);
	ft_printf("{%3.2d}", 0);
	ft_printf("{%+03.2d}", 0);
	ft_printf("{%03.2d}", -3);
	ft_printf("{%.4d}", 42);
	ft_printf("{%4d}", 42);
	ft_printf("{%05.2d}", 0);
	ft_printf("{%05.2d}", -42);
	ft_printf("{%010.5d}", -42);
	ft_printf("{%10.5d}", -42);
	ft_printf("{%010d}", -42);
	ft_printf("{%10d}", -42);
	ft_printf("{%10.d}", -42);
	ft_printf("{%-010.5d}", -42);
	ft_printf("{%-10.5d}", -42);
	ft_printf("{%010.5.1d}", -42);
	ft_printf("{%10.5.1d}", -42);
	ft_printf("%.d, %.0d", 0, 0);
	ft_printf("%#.O", 0);
	ft_printf("%#O", 0);
	ft_printf("%#.O", 1);
	ft_printf("%#O", 1);
	ft_printf("%.O", 0);
	ft_printf("%O", 0);
	ft_printf("%.O", 1);
	ft_printf("%O", 1);
	ft_printf("%.3%", 0);
	ft_printf("%.3r", 0);
	ft_printf("{%10R}", 0);
	ft_printf("%#.x, %#.0x", 0, 0);
	ft_printf("%.4s", "42");
	ft_printf("%.4s", "42 is the answer");
	ft_printf("%.0C", L'我');
	ft_printf("%.1C", L'我');
	ft_printf("%.2C", L'"我');
	ft_printf("%.3C", L'我');
	ft_printf("%.4C", L'我');
	ft_printf("%.5C", L'我');
	ft_printf("%.S", L"我是一只猫。");
	ft_printf("%.0S", L"我是一只猫。");
	ft_printf("%.3S", L"我是一只猫。");
	ft_printf("%.4S", L"我是一只猫。");
	ft_printf("%.5S", L"我是一只猫。");
	ft_printf("%.6S", L"我是一只猫。");
	ft_printf("%.7S", L"我是一只猫。");
	ft_printf("%.8S", L"我是一只猫。");
	ft_printf("%05.c", 0);
	ft_printf("%05.C", 0);
	ft_printf("%05.s", 0);
	ft_printf("%05.S", 0);
	ft_printf("%010.s", 0);
	ft_printf("%010.S", 0);
	ft_printf("%010s", 0);
	ft_printf("%010S", 0);
	ft_printf("%#.O", 0);
	ft_printf("%#.3o", 1);
	ft_printf("%*d", 5, 42);
	ft_printf("%*d", 15, 42);
	ft_printf("%*d", -5, 42);
	printf("{%c}\n", '\0');
ft_putchar('\n');
	ft_printf("{%c}", '\0');
	printf("{%c}", 0);
	printf("{%C,}%cpoiusdf%d\n",L'米' ,0, L'米');
	ft_printf("{%c, %hhC}", 0, L'米');
	ft_printf("%f", 1.42);
	ft_printf("%f", -1.42);
	ft_printf("{%05.*d}", -15, 42);
	ft_printf("{%*c}", -15, 0);

//	while (1);
	//ft_printf_f("{%f}{%F}", 1444565444646.6465424242242);
	testn("Salut %nmathieu");
	testn("%nSalut mathieu");
	testn("Salut mathieudfgdsafsadfsdf\ndsfasdfsdaf %n");
*/
	int o, o2;
	testn2("Mon nom est %s%n et je suis a 42", "Mathieu");
	testn2("J'ai %d%n ans", 28);


/*
	ft_printf("\033[45mSalut");
	ft_printf("\033[1m\033[45mSalut");
	ft_printf("\033[1m\033[4mSalut");
	*/
//	ft_printf("Salut%d", 7850);
	return (0);
}
