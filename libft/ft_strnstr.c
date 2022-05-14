/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:31:15 by hkono             #+#    #+#             */
/*   Updated: 2021/11/22 21:36:42 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	h_i;
	size_t	n_i;

	if (*n == '\0')
		return ((char *)h);
	h_i = 0;
	while (h_i < len && h[h_i] != '\0')
	{
		n_i = 0;
		while (h[h_i + n_i] == n[n_i] && h_i + n_i < len && \
				h[h_i + n_i] && n[n_i])
		{
			n_i++;
			if (n[n_i] == '\0')
				return ((char *)(h + h_i));
		}
		h_i++;
	}
	return (NULL);
}
