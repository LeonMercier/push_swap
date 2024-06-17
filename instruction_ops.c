/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:25:37 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/17 12:18:23 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	print_instructions(t_list *instructions)
{
	if (instructions)
	{
		if (instructions->content)
			ft_printf("%s\n", ((char *) instructions->content));
		if (instructions->next)
			print_instructions(instructions->next);
	}
	return (0);
}
