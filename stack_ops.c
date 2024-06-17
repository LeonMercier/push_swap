/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 09:48:04 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/17 12:24:35 by lemercie         ###   ########.fr       */
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

	if (!(*stack)->next)
	{
		new_head = *stack;
		*stack = 0;
		return (new_head);
	}
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

void	rotate(t_list **stack)
{
	t_list	*old_head;

	if (!(*stack)->next)
		return ;
	old_head = pop(stack);
	ft_lstadd_back(stack, old_head);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack;
	if (!(*stack)->next)
		return ;
	if (!(*stack)->next->next)
	{
		swap_top(*stack);
		return ;
	}
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tail = tmp->next;
	tail->next = 0;
	tmp->next = 0;
	ft_lstadd_front(stack, tail);
}
