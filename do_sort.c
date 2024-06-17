/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/17 16:34:57 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list *stack)
{
	int	max;

	max = *(int *) stack->content;
	while (stack->next)
	{
		stack = stack->next;
		if (*(int *) stack->content > max)
			max = *(int *) stack->content;
	}
	return (max);
}

int	get_min(t_list *stack)
{
	int	min;

	min = *(int *) stack->content;
	while (stack->next)
	{
		stack = stack->next;
		if (*(int *) stack->content < min)
			min = *(int *) stack->content;
	}
	return (min);
}

// return -1 if not found
int	index_of_num(t_list *stack, int num)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (num == *(int *) stack->content)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

int	index_of_smaller(t_list *stack, int num)
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
int	index_to_insert(t_list *stack, int num)
{
	if (num > get_max(stack) || num < get_min(stack))
		return (index_of_num(stack, get_max(stack)));
	return (index_of_smaller(stack, num));
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
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

t_moveinfo	get_lowest_cost(int index, int num, t_list *stack_a,
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
	int			num_curr;
	int			lowest_cost;
	t_moveinfo	current_cost;
	t_moveinfo	cheapest;

	i_curr = 0;
	while (stack_a)
	{
		num_curr = *(int *) stack_a->content;
		current_cost = get_lowest_cost(i_curr, num_curr, stack_a, stack_b);
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

void	sort_into_b(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	t_moveinfo	cheapest;

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

int	index_of_bigger_a(t_list *stack, int num)
{
	int	index;
	int	index_smaller;
	int	smallest_bigger;
	int	curr;

	index = 0;
	index_smaller = -1;
	while (stack)
	{
		curr = *(int *) stack->content;
		if (curr > num && (index_smaller == -1 || curr < smallest_bigger))
		{
			smallest_bigger = curr;
			index_smaller = index;
		}
		index++;
		stack = stack->next;
	}
	return (index_smaller);
}

// returns the index of the number above which we want to insert
// 		if inserting bigger than max or smaller than min: rotate min to top
// 		if inserting in the middle: rotate the smallest number that is still
// 			 bigger than num to the top
int	index_to_insert_to_a(t_list *stack, int num)
{
	if (num > get_max(stack) || num < get_min(stack))
	{
		return (index_of_num(stack, get_min(stack)));
	}
	return (index_of_bigger_a(stack, num));
}

void	move_back_a(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int	index_a;
	int	rev_index;

	if (!(*stack_b))
		return ;
	while (*stack_b)
	{
		index_a = index_to_insert_to_a(*stack_a, *(int *)(*stack_b)->content);
		rev_index = ft_lstsize(*stack_a) - index_a;
		if (rev_index < index_a)
		{
			while (rev_index > 0)
			{
				rra(stack_a, stack_b, instructions);
				rev_index--;
			}
		}
		else
		{
			while (index_a > 0)
			{
				ra(stack_a, stack_b, instructions);
				index_a--;
			}
		}
		pa(stack_a, stack_b, instructions);
	}
}

void	rot_smallest_top(t_list **stack_a, t_list **stack_b, t_list **instructions)
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

// This algo will need at least 5 numbers
	// find cheapest number in A to push into correct place in B, we want B to
	// end up in descending order. 
	// 		start calculating costs for each number
	// 		if we find one with cost of 1 (only the number on top of A!),
	// 		 push it
	// 		 else calculate all and push the cheapest
	//
	// 		We could calculate from top and bottom alternatin because numbers
	// 		in the middle of the stack are always going to be expensive
	// 		because of how many time they need to be rotated. But cost also
	// 		depends on rotations needed in B.
	//
	// 	If A is sorted at any point, we can stop moving stuff to B
	// When only 3 numbers remain in A
	// 		sort them in place
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
	sort_three(stack_a, stack_b, instructions);
	len_b = ft_lstsize(*stack_b);
	while (len_b > 0)
	{
		move_back_a(stack_a, stack_b, instructions);
		len_b--;
	}
	rot_smallest_top(stack_a, stack_b, instructions);
	return (0);
}


// check is circular sorted
int	is_sorted_circ(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *) stack->content > *(int *) stack->next->content)
			return (is_sorted(stack->next));
		stack = stack->next;
	}
	return (1);
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (*(int *) stack->content > *(int *) stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
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
