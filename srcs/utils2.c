/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:24:17 by hkono             #+#    #+#             */
/*   Updated: 2022/01/26 23:10:15 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_three_sort(t_ds s_info)
{
	int		top;
	int		mid;
	int		last;

	top = s_info.b->next->key;
	mid = s_info.b->next->next->key;
	last = s_info.b->prev->key;
	if (top < mid && top > last)
		rrb(s_info);
	else if (top > mid && top < last)
		sb(s_info);
	else if (top > mid && mid > last)
	{
		sb(s_info);
		rrb(s_info);
	}
	else if (top < mid && mid > last)
	{
		sb(s_info);
		rb(s_info);
	}
	else if (top > last && mid < last)
		rb(s_info);
	return ;
}

void	a_three_sort(t_ds s_info)
{
	int		top;
	int		mid;
	int		last;

	top = s_info.a->next->key;
	mid = s_info.a->next->next->key;
	last = s_info.a->prev->key;
	if (top < mid && top > last)
		rra(s_info);
	else if (top > mid && top < last)
		sa(s_info);
	else if (top > mid && mid > last)
	{
		sa(s_info);
		rra(s_info);
	}
	else if (top < mid && mid > last)
	{
		sa(s_info);
		ra(s_info);
	}
	else if (top > last && mid < last)
		ra(s_info);
	return ;
}

void	remove_next_cmd(t_list *cmds)
{
	t_list	*tmp;

	tmp = cmds->next->next;
	ft_lstdelone(cmds->next, free);
	cmds->next = tmp;
	return ;
}

void	display_cmd(t_ds s_info)
{
	t_list	*tmp;

	tmp = s_info.cmd_list->next;
	while (tmp != NULL)
	{
		ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
	return ;
}

t_list	*lst_second_last(t_list *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (NULL);
	while (lst->next->next)
	{
		lst = lst->next;
	}
	return (lst);
}
