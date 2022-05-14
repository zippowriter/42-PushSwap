/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 23:17:39 by hkono             #+#    #+#             */
/*   Updated: 2022/01/27 00:08:36 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_overflow_error(int argc, char **argv)
{
	char		**split;
	int			i;
	int			si;
	long long	n;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			exit(1);
		si = 0;
		while (split[si] != NULL)
		{
			n = ft_atol(split[si]);
			if (n > INT_MAX || n < INT_MIN)
				return (1);
			free(split[si]);
			si++;
		}
		free(split);
		i++;
	}
	return (0);
}

static int	is_char(char *src, char *dst)
{
	int		i;

	i = 0;
	if (ft_strlen(src) != ft_strlen(dst))
		return (1);
	while (src[i] != '\0' && dst[i] != '\0')
	{
		if (src[i] != dst[i])
			return (1);
		i++;
	}
	free(dst);
	return (0);
}

static int	is_string_error(int argc, char **argv)
{
	char	**split;
	int		i;
	int		si;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
			exit(1);
		si = 0;
		while (split[si] != NULL)
		{
			if (is_char(split[si], ft_itoa(ft_atoi(split[si]))))
				return (1);
			free(split[si]);
			si++;
		}
		free(split);
		i++;
	}
	return (is_overflow_error(argc, argv));
}

void	error_checker(int argc, char **argv)
{
	if (argc <= 1)
		exit(0);
	if (is_string_error(argc, argv))
		put_error_exit();
	make_stacks(argc, argv);
	return ;
}
