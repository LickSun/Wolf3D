/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:39:09 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 13:40:22 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_findnl_position(char *s)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int					ft_push_str(char **line, char **str, int len)
{
	char			*temp;
	size_t			range;

	range = ft_strlen(*str) - (len + 1);
	if (len >= 0)
	{
		if ((*line = ft_substr(*str, 0, len)) == NULL)
			return (-1);
		if ((temp = ft_substr(*str, len + 1, range)) == NULL)
			return (-1);
	}
	else
	{
		if ((*line = ft_strdup(*str)) == NULL)
			return (-1);
		temp = NULL;
	}
	if (*str != NULL)
		free(*str);
	*str = temp;
	if (*str == NULL)
		return (0);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char		*str;
	char			buf[BUFFER_SIZE + 1];
	long long		len;
	char			*temp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!str)
		str = ft_strdup("");
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = '\0';
		if ((temp = ft_strjoin(str, buf)) == NULL)
			return (-1);
		if (str)
			free(str);
		str = temp;
		if (ft_findnl_position(str) != -1)
			break ;
	}
	if (len < 0)
		return (-1);
	return (ft_push_str(line, &str, ft_findnl_position(str)));
}
