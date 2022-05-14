/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:33:25 by hkono             #+#    #+#             */
/*   Updated: 2022/01/27 00:24:26 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_duplicate(t_ds s_info)
{
	t_stack		*tmp1;
	t_stack		*tmp2;
	int			cmp_num;

	tmp1 = s_info.a->next;
	tmp2 = tmp1->next;
	while (tmp1 != s_info.a)
	{
		cmp_num = tmp1->key;
		while (tmp2 != s_info.a)
		{
			if (cmp_num == tmp2->key)
				put_error_exit();
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
	}
}

static void	insert_args(int argc, char **argv, t_ds *s_info)
{
	int		key;
	char	**split;
	int		i;
	int		si;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		si = 0;
		if (split == NULL)
			exit(0);
		while (split[si] != NULL)
		{
			key = ft_atoi(split[si]);
			insert(key, 0, 0, s_info->a->prev);
			free(split[si]);
			si++;
		}
		free(split);
		i++;
	}
	is_duplicate(*s_info);
}

void	make_stacks(int argc, char **argv)
{
	t_ds	s_info;

	s_info.a = (t_stack *)malloc(sizeof(t_stack));
	if (s_info.a == NULL)
		return ;
	init_a(&s_info);
	insert_args(argc, argv, &s_info);
	s_info.b = (t_stack *)malloc(sizeof(t_stack));
	if (s_info.b == NULL)
	{
		free_stack(s_info.a);
		return ;
	}
	init_b(&s_info);
	s_info.cmd_list = ft_lstnew(NULL);
	if (s_info.cmd_list == NULL)
	{
		free_stack(s_info.a);
		free_stack(s_info.b);
		return ;
	}
	push_swap(s_info);
}
