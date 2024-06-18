/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:39:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/18 11:46:26 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	ft_lstclear(instructions, free);
	ft_printf("Error\n");
	exit(1);
}

int	turksort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int	len_a;
	int	len_b;

	pb(stack_a, stack_b, instructions);
	len_a = ft_lstsize(*stack_a);
	while (len_a > 3 && !is_sorted_circ(*stack_a))
	{
		sort_into_b(stack_a, stack_b, instructions);
		len_a--;
	}
//	ft_printf("A\n");
//	print_stack(*stack_a);
	sort_three(stack_a, stack_b, instructions);
//	ft_printf("A\n");
//	print_stack(*stack_a);
//	ft_printf("B\n");
//	print_stack(*stack_b);
	len_b = ft_lstsize(*stack_b);
	while (len_b > 0)
	{
		move_back_a(stack_a, stack_b, instructions);
		len_b--;
	}
	smallest_top(stack_a, stack_b, instructions);
	return (0);
}

int	do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	if (is_sorted(*stack_a))
		return (0);
	if (ft_lstsize(*stack_a) == 2)
	{
		sa(stack_a, stack_b, instructions);
		return (0);
	}
	if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a, stack_b, instructions);
		return (0);
	}
	return (turksort(stack_a, stack_b, instructions));
}

// return 0 on success
static int	do_thing(int argc, char **argv)
{
	t_list	*instructions;
	t_list	*stack_a;
	t_list	*stack_b;

	instructions = 0;
	if (parse_input(argc, argv, &stack_a))
	{
		cleanup(&stack_a, &stack_b, &instructions);
		return (1);
	}
	if (do_sort(&stack_a, &stack_b, &instructions))
	{
		cleanup(&stack_a, &stack_b, &instructions);
		return (1);
	}
	if (print_instructions(instructions))
	{
		cleanup(&stack_a, &stack_b, &instructions);
		return (1);
	}
//	print_stack(stack_a);
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
