/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 10:42:02 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/14 10:43:25 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push len -1 elements to stack B, leaving largest in A
// return the same elements to stack A
// on the second round we push len -2 elements leaving behind the two largest
// ones in order and so on and so on
// TODO save lines by using exit() in add_instr() ?
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

