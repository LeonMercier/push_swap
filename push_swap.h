/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:02:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/06/13 17:03:32 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"

enum e_movetype
{
	mt_rot_rot,
	mt_rot_rev,
	mt_rev_rot,
	mt_rev_rev
};

typedef enum e_movetype t_movetype;

typedef struct s_moveinfo
{
	int	index;
	int	cost;
	int	a_rotations;
	int	b_rotations;
	t_movetype mt;
} t_moveinfo;

void	swap_top(t_list *stack);
t_list	*pop(t_list **stack);
void	push_ab(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack_a);
void	reverse_rotate(t_list **stack);
int		is_sorted(t_list *stack);
void	print_stack(t_list *stack);
int		add_instr(t_list **instructions, char *instr);
int		print_instructions(t_list *instructions);
void	pb(t_list **stack_a, t_list **stack_b, t_list **instructions);
int		do_sort(t_list **stack_a, t_list **stack_b, t_list **instructions);
int		parse_input(int argc, char **argv, t_list **stack_a);
#endif
