# **************************************************************************** #
#																			   #
#														  :::	   ::::::::    #
#	 Makefile											:+:		 :+:	:+:    #
#													  +:+ +:+		  +:+	   #
#	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2025/02/21 09:44:40 by acarranz		   #+#	  #+#			   #
#	 Updated: 2025/02/21 09:44:40 by acarranz		  ###	########.fr		   #
#																			   #
# **************************************************************************** #

NAME = solong
CC = cc
CFLAGS = -Ofast -Wall -Wextra -Werror -g

# Directorios
SRC_DIR = src
INCLUDES_DIR = includes
LIBFT_DIR = libft
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
MLX_DIR = MLX42

# Archivos fuente
SRCS = main.c \
	   $(SRC_DIR)/enemy_move.c \
	   $(SRC_DIR)/check_map.c \
	   $(SRC_DIR)/enemies_init.c \
	   $(SRC_DIR)/init_end.c \
	   $(SRC_DIR)/key_hook.c \
	   $(SRC_DIR)/load_images.c \
	   $(SRC_DIR)/move_jou.c \
	   $(SRC_DIR)/moving.c \
	   $(SRC_DIR)/patrol_enemies.c \
	   $(SRC_DIR)/render.c \
	   $(SRC_DIR)/render_cell.c \
	   $(SRC_DIR)/render_elemnts.c \
	   $(SRC_DIR)/stop_game.c \
	   $(SRC_DIR)/tomb.c \
	   $(SRC_DIR)/utils.c \
	   $(SRC_DIR)/visited.c

OBJS = $(SRCS:.c=.o)

# Librerías
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MLX_LIB = $(MLX_DIR)/build/libmlx42.a

# Flags para MLX42 (Linux)
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -lGL -lGLU -lglfw -lX11 -lm

# Header principal
HEADER = $(INCLUDES_DIR)/solong.h

# Encontrar archivos de libft y ft_printf automáticamente
LIBFT_SRCS = $(shell find $(LIBFT_DIR) -name "*.c")
LIBFT_HEADERS = $(shell find $(LIBFT_DIR) -name "*.h")

# Reglas
all: $(LIBFT) $(FT_PRINTF) $(NAME)

# Compilar el proyecto principal
$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf $(MLX_FLAGS) -I$(INCLUDES_DIR) -I$(MLX_DIR)/include

# Compilar libft primero si hay cambios en los archivos fuente
$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADERS)
	@$(MAKE) -C $(LIBFT_DIR)

# Compilar ft_printf primero si hay cambios en los archivos fuente
$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

# Los objetos dependen del header principal
$(OBJS): $(HEADER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES_DIR) -I$(MLX_DIR)/include

# Compilar MLX
$(MLX_LIB):
	@cmake -B $(MLX_DIR)/build -S $(MLX_DIR) -DCMAKE_BUILD_TYPE=Release
	@cmake --build $(MLX_DIR)/build

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR)/build clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -rf $(MLX_DIR)/build

re: fclean all

.PHONY: all clean fclean re
