/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:44:45 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/04 16:14:22 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_number(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (0);
		str++;
	}
	return (1);
}

int	parse_input(int argc, char **argv, t_list **stack_a)
{
	int		i;
	char	**strv;
	int		*num;
	t_list	*newnode;

	i = 1;
	while (i < argc)
	{
		strv = ft_split(argv[i]);
		if (!strv)
			return (1);
		while (*strv)
		{
			if (validate_number(*strv))
			{
				free(strv);
				return (1);
			}
			num = (int *) malloc(sizeof(int));
			if (!num)
			{
				free(strv);
				return (1);
			}
			*num = ft_atoi(*strv);
			newnode = ft_lstnew(num);
			if (!newnode)
			{
				free(strv);
				free(num);
				return (1);
			}
			ft_lstadd_front(stack_a, newnode);
			strv++;
		}
		free(strv);
		i++;
	}
	return (0);
}
