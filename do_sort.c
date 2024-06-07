/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/07 17:21:17 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_list *stack)
{
	int	tmp;

	tmp = *(int *) stack->content;
	*(int *) stack->content = *(int *) stack->next->content;
	*(int *) (stack->next->content) = tmp;
}

// stak_b can be an empty stack
// cases:
// B has 0 members
// B has one member
// B has > 1 members
// The biggest number always remains in A, therefore we would NOT call this
// function if A has < 2 members.
void	pop_push(t_list **stack_a, t_list **stack_b)
{
	// TODO stack can be an empty stack
	t_list	*old_head_a;
	t_list	*old_head_b;
	t_list	*tmp_head_a;
	t_list	*tmp_head_b;

	old_head_a = *stack_a;
	tmp_head_a = old_head_a->next;
	if (*stack_b)
	{
		old_head_b = *stack_b;
		tmp_head_b = old_head_b->next;
	}
	old_head_a->next = 0;
	old_head_b->next = 0;

	*stack_a = tmp_head_a;
	*stack_b = tmp_head_b;
	ft_lstadd_front(stack_a, old_head_b);
	ft_lstadd_front(stack_b, old_head_a);
}

int	bubblesort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	(void) instructions;
	t_list	*a;
	t_list	*b;
	int		len;
	int		i;
	int		j;

	a = *stack_a;
	b = *stack_b;
	len = ft_lstsize(a);
//	i = len;
	i = 1;
	while (i > 0)
	{
		j = i;
		while (j > 0)
		{
			if (*(int *) a->content > *(int *) a->next->content)
			{
				swap_top(a);
			}
			pop_push(stack_a, stack_b);
			j--;
		}
		i--;
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
