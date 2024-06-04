/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:39:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/04 12:06:49 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//https://cs.stackexchange.com/questions/90202/sorting-a-stack-using-bubble-sort
	  
// read input into array
//
// create second array of equal size
//
// allocate string for output
// for performance, we use strlcat to construct the output string
// rellocate as necessary to grow the space
//
// bubble sort

#include "push_swap.h"
int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	if (argc <= 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
