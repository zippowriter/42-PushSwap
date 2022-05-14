/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:17:53 by hkono             #+#    #+#             */
/*   Updated: 2022/01/26 23:10:31 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				key;
	int				sorted;
	int				p_id;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ds
{
	t_stack	*a;
	t_stack	*b;
	t_list	*cmd_list;
}	t_ds;

void	error_checker(int argc, char **argv);
void	make_stacks(int argc, char **argv);
void	push_swap(t_ds s_info);
void	rule_sort(t_ds s_info);
void	quick_sort(t_ds s_info);
void	push_a_top(t_ds s_info, int pivot);
void	push_a_bottom(t_ds s_info);
void	push_b(t_ds s_info, int pivot, int pivot_id);
void	sort_b(t_ds s_info);
int		is_sorted(t_stack *a_top);
int		push_a_optim(t_ds s_info, int pivot);
int		push_b_optim(t_ds s_info);
// utils
void	put_error_exit(void);
void	free_all(t_ds s_info);
int		is_sort_complete(t_ds s_info);
int		get_stacksize(t_stack *stack);
int		get_stackmin(t_stack *s);
void	a_three_sort(t_ds s_info);
void	b_three_sort(t_ds s_info);
void	remove_next_cmd(t_list *cmds);
void	display_cmd(t_ds s_info);
t_list	*lst_second_last(t_list *lst);
// command
void	sa(t_ds s_info);
void	sb(t_ds s_info);
void	pa(t_ds s_info);
void	pb(t_ds s_info);
void	ra(t_ds s_info);
void	rb(t_ds s_info);
void	rra(t_ds s_info);
void	rrb(t_ds s_info);
// doubly linked list
void	init_a(t_ds *s_info);
void	init_b(t_ds *s_info);
void	insert(int key, int sorted, int pivot, t_stack *top);
t_stack	*list_search(int key, t_stack *top);
void	delete_node(t_stack *t, t_stack *top);
void	delete_first(t_stack *top);
void	delete_last(t_stack *top);
void	delete_key(int key, t_stack *top);
void	free_stack(t_stack *stack);

#endif
