#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>

typedef struct s_form	t_form;
typedef union u_arg		t_arg;

struct					s_form
{
	char				diese;
	char				zero;
	char				space;
	char				moin;
	char				plus;
	int					precision;
	char				signe;
	char				base;
	char				size;
	char				maj;
	char				letter;
};

union					u_arg
{
	char				c;
	int					i;
	long int			li;
	unsigned int		uli;
};

int	ft_printf(const char *format, ...);

char					*uitoa_base(unsigned int n, int base);
char					*itoa_1(char *n);
char					*itoa_2(short int n);
char					*itoa_4(int n);
char					*itoa_8(long int n);
char					*strcon(char *s1, char *s2);
#endif
