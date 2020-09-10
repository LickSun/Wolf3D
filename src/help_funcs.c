/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:23:51 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:22 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_skip_spaces(char *ptr)
{
	while (*ptr == ' ')
		ptr++;
	return (ptr);
}

int			ft_numb_len(unsigned int numb)
{
	int i;

	i = 0;
	if (numb == 0)
		i++;
	while (numb != 0)
	{
		i++;
		numb /= 10;
	}
	return (i);
}

char		*ft_skip_numb(char *ptr)
{
	while (*ptr >= '0' && *ptr <= '9')
		ptr++;
	return (ptr);
}

int			ft_find_len(char *ptr)
{
	int i;

	i = 0;
	while (ptr[i] >= '0' && ptr[i] <= '9')
		i++;
	return (i);
}

int			ft_valid_atoi(const char *nptr)
{
	size_t				i;
	unsigned long long	res;
	int					flag;

	flag = 0;
	i = 0;
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9' && res <= 10000)
	{
		res *= 10;
		res += nptr[i++] - 48;
	}
	return (res);
}
