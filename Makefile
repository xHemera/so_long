# Nom de l'exécutable
NAME        = so_long

# Directories
SRCDIR      = src
INCDIR      = includes
LIBFTDIR    = includes/libft
MLXDIR      = includes/mlx
OBJDIR      = obj

# Sources
SRCFILES    = \
	$(SRCDIR)/main.c \
	$(SRCDIR)/game_init.c
OBJFILES    = \
	$(OBJDIR)/main.o \
	$(OBJDIR)/game_init.o

# Compilation
CC          = clang
CFLAGS      = -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR) -I$(MLXDIR)
MLXFLAGS    = -L$(MLXDIR) -lmlx -lX11 -lXext

# Règles principales
all: $(NAME)

$(NAME): $(OBJFILES)
	@$(MAKE) -C $(LIBFTDIR)
	@$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) $(OBJFILES) -L$(LIBFTDIR) -lft $(MLXFLAGS) -o $(NAME)
	@echo "========== Compiled $(NAME) =========="

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Nettoyage
clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(MLXDIR)
	@rm -rf $(OBJDIR)
	@echo "========== Cleaned Object files =========="

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@rm -f $(NAME)
	@echo "========== Removed $(NAME) =========="

re: fclean all

# Utilitaires
.PHONY: all clean fclean re
