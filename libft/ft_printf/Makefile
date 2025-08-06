# **************************************************************************** #
#																			   #
#														  :::	   ::::::::    #
#	 Makefile											:+:		 :+:	:+:    #
#													  +:+ +:+		  +:+	   #
#	 By: acarranz <marvin@42.fr>					+#+  +:+	   +#+		   #
#												  +#+#+#+#+#+	+#+			   #
#	 Created: 2024/11/01 12:48:30 by acarranz		   #+#	  #+#			   #
#	 Updated: 2024/11/01 12:48:30 by acarranz		  ###	########.fr		   #
#																			   #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
AR = ar
ARFLAGS = rcs
NAME = libftprintf.a
INC = includes/ft_printf.h Makefile

SRC = src/ft_printf.c \
	  src/conversions/print_char.c \
	  src/conversions/print_hex.c \
	  src/conversions/print_int.c \
	  src/conversions/print_percent.c \
	  src/conversions/print_pointer.c \
	  src/conversions/print_str.c \
	  src/conversions/print_uint.c \
	  src/utils/ft_itoa.c \
	  src/utils/ft_strdup.c \
	  src/utils/ft_putchar.c \
	  src/utils/ft_putstr.c \
	  src/utils/ft_strlen.c \
	  src/utils/ft_uitoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c $(INC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -rf src/conversions/*.o
	rm -rf src/utils/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
