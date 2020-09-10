/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:02:52 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/15 16:20:05 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s + ft_strlen(s);
	while (ptr >= s)
	{
		if (*ptr == c)
			return (ptr);
		ptr--;
	}
	if (*ptr == c)
		return (ptr);
	return (NULL);
}
