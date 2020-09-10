/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 15:55:15 by lmidori           #+#    #+#             */
/*   Updated: 2020/05/17 12:10:50 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *next;
	t_list *now;

	if (!lst || !del)
		return ;
	now = *lst;
	while (now != NULL)
	{
		(*del)(now->content);
		next = now->next;
		free(now);
		now = next;
	}
	*lst = NULL;
}
