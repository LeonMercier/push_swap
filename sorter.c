/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/19 14:48:20 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_into_b(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	t_moveinfo	cheapest;

	if (ft_lstsize(*stack_b) < 2)
	{
		pb(stack_a, stack_b, instructions);
		return ;
	}
	cheapest = index_of_cheapest(*stack_a, *stack_b);
	if (cheapest.mt == mt_rot_rot)
		rot_rot_into_b(stack_a, stack_b, instructions, cheapest);
	else if (cheapest.mt == mt_rot_rev)
		rot_rev_into_b(stack_a, stack_b, instructions, cheapest);
	else if (cheapest.mt == mt_rev_rot)
		rev_rot_into_b(stack_a, stack_b, instructions, cheapest);
	else if (cheapest.mt == mt_rev_rev)
		rev_rev_into_b(stack_a, stack_b, instructions, cheapest);
}

void	sort_three(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int		top;
	int		middle;
	int		bottom;

	top = *(int *)(*stack_a)->content;
	middle = *(int *)(*stack_a)->next->content;
	bottom = *(int *)(*stack_a)->next->next->content;
	if (is_sorted_circ(*stack_a))
		return ;
	if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack_a, stack_b, instructions);
		ra(stack_a, stack_b, instructions);
	}
	else if (top < middle && middle > bottom && top > bottom)
		rra(stack_a, stack_b, instructions);
	else if (top > middle && middle < bottom && top < bottom)
		sa(stack_a, stack_b, instructions);
	else if (top > middle && middle < bottom && top > bottom)
		ra(stack_a, stack_b, instructions);
	else if (top > middle && middle > bottom && top > bottom)
	{
		sa(stack_a, stack_b, instructions);
		rra(stack_a, stack_b, instructions);
	}
}

void	smallest_top(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int	min;
	int	index;
	int	rev_index;

	min = get_min(*stack_a);
	index = index_of_num(*stack_a, min);
	rev_index = ft_lstsize(*stack_a) - index;
	if (index < rev_index)
	{
		while (index > 0)
		{
			ra(stack_a, stack_b, instructions);
			index--;
		}
	}
	else
	{
		while (rev_index > 0)
		{
			rra(stack_a, stack_b, instructions);
			rev_index--;
		}
	}
}
