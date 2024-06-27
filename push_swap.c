/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:39:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/27 16:42:46 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	turksort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(*stack_a);
	while (len_a > 3 && !is_sorted_circ(*stack_a))
	{
		sort_into_b(stack_a, stack_b, instructions);
		len_a--;
	}
	sort_three(stack_a, stack_b, instructions);
	len_b = ft_lstsize(*stack_b);
	while (len_b > 0)
	{
		move_back_a(stack_a, stack_b, instructions);
		len_b--;
	}
	smallest_top(stack_a, stack_b, instructions);
}

static void	do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	if (is_sorted(*stack_a))
		return ;
	if (ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a, stack_b, instructions);
		return ;
	}
	turksort(stack_a, stack_b, instructions);
}

// return 0 on success
static int	do_thing(int argc, char **argv)
{
	t_list	*instructions;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	instructions = 0;
	if (parse_input(argc, argv, &stack_a))
	{
		cleanup_error(&stack_a, &stack_b, &instructions);
		return (1);
	}
	if (ft_lstsize(stack_a) <= 1)
	{
		cleanup_noexit(&stack_a, &stack_b, &instructions);
		return (0);
	}
	do_sort(&stack_a, &stack_b, &instructions);
	if (print_instructions(instructions))
	{
		cleanup_error(&stack_a, &stack_b, &instructions);
		return (1);
	}
	return (cleanup_noexit(&stack_a, &stack_b, &instructions));
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	if (do_thing(argc, argv))
		write(2, "Error\n", 6);
	return (0);
}
