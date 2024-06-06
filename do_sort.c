/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/06 16:58:41 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_list *stack)
{
	int	tmp;

	tmp = *(stack->content);
	*(stack->content) = *(stack->next->content);
	*(stack->next->content) = tmp;
}

void	pop_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*old_head_a;
	t_list	*old_head_b;
	t_list	*tmp_head_a;
	t_list	*tmp_head_b;

	a = *stack_a;
	b = *stack_b;
	old_head_a = a;
	old_head_b = b;
	tmp_head_a = a->next;
	tmp_head_b = b->next;
	old_head_a->next = 0;
	old_head_b->next = 0;

	*stack_a = tmp_head_a;
	*stack_b = tmp_head_b;
	ft_lstadd_front(stack_a, old_head_b);
	ft_lstadd_front(stack_b, old_head_a);
}

int	bubblesort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	t_list	*a;
	t_list	*b;
	int		len;
	int		i;
	int		j;

	a = *stack_a;
	b = *stack_b;
	len = ft_lstsize(a);
	i = len;
	while (i > 0)
	{
		j = i;
		while (j > 0)
		{
			if (*(a->content) > *(a->next->content))
				swap_top(a);
			j--;
		}
		i--;
	}


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
