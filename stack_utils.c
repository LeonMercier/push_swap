/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:55:28 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/19 14:48:45 by lemercie         ###   ########.fr       */
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

// is the stack sorted so that it can be rotated into ascending order
int	is_sorted_circ(t_list *stack)
{
	t_list	*head;
	int		first;
	int		last;

	head = stack;
	first = *(int *) head->content;
	last = *(int *)(ft_lstlast(head)->content);
	while (stack->next)
	{
		if (*(int *) stack->content > *(int *) stack->next->content)
		{
			return (is_sorted(stack->next) && last < first);
		}
		stack = stack->next;
	}
	return (1);
}

// is the stack sorted in ascending order
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
