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
	char				h_flag;
	char				l_flag;
	char				j_flag;
	char				z_flag;
	int					precision;
	char				signe;
	char				base;
	unsigned long		size;
	char				maj;
	char				letter;
	char				positive;
	char				*devant;
};

union					u_arg
{
	char				c;
	int					i;
	long int			li;
	unsigned int		uli;
};

/*----------------------ft_printf.c-----------------------------------------*/
int						ft_printf(const char *fmt, ...);

/*----------------------uitoa_base_X.c--------------------------------------*/
char					*uitoa_base_1(unsigned char n, int base);
char					*uitoa_base_2(unsigned short int n, int base);
char					*uitoa_base_4(unsigned int n, int base);
char					*uitoa_base_8(unsigned long int n, int base);

/*----------------------itoa_X.c--------------------------------------------*/
char					*itoa_1(char n);
char					*itoa_2(short int n);
char					*itoa_4(int n);
char					*itoa_8(long int n);

/*----------------------insert_flag.c---------------------------------------*/
void					insert_flag(char **str, t_form* form);
/*static char			*make_precision(char **str, t_form *form);			*/
/*static void			make_devant(t_form *form);							*/
/*static void			retirer_signe(char **str, t_form *form);			*/

/*----------------------argtoa.c--------------------------------------------*/
char					*argtoa(t_form* form, va_list *list);
/*static char 			*uinttoa_base(t_form *form, va_list *list);			*/
/*static char 			*inttoa(t_form *form, va_list *list);				*/

/*----------------------read_flag.c-----------------------------------------*/
void					read_flag(const char **fmt, t_form *form);
/*static void			set_size(const char **fmt, t_form *form);			*/
/*static void			read_precision(const char **fmt, t_form *form);		*/
/*static char			is_flag(char c);									*/
/*static void			normalize_flag(const char **fmt, t_form *form);		*/

/*----------------------print_arg.c-----------------------------------------*/
void					print_arg(const char **fmt, va_list *list, int *l);
/*static void			read_base(const char **fmt, t_form *form);			*/
#endif
