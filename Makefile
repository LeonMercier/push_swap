# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:50:44 by lemercie          #+#    #+#              #
#    Updated: 2024/06/04 12:07:46 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -f *.o
	make clean -C ./ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ./ft_printf

re: fclean $(NAME)

.PHONY: all clean fclean re
