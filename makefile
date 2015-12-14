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
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		unicode.c ft_strcon.h
OBJ = ft_printf.o itoa_4.o itoa_2.o itoa_1.o itoa_8.o \
		uitoa_base_1.o uitoa_base_2.o uitoa_base_4.o uitoa_base_8.o \
		insert_flag.o argtoa.o read_flag.o print_arg.o \
		ft_putchar.o ft_putstr.o ft_bzero.o ft_memset.o \
		ft_memcpy.o ft_putnbr.o ft_memccpy.o ft_memmove.o \
		ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o \
		ft_strcat.o ft_strncat.o ft_strlcat.o ft_strstr.o \
		ft_strcmp.o ft_strncmp.o ft_isupper.o ft_islower.o \
		ft_isalpha.o ft_atoi.o ft_isdigit.o ft_isalnum.o \
		ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
		ft_memchr.o ft_memcmp.o ft_strchr.o ft_strrchr.o \
		ft_strnstr.o ft_memalloc.o ft_memdel.o ft_strnew.o \
		ft_strdel.o ft_strclr.o	ft_striter.o ft_striteri.o \
		ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o \
		ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o\
		ft_strclen.o ft_strnext.o ft_strcount.o ft_putchar_fd.o  \
		ft_putendl.o ft_putstr_fd.o ft_putnbr_fd.o ft_itoa.o\
		ft_putendl_fd.o ft_putnbr_fd.o ft_lstnew.o ft_lstdelone.o \
		ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
		unicode.o ft_strcon.o

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
