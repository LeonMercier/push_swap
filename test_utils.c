/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:46:39 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/04 18:09:13 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//#include <stdio.h>
void	print_stack(t_list *stack)
{
	if (stack)
	{
		if (stack->content)
			ft_printf("%i\n",(*(int*) stack->content));
		if (stack->next)
			print_stack(stack->next);
	}
}
