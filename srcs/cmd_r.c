/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:05:37 by hkono             #+#    #+#             */
/*   Updated: 2022/01/26 23:57:26 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ds s_info)
{
	int		key;
	int		sorted;
	int		p_id;
	t_list	*second;

	key = s_info.a->next->key;
	sorted = s_info.a->next->sorted;
	p_id = s_info.a->next->p_id;
	delete_first(s_info.a);
	insert(key, sorted, p_id, s_info.a->prev);
	second = lst_second_last(s_info.cmd_list);
	if (ft_lstsize(s_info.cmd_list) == 1)
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("ra")));
	else if (ft_strncmp(second->next->content, "rb", 2) == 0)
	{
		free(second->next->content);
		second->next->content = ft_strdup("rr");
	}
	else if (ft_strncmp(second->next->content, "rra", 3) == 0)
	{
		ft_lstdelone(second->next, free);
		second->next = NULL;
	}
	else
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("ra")));
}

void	rb(t_ds s_info)
{
	int		key;
	int		sorted;
	int		p_id;
	t_list	*second;

	key = s_info.b->next->key;
	sorted = s_info.b->next->sorted;
	p_id = s_info.b->next->p_id;
	delete_first(s_info.b);
	insert(key, sorted, p_id, s_info.b->prev);
	second = lst_second_last(s_info.cmd_list);
	if (ft_lstsize(s_info.cmd_list) == 1)
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("rb")));
	else if (ft_strncmp(second->next->content, "ra", 2) == 0)
	{
		free(second->next->content);
		second->next->content = ft_strdup("rr");
	}
	else if (ft_strncmp(second->next->content, "rrb", 3) == 0)
	{
		ft_lstdelone(second->next, free);
		second->next = NULL;
	}
	else
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("rb")));
}

void	rra(t_ds s_info)
{
	int		key;
	int		sorted;
	int		p_id;
	t_list	*second;

	key = s_info.a->prev->key;
	sorted = s_info.a->prev->sorted;
	p_id = s_info.a->prev->p_id;
	delete_last(s_info.a);
	insert(key, sorted, p_id, s_info.a);
	second = lst_second_last(s_info.cmd_list);
	if (ft_lstsize(s_info.cmd_list) == 1)
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("rra")));
	else if (ft_strncmp(second->next->content, "rrb", 3) == 0)
	{
		free(second->next->content);
		second->next->content = ft_strdup("rrr");
	}
	else if (ft_strncmp(second->next->content, "ra", 2) == 0)
	{
		ft_lstdelone(second->next, free);
		second->next = NULL;
	}
	else
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("rra")));
}

void	rrb(t_ds s_info)
{
	int		key;
	int		sorted;
	int		p_id;
	t_list	*second;

	key = s_info.b->prev->key;
	sorted = s_info.b->prev->sorted;
	p_id = s_info.b->prev->p_id;
	delete_last(s_info.b);
	insert(key, sorted, p_id, s_info.b);
	second = lst_second_last(s_info.cmd_list);
	if (ft_lstsize(s_info.cmd_list) == 1)
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("rra")));
	else if (ft_strncmp(second->next->content, "rra", 3) == 0)
	{
		free(second->next->content);
		second->next->content = ft_strdup("rrr");
	}
	else if (ft_strncmp(second->next->content, "rb", 2) == 0)
	{
		ft_lstdelone(second->next, free);
		second->next = NULL;
	}
	else
		ft_lstadd_back(&s_info.cmd_list, ft_lstnew(ft_strdup("rrb")));
}
