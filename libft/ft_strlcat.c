/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 23:29:54 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/14 16:56:23 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		endlen;
	size_t		dstlen;

	d = dst;
	s = src;
	endlen = size;
	while (endlen-- != 0 && *d != '\0')
		d++;
	dstlen = d - dst;
	endlen = size - dstlen;
	if (endlen == 0)
		return (dstlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (endlen != 1)
		{
			*d++ = *s;
			endlen--;
		}
		s++;
	}
	*d = '\0';
	return (dstlen + (s - src));
}
