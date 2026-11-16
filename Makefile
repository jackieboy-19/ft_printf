# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrito <jbrito@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 10:59:10 by jbrito            #+#    #+#              #
#    Updated: 2026/11/12 10:02:44 by jbrito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft
SRCS = ft_handle_format.c ft_print_char.c ft_print_hex.c ft_print_nbr.c \
       ft_print_ptr.c ft_print_str.c ft_print_unb.c ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft 
	ar rcs $(NAME) $(OBJS)
	ar rcs libftprintf.a libft/*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re