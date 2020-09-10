/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:53:29 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/15 14:52:46 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
