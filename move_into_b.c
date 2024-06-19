/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:05:31 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/19 14:47:52 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_rot_into_b(t_list **stack_a, t_list **stack_b,
		t_list **instructions, t_moveinfo moveinfo)
{
	while (moveinfo.a_rotations > 0 && moveinfo.b_rotations > 0)
	{
		rr(stack_a, stack_b, instructions);
		moveinfo.a_rotations--;
		moveinfo.b_rotations--;
	}
	while (moveinfo.a_rotations > 0)
	{
		ra(stack_a, stack_b, instructions);
		moveinfo.a_rotations--;
	}
	while (moveinfo.b_rotations > 0)
	{
		rb(stack_a, stack_b, instructions);
		moveinfo.b_rotations--;
	}
	pb(stack_a, stack_b, instructions);
}

void	rot_rev_into_b(t_list **stack_a, t_list **stack_b,
		t_list **instructions, t_moveinfo moveinfo)
{
	while (moveinfo.a_rotations > 0)
	{
		ra(stack_a, stack_b, instructions);
		moveinfo.a_rotations--;
	}
	while (moveinfo.b_rotations > 0)
	{
		rrb(stack_a, stack_b, instructions);
		moveinfo.b_rotations--;
	}
	pb(stack_a, stack_b, instructions);
}

void	rev_rot_into_b(t_list **stack_a, t_list **stack_b,
		t_list **instructions, t_moveinfo moveinfo)
{
	while (moveinfo.a_rotations > 0)
	{
		rra(stack_a, stack_b, instructions);
		moveinfo.a_rotations--;
	}
	while (moveinfo.b_rotations > 0)
	{
		rb(stack_a, stack_b, instructions);
		moveinfo.b_rotations--;
	}
	pb(stack_a, stack_b, instructions);
}

void	rev_rev_into_b(t_list **stack_a, t_list **stack_b,
		t_list **instructions, t_moveinfo moveinfo)
{
	while (moveinfo.a_rotations > 0 && moveinfo.b_rotations > 0)
	{
		rrr(stack_a, stack_b, instructions);
		moveinfo.a_rotations--;
		moveinfo.b_rotations--;
	}
	while (moveinfo.a_rotations > 0)
	{
		rra(stack_a, stack_b, instructions);
		moveinfo.a_rotations--;
	}
	while (moveinfo.b_rotations > 0)
	{
		rrb(stack_a, stack_b, instructions);
		moveinfo.b_rotations--;
	}
	pb(stack_a, stack_b, instructions);
}
