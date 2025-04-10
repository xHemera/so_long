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
	$(SRCDIR)/game_init.c \
	$(SRCDIR)/so_long_utils.c \
	$(SRCDIR)/game_display.c \
	$(SRCDIR)/get_next_line.c \
	$(SRCDIR)/get_next_line_utils.c \
	$(SRCDIR)/map_checker.c \
	$(SRCDIR)/ft_isonly.c
OBJFILES    = $(SRCFILES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Compilation
CC          = clang
CFLAGS      = -g -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBFTDIR) -I$(MLXDIR)
MLXFLAGS    = -L$(MLXDIR) -lmlx -lX11 -lXext

# Couleurs
GREEN       = \033[1;32m
BLUE        = \033[1;34m
YELLOW      = \033[1;33m
RED         = \033[1;31m
RESET       = \033[0m

# Fonctions pour l'animation
define loading_animation
	@printf "$(YELLOW)  [";
	@for i in {1..10}; do \
		printf "="; \
		sleep 0.1; \
	done; \
	printf "] Done.$(RESET)\n";
endef

# Messages
CLEAN_MSG   = @echo "$(GREEN)========== Cleaning Object files ==========$(RESET)"
COMPILE_MSG = @echo "$(BLUE)========== Compilating ==========$(RESET)"
LIBFT_MSG   = @echo "$(GREEN)========== Libft compiled ==========$(RESET)"
MLX_MSG     = @echo "$(GREEN)========== MLX compiled ==========$(RESET)"
DONE_MSG    = @echo "$(GREEN)========== Compiled $(NAME) ==========$(RESET)"

# Règles principales
all: $(NAME)

$(NAME): $(OBJFILES)
	$(COMPILE_MSG)
	$(loading_animation)
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory >/dev/null
	$(LIBFT_MSG)
	$(loading_animation)
	@$(MAKE) -C $(MLXDIR) --no-print-directory >/dev/null 2>&1
	$(MLX_MSG)
	$(loading_animation)
	@$(CC) $(CFLAGS) $(OBJFILES) -L$(LIBFTDIR) -lft $(MLXFLAGS) -o $(NAME)
	$(DONE_MSG)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Nettoyage
clean:
	$(CLEAN_MSG)
	$(loading_animation)
	@$(MAKE) clean -C $(LIBFTDIR) --no-print-directory >/dev/null
	@$(MAKE) clean -C $(MLXDIR) --no-print-directory >/dev/null 2>&1
	@rm -rf $(OBJDIR)

fclean: clean
	$(loading_animation)
	@$(MAKE) fclean -C $(LIBFTDIR) --no-print-directory >/dev/null
	@rm -f $(NAME)

re: fclean all

# Utilitaires
.PHONY: all clean fclean re
