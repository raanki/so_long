# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ranki <ranki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 13:46:23 by ranki             #+#    #+#              #
#    Updated: 2022/11/19 20:02:42 by ranki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_strlcpy.c  ft_strlen.c ft_bzero.c ft_isdigit.c  ft_strchr.c ft_toupper.c \
ft_tolower.c ft_isalpha.c ft_isalnum.c  ft_isascii.c ft_isprint.c ft_memcpy.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_calloc.c ft_strdup.c ft_atoi.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlcat.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_itoa.c\

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c\

BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

FLAGS =-Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) $(SRC) -c 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	
all: $(NAME)

bonus :
	gcc $(FLAGS) $(SRC) $(BONUS_SRC) -c   
	ar rc $(NAME) $(BONUS_OBJ) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: 	clean
			rm -f $(NAME)

re: fclean all
