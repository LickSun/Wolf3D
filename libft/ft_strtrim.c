/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:39:51 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/14 16:56:52 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findch(char const *s1, char const *set)
{
	while (*set && *s1 != *set)
		set++;
	if (*s1 == *set)
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*last;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_findch(s1, set))
		s1++;
	last = (char *)s1;
	while (*last)
		last++;
	while ((last - s1) && ft_findch(last, set))
		last--;
	str = ft_substr(s1, 0, last - s1 + 1);
	return (str);
}
