/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:51:12 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/19 14:51:45 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanup(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	ft_lstclear(instructions, free);
	ft_printf("Error\n");
	exit(1);
}

int	cleanup_noexit(t_list **stack_a, t_list **stack_b, t_list **instructions)
{
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	ft_lstclear(instructions, free);
	return (0);
}
