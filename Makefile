# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME        = so_long

CC          = clang
CFLAGS      = -Wall -Wextra -Werror -g

# ───── LIBFT ──────────────────────────────────────────────────────────────── #

LIBFT_PATH  = ./libft/
LIBFT_FILE  = libft.a
LIBFT_LIB   = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

# ───── MiniLibX ───────────────────────────────────────────────────────────── #

MLX_PATH    = ./src/mlx/
MLX_FILE    = libmlx.a
MLX_FLAG    = -lX11 -lXext
MLX_LIB     = $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX      = $(MLX_LIB) $(MLX_FLAG)

# ───── SOURCES ────────────────────────────────────────────────────────────── #

SRC_DIR     = ./src/
INC_DIR     = ./include/

SO_LONG_FILE = main.c         \
               mouvement.c    \
               map.c          \
               verif_map.c    \
               verif_elt.c    \
               read_map.c     \
               verif_chemin.c \
               exit.c

SRC = $(addprefix $(SRC_DIR), $(SO_LONG_FILE))
OBJ = $(SRC:.c=.o)

# ───── COULEURS ───────────────────────────────────────────────────────────── #

YELLOW = \033[1;33m
GREEN  = \033[1;32m
BLUE   = \033[1;34m
RED    = \033[1;31m
RESET  = \033[0m

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

prepare:
	@-git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	@echo "$(BLUE)📥 MiniLibX cloné dans $(MLX_PATH)$(RESET)"

lib: prepare
	@echo "$(BLUE)📦 Compilation de libft...$(RESET)"
	@make -s -C $(LIBFT_PATH)
	@echo "$(GREEN)✔ LIBFT prête.$(RESET)"

mlx: $(MLX_PATH)
	@echo "$(BLUE)🛠 Compilation de MiniLibX...$(RESET)"
	@make -s -C $(MLX_PATH)
	@echo "$(GREEN)✔ MLX prête.$(RESET)"

$(NAME): lib mlx $(OBJ)
	@$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) compilé avec succès !$(RESET)"

clean:
	@echo "$(YELLOW)🧹 Suppression des fichiers objets...$(RESET)"
	@rm -f $(OBJ)
	@make -s clean -C $(LIBFT_PATH)

fclean: clean
	@echo "$(RED)❌ Suppression de l'exécutable $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -s fclean -C $(LIBFT_PATH)
	@rm -rf $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re lib mlx prepare
