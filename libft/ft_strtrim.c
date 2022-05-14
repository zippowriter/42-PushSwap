/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:17:34 by hkono             #+#    #+#             */
/*   Updated: 2021/04/12 19:41:30 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_is(char const c, char const *set)
{
	int		set_i;

	set_i = 0;
	while (set[set_i])
	{
		if (c == set[set_i])
			return (1);
		set_i++;
	}
	return (0);
}

static size_t	trim_strlen(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	begin = 0;
	while (set_is(s1[begin], set) && begin < ft_strlen(s1))
		begin++;
	end = ft_strlen(s1) - 1;
	while (set_is(s1[end], set) && end > 0)
		end--;
	end++;
	if (begin > end)
		return (0);
	return (end - begin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_s;
	size_t	ts_i;
	size_t	begin;
	size_t	s1_len;
	size_t	trim_len;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	trim_len = trim_strlen(s1, set);
	trim_s = (char *)malloc(sizeof(char) * (trim_len + 1));
	if (trim_s == NULL)
		return (NULL);
	begin = 0;
	while (set_is(s1[begin], set) && begin < s1_len)
		begin++;
	ts_i = 0;
	while (ts_i < trim_len)
	{
		trim_s[ts_i] = s1[ts_i + begin];
		ts_i++;
	}
	trim_s[ts_i] = '\0';
	return (trim_s);
}
