# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:50:44 by lemercie          #+#    #+#              #
#    Updated: 2024/06/19 14:52:39 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror

SRCS = push_swap.c parse_input.c sorter.c instruction_ops.c test_utils.c \
	  stack_ops.c sort_ops.c sort_ops_more.c stack_utils.c utils.c \
	  move_into_b.c move_back_to_a.c move_calcs.c cleanup.c

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
