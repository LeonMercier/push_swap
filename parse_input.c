/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:44:45 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/10 14:04:40 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO fail when garbage before a digit
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

static void	free_strv(char **strv)
{
	char **strv_head;

	strv_head = strv;
	while (*strv)
	{
		free(*strv);
		strv++;
	}
	free(strv_head);
}

int	parse_input(int argc, char **argv, t_list **stack_a)
{
	int		i;
	char	**strv;
	char	**strv_head;
	int		*num;
	t_list	*newnode;

	i = 1;
	while (i < argc)
	{
		strv = ft_split(argv[i], ' ');
		if (!strv)
			return (1);
		strv_head = strv;
		while (*strv)
		{
			if (validate_number(*strv))
			{
				free_strv(strv_head);
				return (1);
			}
			num = (int *) malloc(sizeof(int));
			if (!num)
			{
				free_strv(strv_head);
				return (1);
			}
			*num = ft_atoi(*strv);
			newnode = ft_lstnew(num);
			if (!newnode)
			{
				free_strv(strv_head);
				free(num);
				return (1);
			}
			ft_lstadd_back(stack_a, newnode);
			strv++;
		}
		i++;
	}
	free_strv(strv_head);
	return (0);
}
