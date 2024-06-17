# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:50:44 by lemercie          #+#    #+#              #
#    Updated: 2024/06/17 15:41:56 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror

SRCS = push_swap.c parse_input.c do_sort.c instruction_ops.c test_utils.c \
	  stack_ops.c sort_ops.c sort_ops_more.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./ft_printf/libft
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
