/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:48:09 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/17 14:53:54 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	push_ab(stack_a, stack_b);
	if (add_instr(instructions, "pa"))
	{
		cleanup(stack_a, stack_b, instructions);
	}
}

void	pb(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	push_ab(stack_a, stack_b);
	if (add_instr(instructions, "pb"))
	{
		cleanup(stack_a, stack_b, instructions);
	}
}

void	sa(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	swap_top(*stack_a);
	if (add_instr(instructions, "sa"))
	{
		cleanup(stack_a, stack_b, instructions);
	}
}

void	ra(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	rotate(stack_a);
	if (add_instr(instructions, "ra"))
	{
		cleanup(stack_a, stack_b, instructions);
	}
}

void	rra(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	reverse_rotate(stack_a);
	if (add_instr(instructions, "rra"))
	{
		cleanup(stack_a, stack_b, instructions);
	}
}
