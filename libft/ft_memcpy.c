/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:27:44 by hkono             #+#    #+#             */
/*   Updated: 2020/11/04 20:21:08 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	if (dst == NULL && src == NULL)
		return (NULL);
	s1 = (char *)dst;
	s2 = (const char *)src;
	i = 0;
	while (i < n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		i++;
	}
	return (dst);
}
