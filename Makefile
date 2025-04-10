# Makefile so_long – Cosmétiquement stylé ✨

NAME	= so_long

# Directories
SRCDIR	= src
OBJDIR	= obj
INCDIR	= includes
LIBDIR	= includes/libft
MLXDIR	= includes/mlx

# Sources
SRC		= $(SRCDIR)/main.c \
		  $(SRCDIR)/game_init.c \
		  $(SRCDIR)/so_long_utils.c \
		  $(SRCDIR)/game_display.c \
		  $(SRCDIR)/get_next_line.c \
		  $(SRCDIR)/get_next_line_utils.c \
		  $(SRCDIR)/map_checker.c \
		  $(SRCDIR)/ft_isonly.c \
		  $(SRCDIR)/verify_chemin.c \
		  $(SRCDIR)/verify_element.c \
		  $(SRCDIR)/verify_map.c

OBJ		= $(SRC:.c=.o)
OBJF	= $(OBJ:$(SRCDIR)/%=$(OBJDIR)/%)

# Compilation
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBDIR) -I$(MLXDIR)

# Colors
GREEN	= \033[0;32m
CYAN	= \033[0;36m
RESET	= \033[0m

# Rules
all: $(NAME)

$(NAME): message_libft message_mlx $(OBJF)
	@echo "$(CYAN)🔧 Linking objects...$(RESET)"
	@$(CC) $(OBJF) $(MLXDIR)/libmlx.a -L$(LIBDIR) -lft -lX11 -lXext -lm -o $(NAME)
	@echo "$(GREEN)✅ Build complete: $(NAME)$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)📦 Compiled: $<$(RESET)"

message_libft:
	@echo "$(CYAN)📚 Building Libft...$(RESET)"
	@$(MAKE) -C $(LIBDIR) --silent

message_mlx:
	@echo "$(CYAN)🖼️  Building MiniLibX...$(RESET)"
	@$(MAKE) -C $(MLXDIR) --silent

clean:
	@echo "$(CYAN)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBDIR) clean --silent
	@$(MAKE) -C $(MLXDIR) clean --silent

fclean: clean
	@echo "$(CYAN)🗑️  Removing binary...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re message_libft message_mlx
