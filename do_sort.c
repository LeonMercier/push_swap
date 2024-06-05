/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:09:16 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/05 16:18:04 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	char	*ins;

	ins = (char *) malloc(sizeof(char) * 3);
	ins = ft_strdup("HE");
	*stack_b = *stack_a;
	ft_lstadd_back(instructions, ft_lstnew(ins));
	return (0);
}
