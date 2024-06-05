/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:25:37 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/05 14:32:03 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_instructions(t_list *instructions)
{
	if (instructions)
	{
		if (instructions->content)
			ft_printf("%s\n",((char*) instructions->content));
		if (instructions->next)
			print_instructions(instructions->next);
	}
	return (0);
}
	
