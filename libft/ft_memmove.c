/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:28:14 by hkono             #+#    #+#             */
/*   Updated: 2020/11/23 21:59:13 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p1;
	const char	*p2;

	if (dst == NULL && src == NULL)
		return (NULL);
	p1 = (char *)dst;
	p2 = (const char *)src;
	if (p1 > p2)
	{
		while (len > 0)
		{
			len--;
			*(p1 + len) = *(p2 + len);
		}
	}
	else
	{
		while (len > 0)
		{
			*(p1++) = *(p2++);
			len--;
		}
	}
	return (dst);
}
