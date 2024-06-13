/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/13 17:03:31 by lemercie         ###   ########.fr       */
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
	int biggest_smaller;
	int curr;

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
int	index_to_insert(t_list *stack, int num)
{
	// if inserting bigger than max or smaller than min: rotate max to top
	if (num > get_max(stack) || num < get_min(stack))
	{
		return (index_of_num(stack, get_max(stack)));
	}
	// if inserting in the middle: rotate the biggest number that is still
	// smaller than num to the top
	return (index_of_smaller(stack, num));	
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	if (b < a && b < c && b < d)
		return (b);
	if (c < a && c < b && c < d)
		return (c);
	return (d);
}

t_moveinfo	get_lowest_cost(int index, int num, t_list *stack_a, t_list *stack_b)
{
// rot => index
// rev => len - index
//	min (
	// max (rot,rot) 
	// rot + rev
	// rev + rot
	// max (rev, rev)
	int			rot_rot;
	int			rot_rev;
	int			rev_rot;
	int			rev_rev;
	t_moveinfo	ret;

	rot_rot = max(index, index_to_insert(stack_b, num));
	rot_rev = index + (ft_lstsize(stack_b) - index_to_insert(stack_b, num));
	rev_rot = (ft_lstsize(stack_a) - index) + index_to_insert(stack_b, num);
	rev_rev = max((ft_lstsize(stack_a) - index),
		   	(ft_lstsize(stack_b) - index_to_insert(stack_b, num)));
	if (rot_rot < rot_rev && rot_rot < rev_rot && rot_rot < rev_rev)
	{
		ret.cost = rot_rot;
		ret.mt = mt_rot_rot;
		ret.a_rotations = index;
		ret.b_rotations = index_to_insert(stack_b, num);
	}
	else if (rot_rev < rot_rot && rot_rev < rev_rot && rot_rev < rev_rev)
	{
		ret.cost = rot_rev;
		ret.mt = mt_rot_rev;
		ret.a_rotations = index;
		ret.b_rotations = (ft_lstsize(stack_b) - index_to_insert(stack_b, num));
	}
	else if (rev_rot < rot_rot && rev_rot < rot_rev && rev_rot < rev_rev)
	{
		ret.cost = rev_rot;
		ret.mt = mt_rev_rot;
		ret.a_rotations = (ft_lstsize(stack_a) - index);
		ret.b_rotations = index_to_insert(stack_b, num);
	}
	else
	{
		ret.cost = rev_rev;
		ret.mt = mt_rev_rev;
		ret.a_rotations = (ft_lstsize(stack_a) - index);
		ret.b_rotations = (ft_lstsize(stack_b) - index_to_insert(stack_b, num));
	}
	return (ret);
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

	// cost to rotate A + cost to rotate B
	// BUT rotations of A and B can be combined if they are to the same
	// direction
	// 
}

// TODO: add_instr() can fail
void	rot_rot_into_b(t_list **stack_a, t_list **stack_b,
		t_list **instructions, t_moveinfo moveinfo)
{
	while (moveinfo.a_rotations > 0 && moveinfo.b_rotations > 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		add_instr(instructions, "rr");
		moveinfo.a_rotations--;
		moveinfo.b_rotations--;
	}
	while (moveinfo.a_rotations > 0)
	{
		rotate(stack_a);
		add_instr(instructions, "ra");
		moveinfo.a_rotations--;
	}
	while (moveinfo.b_rotations > 0)
	{
		rotate(stack_b);
		add_instr(instructions, "rb");
		moveinfo.b_rotations--;
	}
	pb(stack_a, stack_b, instructions);
}

void	rot_rev_into_b(t_list **stack_a, t_list **stack_b,
		t_list **instructions, t_moveinfo moveinfo)
{
	while (moveinfo.a_rotations > 0)
	{
		rotate(stack_a);
		add_instr(instructions, "ra");
		moveinfo.a_rotations--;
	}
	while (moveinfo.b_rotations > 0)
	{
		reverse_rotate(stack_b);
		add_instr(instructions, "rrb");
		moveinfo.b_rotations--;
	}
	pb(stack_a, stack_b, instructions);
}

void	rev_rot_into_b(t_list **stack_a, t_list **stack_b,
		t_list **instructions, t_moveinfo moveinfo)
{
	while (moveinfo.a_rotations > 0)
	{
		reverse_rotate(stack_a);
		add_instr(instructions, "rra");
		moveinfo.a_rotations--;
	}
	while (moveinfo.b_rotations > 0)
	{
		rotate(stack_b);
		add_instr(instructions, "rb");
		moveinfo.b_rotations--;
	}
	pb(stack_a, stack_b, instructions);
}

void	rev_rev_into_b(t_list **stack_a, t_list **stack_b,
		t_list **instructions, t_moveinfo moveinfo)
{
	while (moveinfo.a_rotations > 0 && moveinfo.b_rotations > 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		add_instr(instructions, "rrr");
		moveinfo.a_rotations--;
		moveinfo.b_rotations--;
	}
	while (moveinfo.a_rotations > 0)
	{
		reverse_rotate(stack_a);
		add_instr(instructions, "rra");
		moveinfo.a_rotations--;
	}
	while (moveinfo.b_rotations > 0)
	{
		reverse_rotate(stack_b);
		add_instr(instructions, "rrb");
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

// TODO handle identical numbers
void	sort_three(t_list **stack, t_list **instructions)
{
	t_list	*head;
	int		top;
	int		middle;
	int		bottom;

	head = *stack;
	top = *(int *) head->content;
	middle = *(int *) head->next->content;
	bottom = *(int *) head->next->next->content;
	if (is_sorted(*stack))
		return ;
	if (top < middle && middle > bottom && top < bottom)
	{
		swap_top(*stack);
		add_instr(instructions, "sa");
		rotate(stack);
		add_instr(instructions, "ra");
	}
	else if (top < middle && middle > bottom && top > bottom)
	{
		reverse_rotate(stack);
		add_instr(instructions, "rra");
	}
	else if (top > middle && middle < bottom && top < bottom)
	{
		swap_top(*stack);
		add_instr(instructions, "sa");
	}
	else if (top > middle && middle < bottom && top > bottom)
	{
		rotate(stack);
		add_instr(instructions, "ra");
	}
	else if (top > middle && middle > bottom && top > bottom)
	{
		swap_top(*stack);
		add_instr(instructions, "sa");
		reverse_rotate(stack);
		add_instr(instructions, "rra");
	}
}

int	index_of_bigger_a(t_list *stack, int num)
{
	int	index;
	int	index_smaller;
	int smallest_bigger;
	int curr;

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
int	index_to_insert_to_a(t_list *stack, int num)
{
	// if inserting bigger than max or smaller than min: rotate max to top
	if (num > get_max(stack) || num < get_min(stack))
	{
		return (index_of_num(stack, get_max(stack)));
	}
	// if inserting in the middle: rotate the biggest number that is still
	// smaller than num to the top
	return (index_of_smaller(stack, num));
}

// TODO: consider case of reverse rotating stack A
void	move_back_a(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int	index_a;
	t_list	*head_b;

	head_b = *stack_b;
	while (head_b)
	{
		index_a = index_to_insert_to_a(*stack_a, *(int *) head_b->content);
		while (index_a > 0)
		{
			rotate(stack_a);
			add_instr(instructions, "ra");
		}
		push_ab(stack_b, stack_a);
		add_instr(instructions, "pa");
		head_b = head_b->next;
	}
}

// TODO: consider reverse rotating
void	rot_smallest_top(t_list **stack, t_list **instructions)
{
	int	min;

	min = get_min(*stack);
	while (*(int *) (*stack)->content != min)
	{
		rotate(stack);
		add_instr(instructions, "ra");
	}
}

// This algo will need at least 5 numbers
int	turksort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int	len_a;
	int	len_b;
	// push two numbers from A to B
	pb(stack_a, stack_b, instructions);
	pb(stack_a, stack_b, instructions);

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
	len_a = ft_lstsize(*stack_a);
	while (len_a > 3 && !is_sorted(*stack_a))
	{
		sort_into_b(stack_a, stack_b, instructions);
		len_a--;
	}

	// When only 3 numbers remain in A
	// 		sort them in place
	sort_three(stack_a, instructions); //skip if already sorted
	
	// 		start pushing from the top of B back to A
	// 		but we still need to check where to push
	len_b = ft_lstsize(*stack_b);
	while (len_b > 0) // this ends up skipping is A was sorted the whole time
	{
		move_back_a(stack_a, stack_b, instructions);
		len_b--;
	}

	// 		when B is empty rotate A until smallest number is on top
	rot_smallest_top(stack_a, instructions);	
	return (0);
}

// push len -1 elements to stack B, leaving largest in A
// return the same elements to stack A
// on the second round we push len -2 elements leaving behind the two largest
// ones in order and so on and so on
// TODO save lines by using exit() in add_instr() ?
// TODO put bubblesort in its own file but leave stack manipulators
int	bubblesort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int		len;
	int		i;
	
	len = ft_lstsize(*stack_a);
	while (len > 0)
	{
		i = len - 1;
		while (i > 0)
		{
			if (*(int *) (*stack_a)->content >
					*(int *) (*stack_a)->next->content)
			{
				swap_top(*stack_a);
				if (add_instr(instructions, "sa"))
					return (1);
			}
			push_ab(stack_a, stack_b);
			if (add_instr(instructions, "pb"))
				return (1);
			i--;
		}
		i = len - 1;
		while (i > 0)
		{
			push_ab(stack_b, stack_a);
			if (add_instr(instructions, "pa"))
				return (1);
			i--;
		}
		// at this point we could test if the array is already sorted
		len--;
	}
	return (0);
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

// TODO handle stack with < 5 numbers here
int	do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	if (is_sorted(*stack_a))
		return (0);
	if (ft_lstsize(*stack_a) == 2)
	{
		swap_top(*stack_a);
		add_instr(instructions, "sa");
		return (0);
	}		
	if (ft_lstsize(*stack_a) == 3)
	{
		sort_three(stack_a, instructions);
		return (0);
	}
	return (turksort(stack_a, stack_b, instructions));
}
