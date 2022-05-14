/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:30:13 by hkono             #+#    #+#             */
/*   Updated: 2020/11/23 22:03:35 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_n;
	size_t	src_n;
	size_t	i;
	size_t	j;

	dst_n = ft_strlen(dst);
	src_n = ft_strlen(src);
	if (dstsize > dst_n)
	{
		i = 0;
		while (dst[i] != '\0')
			i++;
		j = 0;
		while (j < dstsize - dst_n - 1 && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (dst_n + src_n);
	}
	return (dstsize + src_n);
}
