/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:52:22 by hkono             #+#    #+#             */
/*   Updated: 2020/11/23 22:00:34 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		num1;
	char	moji;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	num1 = n / 10;
	moji = n % 10 + '0';
	if (num1)
	{
		ft_putnbr_fd(num1, fd);
		write(fd, &moji, 1);
	}
	else
		write(fd, &moji, 1);
}
