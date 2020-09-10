/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 14:05:37 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/15 13:37:46 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char ch;

	if (!s)
		return ;
	ch = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &ch, 1);
	return ;
}
