/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_p_and_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:41:42 by hkono             #+#    #+#             */
/*   Updated: 2022/01/26 23:24:42 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ds s_info)
{
	int		key;
	int		sorted;
	int		p_id;
	t_list	*second;

	if (s_info.a == s_info.a->next->next)
		return ;
	key = s_info.a->next->key;
	sorted = s_info.a->next->sorted;
	p_id = s_info.a->next->p_id;
	delete_first(s_info.a);
	insert(key, sorted, p_id, s_info.a->next);
	second = lst_second_last(s_info.cmd_list);
	if (ft_lstsize(s_info.cmd_list) == 1)
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("sa")));
	else if (ft_strncmp(second->next->content, "sb", 2) == 0)
	{
		free(second->next->content);
		second->next->content = ft_strdup("ss");
	}
	else
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("sa")));
	return ;
}

void	sb(t_ds s_info)
{
	int		key;
	int		sorted;
	int		p_id;
	t_list	*second;

	if (s_info.b == s_info.b->next->next)
		return ;
	key = s_info.b->next->key;
	sorted = s_info.b->next->sorted;
	p_id = s_info.b->next->p_id;
	delete_first(s_info.b);
	insert(key, sorted, p_id, s_info.b->next);
	second = lst_second_last(s_info.cmd_list);
	if (ft_lstsize(s_info.cmd_list) == 1)
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("sb")));
	else if (ft_strncmp(second->next->content, "sa", 2) == 0)
	{
		free(second->next->content);
		second->next->content = ft_strdup("ss");
	}
	else
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("sb")));
	return ;
}

void	pa(t_ds s_info)
{
	int		key;
	int		sorted;
	int		p_id;
	t_list	*second;

	key = s_info.b->next->key;
	sorted = s_info.b->next->sorted;
	p_id = s_info.b->next->p_id;
	if (s_info.b->next == s_info.b)
		return ;
	insert(key, sorted, p_id, s_info.a);
	delete_first(s_info.b);
	second = lst_second_last(s_info.cmd_list);
	if (ft_lstsize(s_info.cmd_list) == 1)
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("pa")));
	else if (ft_strncmp(second->next->content, "pb", 2) == 0)
	{
		ft_lstdelone(second->next, free);
		second->next = NULL;
	}
	else
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("pa")));
	return ;
}

void	pb(t_ds s_info)
{
	int		key;
	int		sorted;
	int		p_id;
	t_list	*second;

	key = s_info.a->next->key;
	sorted = s_info.a->next->sorted;
	p_id = s_info.a->next->p_id;
	if (s_info.a->next == s_info.a)
		return ;
	insert(key, sorted, p_id, s_info.b);
	delete_first(s_info.a);
	second = lst_second_last(s_info.cmd_list);
	if (ft_lstsize(s_info.cmd_list) == 1)
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("pb")));
	else if (ft_strncmp(second->next->content, "pa", 2) == 0)
	{
		ft_lstdelone(second->next, free);
		second->next = NULL;
	}
	else
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("pb")));
	return ;
}
