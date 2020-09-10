/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:54:56 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/14 16:56:43 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		i;
	char const	*ptr;

	i = 0;
	ptr = str1;
	if (!(*str2))
		return ((char *)str1);
	while (*str1)
	{
		while ((str1 - ptr + i < n) && *(str2 + i)
		&& *(str1 + i) == *(str2 + i))
			i++;
		if (!(*(str2 + i)))
			return ((char *)str1);
		str1++;
		i = 0;
	}
	return (NULL);
}
