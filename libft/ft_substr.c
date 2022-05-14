/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:35:47 by hkono             #+#    #+#             */
/*   Updated: 2020/11/23 22:05:30 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_i;
	size_t	subs_i;

	if (s == NULL)
		return (0);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	s_i = 0;
	subs_i = 0;
	while (subs_i < len && s[s_i] != '\0')
	{
		if (s_i >= start)
		{
			substr[subs_i] = s[s_i];
			subs_i++;
		}
		s_i++;
	}
	substr[subs_i] = '\0';
	return (substr);
}
