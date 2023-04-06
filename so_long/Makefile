# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ranki <ranki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 22:25:54 by ranki             #+#    #+#              #
#    Updated: 2023/04/02 22:44:29 by ranki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
       libft/ft_calloc.c libft/ft_split.c libft/ft_bzero.c\
       game/close.c game/moov.c game/parsing.c game/place.c game/player.c \
       map/checker.c map/checker2.c map/valid_path.c map/path_utils.c \
	   ft_printf/ft_flags.c ft_printf/ft_printf.c ft_printf/ft_putnbr_fd.c \
	   game/place0.c ft_printf/ft_putstr.c ft_printf/ft_sizechar.c \
	   ft_printf/ft_sizehexa.c ft_printf/ft_sizeint.c check_arg.c \
	   ft_printf/ft_sizep.c ft_printf/ft_sizestr.c ft_printf/ft_size_unsignedint.c \
	   ft_printf/ft_sizeptr.c map/checker3.c libft/ft_itoa.c\

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -L minilibx-linux/ -lmlx -lbsd -lXext -lX11

MLX: $(NAME)
	@echo "\nBuilding minilibx-linux..."
	@make -C minilibx-linux

all: MLX

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@echo "\nCleaning up..."
	rm -rf $(OBJS)

fclean: clean
	@echo "\nRemoving executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re MLX


