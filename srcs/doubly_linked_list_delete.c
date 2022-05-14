/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_delete.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:45:08 by hkono             #+#    #+#             */
/*   Updated: 2022/01/25 19:42:46 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_first(t_stack *top)
{
	delete_node(top->next, top);
	return ;
}

void	delete_last(t_stack *top)
{
	delete_node(top->prev, top);
	return ;
}

void	delete_node(t_stack *t, t_stack *top)
{
	if (t == top)
		return ;
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
	return ;
}

void	delete_key(int key, t_stack *top)
{
	delete_node(list_search(key, top), top);
	return ;
}

void	free_stack(t_stack *stack)
{
	while (1)
	{
		if (stack == stack->next && stack == stack->prev)
			break ;
		delete_node(stack->next, stack);
	}
	free(stack);
	return ;
}
