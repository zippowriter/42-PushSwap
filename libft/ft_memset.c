/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:29:11 by hkono             #+#    #+#             */
/*   Updated: 2020/11/23 21:59:32 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	uc;
	char	*p;
	size_t	i;

	uc = (char)c;
	p = (char *)b;
	i = 0;
	while (i < len)
	{
		*p = uc;
		p++;
		i++;
	}
	return (b);
}
