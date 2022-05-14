/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:40:48 by hkono             #+#    #+#             */
/*   Updated: 2022/01/27 00:17:29 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	decesion_pivot(t_stack *s)
{
	int		p;

	if (s->next->key > s->next->next->key)
		p = s->next->key;
	else
		p = s->next->next->key;
	return (p);
}

void	quick_sort(t_ds s_info)
{
	int		p;
	int		p_id;

	p = 0;
	p_id = 0;
	while (!is_sort_complete(s_info))
	{
		p = decesion_pivot(s_info.a);
		push_b(s_info, p, p_id);
		while (get_stacksize(s_info.b) > 3)
		{
			p = decesion_pivot(s_info.b);
			push_a_top(s_info, p);
		}
		sort_b(s_info);
		push_a_bottom(s_info);
		p_id = s_info.a->next->p_id;
	}
}
