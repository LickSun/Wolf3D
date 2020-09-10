/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:38:39 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:51:27 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite		*ft_lstnew_sprite(int x, int y)
{
	t_sprite	*tmp;

	tmp = NULL;
	if ((tmp = (t_sprite *)malloc(sizeof(t_sprite))) == NULL)
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	return (tmp);
}

t_sprite		*ft_lstlast_sprite(t_sprite *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void			ft_lstadd_back_sprite(t_sprite **lst, t_sprite *tmp)
{
	t_sprite	*last;

	if (!lst || !tmp)
		return ;
	last = ft_lstlast_sprite(*lst);
	if (last)
		last->next = tmp;
	else
		*lst = tmp;
}

void			ft_sprclear(t_sprite **lst)
{
	t_sprite	*next;
	t_sprite	*now;

	if (!lst)
		return ;
	now = *lst;
	while (now != NULL)
	{
		next = now->next;
		free(now);
		now = next;
	}
	*lst = NULL;
}
