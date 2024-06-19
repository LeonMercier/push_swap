/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:09:17 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/19 16:16:49 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// For inserting into A:
// return the index of hte smallest element that is bigger than num
static int	index_of_bigger_a(t_list *stack, int num)
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
static int	index_to_insert_to_a(t_list *stack, int num)
{
	if (num > get_max(stack) || num < get_min(stack))
	{
		return (index_of_num(stack, get_min(stack)));
	}
	return (index_of_bigger_a(stack, num));
}

// Take elements from the top of B and insert them into the correct location 
// in A. Either rotate or reverse rotate A before inserting. 
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
			while (rev_index-- > 0)
			{
				rra(stack_a, stack_b, instructions);
			}
		}
		else
		{
			while (index_a-- > 0)
			{
				ra(stack_a, stack_b, instructions);
			}
		}
		pa(stack_a, stack_b, instructions);
	}
}
