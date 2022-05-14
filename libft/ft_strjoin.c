/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:59:45 by hkono             #+#    #+#             */
/*   Updated: 2021/04/12 19:29:47 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_concat(char *ret_str, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		ret_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ret_str[i] = s2[j];
		i++;
		j++;
	}
	ret_str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ret_str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ret_str == NULL)
		return (NULL);
	str_concat(ret_str, s1, s2);
	return (ret_str);
}
