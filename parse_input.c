/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:44:45 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/25 16:14:40 by lemercie         ###   ########.fr       */
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

static int	has_number(t_list *stack, int num)
{
	while (stack)
	{
		if (*(int *) stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	free_strv(char **strv)
{
	char	**strv_head;

	strv_head = strv;
	while (*strv)
	{
		free(*strv);
		strv++;
	}
	free(strv_head);
}

// Parse string array resulting from ft_split() in parse_input()
static int	parse_num(t_list **stack, char **strv)
{
	int		*num;
	int		err_atoi;
	t_list	*node;

	err_atoi = 0;
	while (*strv)
	{
		num = (int *) malloc(sizeof(int));
		if (!is_valid_number(*strv) || !num)
			return (1);
		*num = ft_atoi_safe(*strv, &err_atoi);
		node = ft_lstnew(num);
		if (!node || err_atoi || has_number(*stack, *num))
		{
			free(num);
			if (node)
				free(node);
			return (1);
		}
		ft_lstadd_back(stack, node);
		strv++;
	}
	return (0);
}

// split each command line argument on spaces (even if argument is a single 
// number)
int	parse_input(int argc, char **argv, t_list **stack_a)
{
	int		i;
	char	**strv;

	i = 1;
	while (i < argc)
	{
		strv = ft_split(argv[i], ' ');
		if (!strv || !*strv)
			return (1);
		if (parse_num(stack_a, strv))
		{
			free_strv(strv);
			return (1);
		}
		free_strv(strv);
		i++;
	}
	return (0);
}
