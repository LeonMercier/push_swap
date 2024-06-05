/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:02:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/05 14:29:21 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

void	print_stack(t_list *stack);
int	print_instructions(t_list *instructions);
int	do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions);
int	parse_input(int argc, char **argv, t_list **stack_a);
#endif
