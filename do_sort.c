/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/10 17:57:12 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_list *stack)
{
	void	*tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

t_list	*pop(t_list **stack)
{
	t_list	*old_head;
	t_list	*new_head;

	old_head = *stack;
	new_head = old_head->next;
	*stack = new_head;
	old_head->next = 0;
	return (old_head);
}

// The biggest number always remains in A, therefore we would NOT call this
// function if A is empty.
void	push_ab(t_list **stack_a, t_list **stack_b)
{
	t_list	*old_head_a;

	old_head_a = pop(stack_a);
	ft_lstadd_front(stack_b, old_head_a);
}

int	add_instr(t_list **instructions, char *instr)
{
	char	*str;
	t_list	*node;

	str = ft_strdup(instr);
	if (!str)
		return (1);
	node = ft_lstnew(str);
	if (!node)
		return (1);
	ft_lstadd_back(instructions, node);
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
			if (*(int *) (*stack_a)->content > *(int *) (*stack_a)->next->content)
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

int	do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	if (is_sorted(*stack_a))
		return (0);
	return (bubblesort(stack_a, stack_b, instructions));
}
