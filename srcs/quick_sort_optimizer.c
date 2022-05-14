/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_optimizer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:29:41 by hkono             #+#    #+#             */
/*   Updated: 2022/01/27 00:18:34 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a_top)
{
	t_stack	*tmp;

	tmp = a_top;
	tmp = tmp->next;
	while (tmp != a_top)
	{
		if (tmp->sorted == 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	get_min_from_a(t_ds s_info)
{
	int		min;
	t_stack	*tmp;

	min = INT_MAX;
	tmp = s_info.a;
	tmp = tmp->next;
	while (tmp != s_info.a && tmp->sorted == 0)
	{
		if (tmp->key < min)
			min = tmp->key;
		tmp = tmp->next;
	}
	return (min);
}

static int	get_min_from_b(t_ds s_info)
{
	int		min;
	t_stack	*tmp;

	min = INT_MAX;
	tmp = s_info.b;
	tmp = tmp->next;
	while (tmp != s_info.b)
	{
		if (tmp->key < min)
			min = tmp->key;
		tmp = tmp->next;
	}
	return (min);
}

int	push_a_optim(t_ds s_info, int p)
{
	int		min;

	min = get_min_from_b(s_info);
	if (s_info.b->next->key > p)
		return (0);
	if (s_info.b->next->key == min && min)
	{
		s_info.b->next->sorted = 1;
		pa(s_info);
		ra(s_info);
		return (1);
	}
	else if (s_info.b->prev->key == min)
	{
		s_info.b->prev->sorted = 1;
		rrb(s_info);
		pa(s_info);
		ra(s_info);
		return (1);
	}
	return (0);
}

int	push_b_optim(t_ds s_info)
{
	int		min;

	min = get_min_from_a(s_info);
	if (s_info.a->next->key == min)
	{
		s_info.a->next->sorted = 1;
		ra(s_info);
		return (1);
	}
	return (0);
}
