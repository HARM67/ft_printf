NAME = libftprintf.a
FLAG = -g
SRC = ft_printf.c itoa_4.c itoa_2.c itoa_1.c itoa_8.c \
		uitoa_base_1.c uitoa_base_2.c uitoa_base_4.c uitoa_base_8
OBJ = ft_printf.o uitoa_base.o itoa_4.o itoa_2.o itoa_1.o itoa_8.o \
		uitoa_base_1.o uitoa_base_2.o uitoa_base_4.o uitoa_base_8.o
#-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(SRC):
	gcc -c $(SRC) $(FLAG)

test : fclean all
	gcc main.c libft.a $(FLAG) $(NAME) -I./
	./a.out

dev:
	vim -O $(SRC) *.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
