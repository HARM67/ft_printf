NAME = libftprintf.a
FLAG = -g
#-Wall -Werror -Wextra
SRC = ft_printf.c itoa_4.c itoa_2.c itoa_1.c itoa_8.c \
		uitoa_base_1.c uitoa_base_2.c uitoa_base_4.c uitoa_base_8 \
		insert_flag.c argtoa.c read_flag.c print_arg.c \
		ft_putchar.c ft_putstr.c ft_bzero.c ft_memset.c \
		ft_memcpy.c ft_putnbr.c ft_memccpy.c ft_memmove.c \
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strstr.c \
		ft_strcmp.c ft_strncmp.c ft_isupper.c ft_islower.c \
		ft_isalpha.c ft_atoi.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_memchr.c ft_memcmp.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c	ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c \
		ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
		ft_strclen.c ft_strnext.c ft_strcount.c ft_putchar_fd.c  \
		ft_putendl.c ft_putstr_fd.c ft_putnbr_fd.c ft_itoa.c\
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
OBJ = ft_printf.o itoa_4.o itoa_2.o itoa_1.o itoa_8.o \
		uitoa_base_1.o uitoa_base_2.o uitoa_base_4.o uitoa_base_8.o \
		insert_flag.o argtoa.o read_flag.o print_arg.o ./*.o

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(SRC) :
	gcc -c $(SRC) $(FLAG) 

test : fclean all
	gcc main.c $(FLAG) $(NAME) -I./
	./a.out

dev :
	vim -O $(SRC) *.h

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
