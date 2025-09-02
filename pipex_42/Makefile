COLOR_RESET = \033[0m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_YELLOW = \033[93m
COLOR_BOLD = \033[1m
MAKEFLAGS += --no-print-directory

NAME		:= pipex

SRC_DIR		:= src
OBJ_DIR		:= obj
SRCS		= $(PATH_LIBFT) $(PIPEX_PATH)
PATH_LIBFT 	= $(libft:%=src/libft/%)
libft		= ft_isdigit.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c\
				ft_isprint.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_atoi.c\
				ft_itoa.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_bzero.c\
				ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c\
				ft_calloc.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalnum.c ft_memcpy.c\
				ft_strchr.c ft_strncmp.c ft_isalpha.c ft_memmove.c ft_strdup.c\
				ft_strnstr.c ft_isascii.c ft_memset.c ft_striteri.c ft_strrchr.c\
				ft_free.c get_next_line.c\

PIPEX_PATH 	= $(pipex:%=src/pipex_src/%)
pipex 		= pipex_utils.c pipex.c here_doc.c code_erreur.c\

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CCFLAGS		:= -I include

RM			:= rm -f
DIR_DUP		= mkdir -p $(@D)

all: $(NAME)


$(NAME): $(OBJS)
		@$(CC) $(OBJS) -o $(NAME) 
		@echo "$(COLOR_GREEN)$(COLOR_BOLD)Compilation fini 👍 $(COLOR_RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/libft.h include/pipex.h
		@$(DIR_DUP)
		@$(CC) $(CFLAGS) $(CCFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all