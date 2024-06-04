# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:50:44 by lemercie          #+#    #+#              #
#    Updated: 2024/05/29 14:00:31 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_conversions.c ft_printf_utils.c ft_itoa_long.c \
	   ft_printf_hexhandler.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft/
	cp ./libft/libft.a ./$(NAME)
	ar -crs $(NAME) $(OBJS)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -f *.o
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean $(NAME)

.PHONY: all clean fclean re
