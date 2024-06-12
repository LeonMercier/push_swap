/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:02:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/12 16:12:46 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

void	swap_top(t_list *stack);
t_list	*pop(t_list **stack);
void	push_ab(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack_a);
void	print_stack(t_list *stack);
int		add_instr(t_list **instructions, char *instr);
int		print_instructions(t_list *instructions);
void	pb(t_list **stack_a, t_list **stack_b, t_list **instructions);
int		do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions);
int		parse_input(int argc, char **argv, t_list **stack_a);
#endif
