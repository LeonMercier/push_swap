/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:39:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/04 16:59:05 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//https://cs.stackexchange.com/questions/90202/sorting-a-stack-using-bubble-sort
	  
// read input into dtta structure
//
// create second data structure
//
// allocate string for output
// for performance, we use strlcat to construct the output string
// rellocate as necessary to grow the space
//
// bubble sort may be too slow
// consider radix sort although that one needs hardcoded solutions for
//  3-5 inputs
//
//  int array for the stack is a bad idea because rotate instructions will be 
//	hard to implement
//
//	strsplit with space
//	atoi
//	==> numbers

#include "push_swap.h"
// return 0 on success
static int	do_thing(int argc, char **argv)
{
//	t_list	*instructions;
	t_list	*stack_a;
//	t_list	*stack_b;

	if (parse_input(argc, argv, &stack_a))
		return (1);
	print_stack(stack_a);
//	if (do_sort(&stack_a, &stack_b, &instructions))
//		return (1);
//	if (print_instructions(instructions))
//		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	if (do_thing(argc, argv))
		ft_printf("Error\n");
	return (0);
}
