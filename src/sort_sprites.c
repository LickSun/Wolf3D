/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:19:20 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:51:32 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_swap(t_sprite **head, t_sprite *tmp, t_sprite *sled)
{
	t_sprite *temp;
	t_sprite *root;

	root = *head;
	if (tmp == *head)
	{
		temp = sled->next;
		sled->next = tmp;
		tmp->next = temp;
		(*head) = sled;
	}
	else
	{
		while (root->next != tmp)
			root = root->next;
		temp = sled->next;
		sled->next = tmp;
		tmp->next = temp;
		root->next = sled;
	}
}

void		ft_sort_sprite_len(t_sprite **root)
{
	t_sprite	*tmp;
	int			flag;

	flag = 1;
	tmp = *root;
	while (flag)
	{
		flag = 0;
		tmp = *root;
		while (tmp->next != NULL)
		{
			if (tmp->len < tmp->next->len)
			{
				ft_swap(root, tmp, tmp->next);
				flag = 1;
			}
			else
				tmp = tmp->next;
		}
	}
}

void		ft_len_sprite(t_all *all, t_sprite *root)
{
	t_sprite *tmp;

	tmp = root;
	while (tmp != NULL)
	{
		tmp->len = sqrt(pow(tmp->x - all->player.x_pos, 2) +
		pow(tmp->y - all->player.y_pos, 2));
		tmp = tmp->next;
	}
}

void		ft_sort_sprites(t_all *all)
{
	ft_len_sprite(all, all->sprite);
	ft_sort_sprite_len(&(all->sprite));
}

void		ft_init_spr_params(t_all *all, t_sprite *spr)
{
	spr->angle = atan2(spr->y - all->player.y_pos, spr->x - all->player.x_pos);
	while (spr->angle - all->player.a_pos > M_PI)
		spr->angle -= 2 * M_PI;
	while (spr->angle - all->player.a_pos < -M_PI)
		spr->angle += 2 * M_PI;
	spr->size = all->scr_height * CUB_SIZE / spr->len;
}
