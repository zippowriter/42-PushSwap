/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:45:28 by hkono             #+#    #+#             */
/*   Updated: 2022/01/26 18:55:03 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_all(t_ds s_info)
{
	free_stack(s_info.a);
	free_stack(s_info.b);
	ft_lstclear(&s_info.cmd_list, free);
	return ;
}

int	is_sort_complete(t_ds s_info)
{
	t_stack		*tmp;

	tmp = s_info.a;
	tmp = tmp->next;
	while (tmp != s_info.a->prev)
	{
		if (tmp->key > tmp->next->key)
			return (0);
		tmp = tmp->next;
	}
	if (get_stacksize(s_info.b) > 0)
		return (0);
	return (1);
}

int	get_stacksize(t_stack *stack)
{
	int			len;
	t_stack		*tmp;

	tmp = stack;
	tmp = tmp->next;
	len = 0;
	while (tmp != stack)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	get_stackmin(t_stack *s)
{
	int		min;
	t_stack	*tmp;

	min = INT_MAX;
	tmp = s->next;
	while (tmp != s)
	{
		if (tmp->key < min)
			min = tmp->key;
		tmp = tmp->next;
	}
	return (min);
}
