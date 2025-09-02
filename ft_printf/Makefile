NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
SRC = ft_printf.c ft_print_hex.c ft_print_letters.c ft_print_nbr.c ft_print_ptr.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

bonus : $(OBJ)
		$(AR) $(NAME) $(OBJ)

%.o : %.c
		$(CC) $(CFLAGS) -o $@  -c $<

$(NAME) : $(OBJ)
		$(AR) $(NAME) $(OBJ)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re