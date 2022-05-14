/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:21:24 by hkono             #+#    #+#             */
/*   Updated: 2021/04/12 19:37:12 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	require_array_num(char const *s, char c)
{
	size_t	an;
	size_t	i;

	an = 0;
	if (s[0] != c && s[0] != '\0')
		an++;
	i = 1;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c && s[i] != '\0')
			an++;
		i++;
	}
	return (an);
}

static char	*ft_strndup(char const *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * n);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, n);
	return (str);
}

static char	**make_split(char const *s, char c, char **strs, size_t an)
{
	size_t	strs_i;
	size_t	s_i;
	size_t	begin;

	s_i = 0;
	strs_i = 0;
	while (s[s_i] && strs_i < an - 1)
	{
		while (s[s_i] == c && s[s_i])
			s_i++;
		begin = s_i;
		while (s[s_i] != c && s[s_i])
			s_i++;
		strs[strs_i] = ft_strndup(s + begin, s_i - begin + 1);
		if (strs[strs_i] == NULL)
		{
			free(strs);
			return (NULL);
		}
		strs_i++;
	}
	strs[strs_i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	an;

	if (s == NULL)
		return (NULL);
	an = require_array_num(s, c);
	strs = (char **)malloc(sizeof(char *) * (an + 1));
	if (strs == NULL)
		return (NULL);
	strs = make_split(s, c, strs, an + 1);
	if (strs == NULL)
		return (NULL);
	return (strs);
}
