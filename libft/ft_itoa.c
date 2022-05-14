/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 10:33:09 by hkono             #+#    #+#             */
/*   Updated: 2021/04/16 16:47:26 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	unsigned int	proxy;
	int				digits;

	proxy = n;
	if (n < 0)
		proxy *= -1;
	digits = 0;
	while (proxy > 0)
	{
		proxy /= 10;
		digits++;
	}
	if (n < 0 || n == 0)
		return (digits + 1);
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	proxy;
	int				digits;
	int				thresh;

	digits = get_digits(n);
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	str[digits] = '\0';
	proxy = n;
	thresh = 0;
	if (n < 0)
	{
		proxy *= -1;
		str[0] = '-';
		thresh = 1;
	}
	while (digits > thresh)
	{
		str[--digits] = (proxy % 10) + '0';
		proxy /= 10;
	}
	return (str);
}
