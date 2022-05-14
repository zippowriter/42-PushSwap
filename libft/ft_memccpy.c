/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:26:31 by hkono             #+#    #+#             */
/*   Updated: 2020/11/23 21:58:17 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*s1;
	const char	*s2;
	char		sc;
	size_t		i;

	s1 = (char *)dst;
	s2 = (const char *)src;
	sc = (char)c;
	i = 0;
	while (i < n)
	{
		*s1 = *s2;
		if (*s2 == sc)
			return (s1 + 1);
		s1++;
		s2++;
		i++;
	}
	return (NULL);
}
