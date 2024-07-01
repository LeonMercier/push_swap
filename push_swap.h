/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:02:57 by lemercie          #+#    #+#             */
/*   Updated: 2024/07/01 10:56:23 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

enum e_movetype
{
	mt_rot_rot,
	mt_rot_rev,
	mt_rev_rot,
	mt_rev_rev
};

typedef enum e_movetype	t_movetype;

typedef struct s_moveinfo
{
	int			index;
	int			cost;
	int			a_rotations;
	int			b_rotations;
	t_movetype	mt;
}	t_moveinfo;

//ft_atoi_safe.c
int			ft_atoi_safe(const char *str, int *err_atoi);

//cleanup.c
void		cleanup_error(t_list **stack_a, t_list **stack_b,
				t_list **instructions);
int			cleanup_noexit(t_list **stack_a, t_list **stack_b,
				t_list **instructions);

//stack_ops.c
void		swap_top(t_list *stack);
t_list		*pop(t_list **stack);
void		push_ab(t_list **stack_a, t_list **stack_b);
void		rotate(t_list **stack_a);
void		reverse_rotate(t_list **stack);

// instruction_ops.c
int			add_instr(t_list **instructions, char *instr);
int			print_instructions(t_list *instructions);

//utils.c
int			max(int a, int b);

//stack_utils.c
int			get_max(t_list *stack);
int			get_min(t_list *stack);
int			index_of_num(t_list *stack, int num);
int			is_sorted_circ(t_list *stack);
int			is_sorted(t_list *stack);

//move_into_b.c
void		rot_rot_into_b(t_list **stack_a, t_list **stack_b,
				t_list **instructions, t_moveinfo moveinfo);
void		rot_rev_into_b(t_list **stack_a, t_list **stack_b,
				t_list **instructions, t_moveinfo moveinfo);
void		rev_rot_into_b(t_list **stack_a, t_list **stack_b,
				t_list **instructions, t_moveinfo moveinfo);
void		rev_rev_into_b(t_list **stack_a, t_list **stack_b,
				t_list **instructions, t_moveinfo moveinfo);

//move_back_to_a.c
void		move_back_a(t_list **stack_a, t_list **stack_b,
				t_list **instructions);

//move_calcs.c
t_moveinfo	index_of_cheapest(t_list *stack_a, t_list *stack_b);

//sort_ops.c
void		pa(t_list **stack_a, t_list **stack_b, t_list **instructions);
void		pb(t_list **stack_a, t_list **stack_b, t_list **instructions);
void		sa(t_list **stack_a, t_list **stack_b, t_list **instructions);
void		ra(t_list **stack_a, t_list **stack_b, t_list **instructions);
void		rra(t_list **stack_a, t_list **stack_b, t_list **instructions);

//sort_ops_more.c
void		rb(t_list **stack_a, t_list **stack_b, t_list **instructions);
void		rrb(t_list **stack_a, t_list **stack_b, t_list **instructions);
void		rr(t_list **stack_a, t_list **stack_b, t_list **instructions);
void		rrr(t_list **stack_a, t_list **stack_b, t_list **instructions);

//sorter.c
void		sort_into_b(t_list **stack_a, t_list **stack_b,
				t_list **instructions);
void		sort_three(t_list **stack_a, t_list **stack_b,
				t_list **instructions);
void		smallest_top(t_list **stack_a, t_list **stack_b,
				t_list **instructions);

//parse_input.c
int			parse_input(int argc, char **argv, t_list **stack_a);
#endif
