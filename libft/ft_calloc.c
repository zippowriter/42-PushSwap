/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:24:20 by hkono             #+#    #+#             */
/*   Updated: 2020/11/23 22:10:21 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ret_p;

	ret_p = malloc(sizeof(void) * size * n);
	if (ret_p == NULL)
		return (NULL);
	ft_bzero(ret_p, size * n);
	return (ret_p);
}
