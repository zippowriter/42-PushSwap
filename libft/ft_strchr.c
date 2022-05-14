/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:29:21 by hkono             #+#    #+#             */
/*   Updated: 2021/04/09 09:25:54 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	cc;

	str = (char *)s;
	cc = (char)c;
	while (*str != '\0')
	{
		if (*str == cc)
			return (str);
		str++;
	}
	if (cc == '\0')
		return (NULL);
	return (NULL);
}
