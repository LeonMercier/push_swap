/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:44:44 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/19 14:47:32 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_of_smaller(t_list *stack, int num)
{
	int	index;
	int	index_smaller;
	int	biggest_smaller;
	int	curr;

	index = 0;
	index_smaller = -1;
	while (stack)
	{
		curr = *(int *) stack->content;
		if (curr < num && (index_smaller == -1 || curr > biggest_smaller))
		{
			biggest_smaller = curr;
			index_smaller = index;
		}
		index++;
		stack = stack->next;
	}
	return (index_smaller);
}

// returns the index of the number above which we want to insert
//		 if inserting bigger than max or smaller than min: rotate max to top
//		 if inserting in the middle: rotate the biggest number that is still
//			smaller than num to the top
static	int	index_to_insert(t_list *stack, int num)
{
	if (num > get_max(stack) || num < get_min(stack))
		return (index_of_num(stack, get_max(stack)));
	return (index_of_smaller(stack, num));
}

static t_moveinfo	set_moveinfo(int cost, t_movetype mt, int a_rot, int b_rot)
{
	t_moveinfo	ret;

	ret.cost = cost;
	ret.mt = mt;
	ret.a_rotations = a_rot;
	ret.b_rotations = b_rot;
	return (ret);
}

static t_moveinfo	get_lowest_cost(int index, int num, t_list *stack_a,
		t_list *stack_b)
{
	int			rot_rot;
	int			rot_rev;
	int			rev_rot;
	int			rev_rev;

	rot_rot = max(index, index_to_insert(stack_b, num));
	rot_rev = index + (ft_lstsize(stack_b) - index_to_insert(stack_b, num));
	rev_rot = (ft_lstsize(stack_a) - index) + index_to_insert(stack_b, num);
	rev_rev = max(ft_lstsize(stack_a) - index,
			ft_lstsize(stack_b) - index_to_insert(stack_b, num));
	if (rot_rot < rot_rev && rot_rot < rev_rot && rot_rot < rev_rev)
		return (set_moveinfo(rot_rot, mt_rot_rot, index,
				index_to_insert(stack_b, num)));
	else if (rot_rev < rot_rot && rot_rev < rev_rot && rot_rev < rev_rev)
		return (set_moveinfo(rot_rev, mt_rot_rev, index,
				ft_lstsize(stack_b) - index_to_insert(stack_b, num)));
	else if (rev_rot < rot_rot && rev_rot < rot_rev && rev_rot < rev_rev)
		return (set_moveinfo(rev_rot, mt_rev_rot, ft_lstsize(stack_a) - index,
				index_to_insert(stack_b, num)));
	else
		return (set_moveinfo(rev_rev, mt_rev_rev, ft_lstsize(stack_a) - index,
				ft_lstsize(stack_b) - index_to_insert(stack_b, num)));
}

// if the sign of the rotations is the same, then they can be combined and the
// total cost is the highest cost of the two
t_moveinfo	index_of_cheapest(t_list *stack_a, t_list *stack_b)
{
	int			i_curr;
	int			lowest_cost;
	t_moveinfo	current_cost;
	t_moveinfo	cheapest;
	t_list		*head_a;

	i_curr = 0;
	head_a = stack_a;
	while (stack_a)
	{
		current_cost = get_lowest_cost(i_curr, *(int *) stack_a->content,
				head_a, stack_b);
		if (i_curr == 0 || current_cost.cost < lowest_cost)
		{
			cheapest.index = i_curr;
			cheapest.a_rotations = current_cost.a_rotations;
			cheapest.b_rotations = current_cost.b_rotations;
			cheapest.mt = current_cost.mt;
			lowest_cost = current_cost.cost;
		}
		stack_a = stack_a->next;
		i_curr++;
	}
	return (cheapest);
}
