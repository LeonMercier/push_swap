/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:44:45 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/10 14:25:30 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
	{
		str++;
	}
	if (*str == '-' || *str == '+')
		str++;
	if (*str >= '0' && *str <= '9')
		return (1);
	return (0);
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
			if (!is_valid_number(*strv))
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
