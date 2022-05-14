/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:51:32 by hkono             #+#    #+#             */
/*   Updated: 2022/01/27 00:17:11 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	adjust_stack_a(t_ds s_info, int count_ra)
{
	if (count_ra == get_stacksize(s_info.a) - 1)
		ra(s_info);
	else if (count_ra == get_stacksize(s_info.a) - 2)
	{
		ra(s_info);
		ra(s_info);
	}
	else
		while (count_ra-- > 0)
			rra(s_info);
}

static void	five_four_sort(t_ds s_info)
{
	int		count_ra;

	a_three_sort(s_info);
	if (s_info.b->next->key > s_info.b->prev->key)
		rb(s_info);
	count_ra = 0;
	while (get_stacksize(s_info.b) > 0)
	{
		if (s_info.a->next->key > s_info.b->next->key)
			pa(s_info);
		else if (s_info.a->next->key == get_stackmin(s_info.a) && count_ra > 0)
			pa(s_info);
		else
		{
			ra(s_info);
			count_ra++;
		}
	}
	if (is_sort_complete(s_info))
		return ;
	adjust_stack_a(s_info, count_ra);
}

void	rule_sort(t_ds s_info)
{
	int		stack_size;

	stack_size = get_stacksize(s_info.a);
	if (stack_size == 2)
	{
		if (s_info.a->next->key > s_info.a->prev->key)
			sa(s_info);
	}
	else if (stack_size == 3)
		a_three_sort(s_info);
	else if (stack_size == 4)
	{
		pb(s_info);
		five_four_sort(s_info);
	}
	else if (stack_size == 5)
	{
		pb(s_info);
		pb(s_info);
		five_four_sort(s_info);
	}
}
