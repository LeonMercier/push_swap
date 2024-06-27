/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ops_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:40:42 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/27 16:45:44 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	rotate(stack_b);
	if (add_instr(instructions, "rb"))
	{
		cleanup_error(stack_a, stack_b, instructions);
	}
}

void	rrb(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	reverse_rotate(stack_b);
	if (add_instr(instructions, "rrb"))
	{
		cleanup_error(stack_a, stack_b, instructions);
	}
}

void	rr(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	rotate(stack_a);
	rotate(stack_b);
	if (add_instr(instructions, "rr"))
	{
		cleanup_error(stack_a, stack_b, instructions);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (add_instr(instructions, "rrr"))
	{
		cleanup_error(stack_a, stack_b, instructions);
	}
}
