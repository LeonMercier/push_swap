/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/12 12:18:35 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_to_insert(t_list *stack_b, int num)
{}

// if the sign of the rotations is the same, then they can be combined and the
// total cost is the highest cost of the two
int	index_of_cheapest(t_list *stack_a, t_list *stack_b)
{
	int	cost_to_extract;
	int	i_curr;
	int	cheapest_index;
	int	cheapest_cost;
	int	len_a;
	int	insert_cost;

	i_curr = 0;
	cheapest_index = 0;
	len_a = ft_lstsize(stack_a);
	while (stack_a)
	{
		if (len_a - index < index)
			cost_to_extract = len_a - index;
		else
			cost_to_extract = index;
		insert_cost = cost_to_insert(stack_b, *(int *) stack_a->content);
		if (i_curr == 0 || insert_cost < cheapest_cost)
		{
			cheapest_index = i_curr;
			cheapest_cost = cost_to_extract + cost_to_insert;
		}
		stack_a = stack_a->next;
		i_curr++;
	}

	// cost to rotate A + cost to rotate B
	// BUT rotations of A and B can be combined if they are to the same
	// direction
	// 
}

void	sort_into_b(t_list **stack_a, t_list **stack_b, t_list **instructions)
{}

void	sort_three(t_list **stack, t_list **instructions)
{}

void	move_back_a(t_list **stack_a, t_list **stack_b, t_list **instructions)
{}

void	rot_smallest_top(t_list **stack, t_list **instructions)
{}

// This algo will need at least 5 numbers
int	turksort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int	len_a;
	int	len_b;
	// push two numbers from A to B
	pb(stack_a, stack_b, instructions);
	pb(stack_a, stack_b, instructions);

	// find cheapest number in A to push into correct place in B
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
	while (len > 3 && !is_sorted(*stack_a))
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
	return (bubblesort(stack_a, stack_b, instructions));
}
