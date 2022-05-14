/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:00:45 by hkono             #+#    #+#             */
/*   Updated: 2022/01/27 00:16:43 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ds s_info)
{
	if (is_sort_complete(s_info) == 1)
	{
		free_all(s_info);
		return ;
	}
	if (get_stacksize(s_info.a) <= 5)
		rule_sort(s_info);
	else
		quick_sort(s_info);
	if (is_sort_complete(s_info) == 1)
		display_cmd(s_info);
	free_all(s_info);
}
