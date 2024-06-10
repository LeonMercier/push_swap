/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/10 12:40:36 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO why not just swap the pointers instead of copying ints?
void	swap_top(t_list *stack)
{
	int	tmp;

	tmp = *(int *) stack->content;
	*(int *) stack->content = *(int *) stack->next->content;
	*(int *) (stack->next->content) = tmp;
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

int	bubblesort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	int		len;
	int		i;
	int		j;
	
	len = ft_lstsize(*stack_a);
	while (len > 0)
	{
		// push len -1 elements to stack B, leaving largest in A
		i = len - 1;
		while (i > 0)
		{
			if (*(int *) (*stack_a)->content > *(int *) (*stack_a)->next->content)
			{
				swap_top(*stack_a);
				// TODO strdup can fail
				ft_lstadd_back(instructions, ft_lstnew(ft_strdup("sa"))); 
			}
			push_ab(stack_a, stack_b);
				// TODO strdup can fail
			ft_lstadd_back(instructions, ft_lstnew(ft_strdup("pb"))); 
			i--;
		}
		// return the same elements to stack A
		j = len - 1;
		while (j > 0)
		{
			push_ab(stack_b, stack_a);
				// TODO strdup can fail
			ft_lstadd_back(instructions, ft_lstnew(ft_strdup("pa"))); 
			j--;
		}
		len--;
	}
	return (0);
}

int	do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	/*
	char	*ins;

	ins = (char *) malloc(sizeof(char) * 3);
	ins = ft_strdup("HE");
	*stack_b = *stack_a;
	ft_lstadd_back(instructions, ft_lstnew(ins));
	*/
	
	return (bubblesort(stack_a, stack_b, instructions));
}
