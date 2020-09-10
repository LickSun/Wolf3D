/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:53:56 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/14 18:26:40 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len;

	ptr = NULL;
	len = nmemb * size;
	if ((ptr = (void *)malloc(len)) == NULL)
		return (NULL);
	ft_bzero(ptr, len);
	return (ptr);
}
