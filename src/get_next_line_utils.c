/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:39:13 by lmidori           #+#    #+#             */
/*   Updated: 2020/07/06 21:47:32 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strdup(const char *src)
{
	int			i;
	char		*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char*)malloc(sizeof(*src) * (i + 1));
	if (dest == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		lenstr;
	size_t		size;
	size_t		i;

	if (s == NULL)
		return (NULL);
	lenstr = ft_strlen(s);
	if (lenstr < start)
		return (NULL);
	size = lenstr - start;
	if (size < len)
		len = size;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		len;
	size_t		i;

	if (!s1 && !s2)
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
