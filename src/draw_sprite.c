/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:22:11 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:25 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_draw_sprite(t_all *all, t_sprite *spr,
							int h_offset, int v_offset)
{
	int			i;
	int			j;
	int			color;
	double		coef;

	coef = (double)(all->texture_spr.height) / spr->size;
	i = -1;
	while (++i < spr->size)
	{
		if (h_offset + i < 0 || h_offset + i >= all->scr_width)
			continue;
		if (all->rays[h_offset + i] < spr->len)
			continue;
		j = -1;
		while (++j < spr->size)
		{
			if (v_offset + j < 0 || v_offset + j >= all->scr_height)
				continue;
			color = ft_get_color_texture(&(all->texture_spr),
					i * coef, j * coef);
			if (color > 0)
				my_mlx_pixel_put(all, h_offset + i, v_offset + j, color);
		}
	}
}

void			ft_rend_sprite(t_all *all, t_sprite *spr)
{
	int			h_offset;
	int			v_offset;

	ft_init_spr_params(all, spr);
	h_offset = (spr->angle - all->player.a_pos) * all->scr_width / FOV
		+ all->scr_width / 2 - spr->size / 2;
	v_offset = all->scr_height / 2 - spr->size / 2;
	ft_draw_sprite(all, spr, h_offset, v_offset);
}

void			ft_rend_sprites(t_all *all)
{
	t_sprite	*tmp;

	ft_sort_sprites(all);
	tmp = all->sprite;
	while (tmp != NULL)
	{
		ft_rend_sprite(all, tmp);
		tmp = tmp->next;
	}
}
