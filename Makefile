# Program Name
NAME = fractol

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I minilibx-linux -O3

# Libraries
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a
MLX_FLAGS = -lX11 -lXext -lm

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

# Source Files
SRC_FILES = init.c key.c main.c utils.c mandelbrot.c burning_ship.c julia.c tricorn.c color.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object Files
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT) $(MLX)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)
	@echo "$(NAME) ready."

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "Building libft..."
	@make -C $(LIBFT_DIR)
	@echo "libft ready."

$(MLX):
	@echo "Building MiniLibX..."
	@make -C $(MLX_DIR)
	@echo "MiniLibX ready."

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
