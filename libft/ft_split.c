/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:10:37 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/15 13:06:19 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (*s && *s != c)
			s++;
		len++;
	}
	return (len);
}

static int	ft_addwords(char **ptr, char const *s, char c)
{
	char	*st;
	char	**temp;
	size_t	i;

	temp = NULL;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		st = (char *)s;
		while (*s && *s != c)
			s++;
		i++;
		if (!(*ptr++ = ft_substr(st, 0, s - st)))
		{
			while (i--)
				free(temp++);
			return (0);
		}
	}
	*ptr = NULL;
	return (1);
}

char		**ft_split(char const *s, char c)
{
	size_t	len;
	char	**str;

	if (!s)
		return (NULL);
	len = ft_countwords(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	if (!ft_addwords(str, s, c))
	{
		free(str);
		return (NULL);
	}
	return (str);
}
