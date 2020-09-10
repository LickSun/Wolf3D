/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 14:11:56 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/14 16:56:00 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		a;
	long long	numb;

	numb = n;
	if (numb < 0)
	{
		write(fd, "-", 1);
		numb = -numb;
	}
	if (numb >= 10)
		ft_putnbr_fd(numb / 10, fd);
	a = numb % 10 + 48;
	write(fd, &a, 1);
	return ;
}
