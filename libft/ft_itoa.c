/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:52:05 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/15 14:41:35 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizenumb(long long n)
{
	size_t		len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
	{
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	long long	numb;
	size_t		len;
	size_t		i;

	numb = n;
	len = ft_sizenumb(numb);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (numb < 0)
	{
		str[0] = '-';
		numb = -numb;
	}
	i = len - 1;
	while (numb)
	{
		str[i--] = numb % 10 + 48;
		numb /= 10;
	}
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	return (str);
}
