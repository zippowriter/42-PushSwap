/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:30:56 by hkono             #+#    #+#             */
/*   Updated: 2022/01/27 00:17:57 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_ds s_info)
{
	if (get_stacksize(s_info.b) == 0)
		return ;
	if ((get_stacksize(s_info.b) == 2) \
		&& s_info.b->next->key > s_info.b->prev->key)
		rb(s_info);
	else if (get_stacksize(s_info.b) == 3)
		b_three_sort(s_info);
}

void	last_three(t_ds s_info, int p_id)
{
	int		len;
	int		remain_num;
	t_stack	*tmp;

	len = get_stacksize(s_info.a);
	remain_num = 0;
	tmp = s_info.a;
	tmp = tmp->next;
	while (len-- > 0 && tmp->sorted == 0 && tmp->p_id == p_id)
	{
		remain_num++;
		tmp = tmp->next;
	}
	if (remain_num > 3)
		return ;
	while (s_info.a->next->sorted == 0 && s_info.a->next->p_id == p_id)
		pb(s_info);
	sort_b(s_info);
	push_a_bottom(s_info);
}

void	push_a_bottom(t_ds s_info)
{
	int		len;

	len = get_stacksize(s_info.b);
	if (len == 0)
		return ;
	while (len-- > 0)
	{
		s_info.b->next->sorted = 1;
		pa(s_info);
		ra(s_info);
	}
}

void	push_a_top(t_ds s_info, int p)
{
	int		len;

	len = get_stacksize(s_info.b);
	while (len-- > 0)
	{
		while (push_a_optim(s_info, p) == 1)
			;
		if (s_info.b->next->key >= p && get_stacksize(s_info.b) > 0)
		{
			s_info.b->next->p_id = p;
			pa(s_info);
		}
		else if (s_info.b->next->key < p && get_stacksize(s_info.b) > 0)
			rb(s_info);
	}
}

void	push_b(t_ds s_info, int p, int p_id)
{
	int		len;
	int		ra_num;

	ra_num = 0;
	while (push_b_optim(s_info) == 1)
		;
	last_three(s_info, p_id);
	len = get_stacksize(s_info.a);
	while (len-- > 0 \
		&& s_info.a->next->sorted == 0 \
		&& s_info.a->next->p_id == p_id)
	{
		if (s_info.a->next->key < p)
			pb(s_info);
		else if (s_info.a->next->key >= p)
		{
			s_info.a->next->p_id = p;
			ra(s_info);
			ra_num++;
		}
	}
	if (is_sorted(s_info.a) == 1)
		while (ra_num-- > 0)
			rra(s_info);
}
