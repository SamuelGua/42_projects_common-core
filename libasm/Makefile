# Couleurs pour l'affichage
COLOR_RESET = \033[0m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_YELLOW = \033[93m
COLOR_BOLD = \033[1m

# Fichiers
NAME        = libasm.a
SRCS        = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS        = $(SRCS:.s=.o)
OBJDIR      = obj

# Compilateurs et outils
NASM        = nasm
AR          = ar
RM          = rm -f

# Flags pour NASM et GCC
NASMFLAGS   = -f elf64

# Cible par défaut
all: $(NAME)

test: $(NAME)
	gcc -o   main main.c libasm.a

# Règle pour la librairie statique
$(NAME): $(OBJS)
	@echo "$(COLOR_GREEN)Creating static library $(NAME)...$(COLOR_RESET)"
	$(AR) rcs $(NAME) $(OBJS)

# Création du répertoire obj/ si nécessaire
%.o: %.s
	@echo "$(COLOR_YELLOW)Compiling $<...$(COLOR_RESET)"
	$(NASM) $(NASMFLAGS) -o $@ $<

# Créer le répertoire obj/ si nécessaire
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Nettoyage des fichiers objets
clean:
	@echo "$(COLOR_RED)Cleaning object files...$(COLOR_RESET)"
	@$(RM) $(OBJS)
	@$(RM) -r $(OBJDIR)

# Nettoyage complet (objets + librairie)
fclean: clean
	@echo "$(COLOR_RED)Removing library $(NAME)...$(COLOR_RESET)"
	@$(RM) $(NAME)

# Recompilation complète
re: fclean all

# Cibles supplémentaires (optionnelles)
.PHONY: all clean fclean re
