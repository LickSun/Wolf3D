/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:17:12 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/15 13:48:22 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	str = NULL;
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (*s1 && len--)
		str[i++] = *s1++;
	len++;
	while (*s2 && len--)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
