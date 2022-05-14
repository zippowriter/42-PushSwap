/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:44:31 by hkono             #+#    #+#             */
/*   Updated: 2022/01/26 19:34:34 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(t_ds *s_info)
{
	s_info->a->next = s_info->a;
	s_info->a->prev = s_info->a;
	return ;
}

void	init_b(t_ds *s_info)
{
	s_info->b->next = s_info->b;
	s_info->b->prev = s_info->b;
	return ;
}

void	insert(int key, int sorted, int p_id, t_stack *top)
{
	t_stack		*x;

	x = (t_stack *)malloc(sizeof(t_stack));
	x->key = key;
	x->sorted = sorted;
	x->p_id = p_id;
	x->next = top->next;
	top->next->prev = x;
	top->next = x;
	x->prev = top;
	return ;
}

t_stack	*list_search(int key, t_stack *top)
{
	t_stack	*cur;

	cur = top->next;
	while (cur != top && cur->key != key)
		cur = cur->next;
	return (cur);
}
