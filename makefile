NAME = libftprintf.a
FLAG = -g
#-Wall -Werror -Wextra

all:
	gcc -c ft_printf.c $(FLAG)
	gcc -c uitoa_base.c $(FLAG)
	gcc -c itoa_4.c $(FLAG)
	ar rc $(NAME) ft_printf.o uitoa_base.o itoa_4.o
#ranlib $(NAME)

test : all
	gcc main.c libft.a $(FLAG) $(NAME) -I./
	./a.out

