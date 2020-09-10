/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:47:24 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:16 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_init_struct(t_all *all)
{
	all->color_ceilling = -1;
	all->color_floor = -1;
	all->scr_height = 0;
	all->scr_width = 0;
	all->texture_e.path = NULL;
	all->texture_n.path = NULL;
	all->texture_s.path = NULL;
	all->texture_spr.path = NULL;
	all->texture_w.path = NULL;
	all->sprite = NULL;
	all->map = NULL;
	all->player.flag = 0;
	all->map_len = 0;
	all->map_height = 0;
	all->spr_flag = 0;
	all->rays = NULL;
	all->head = NULL;
}

int			ft_init_mlx(t_all *all)
{
	all->mlx.mlx = mlx_init();
	if (!(all->mlx.win = mlx_new_window(all->mlx.mlx,
		all->scr_width, all->scr_height, "WOLF")))
		return (0);
	if (!(all->mlx.img = mlx_new_image(all->mlx.mlx,
		all->scr_width, all->scr_height)))
		return (0);
	if (!(all->mlx.addr = mlx_get_data_addr(all->mlx.img,
		&all->mlx.bits_per_pixel, &all->mlx.line_length,
				&all->mlx.endian)))
		return (0);
	return (1);
}

int			ft_init_text(t_all *all, t_texture *texture)
{
	if (!(texture->img = mlx_xpm_file_to_image(all->mlx.mlx, texture->path,
					&texture->width, &texture->height)))
		return (0);
	if (!(texture->addr = mlx_get_data_addr(texture->img,
		&texture->bits_per_pixel,
		&texture->line_length, &texture->endian)))
		return (0);
	return (1);
}

int			ft_init_textures(t_all *all)
{
	if (!ft_init_text(all, &(all->texture_n))
		|| !ft_init_text(all, &(all->texture_e))
		|| !ft_init_text(all, &(all->texture_w))
		|| !ft_init_text(all, &(all->texture_s))
		|| !ft_init_text(all, &(all->texture_spr)))
		return (0);
	return (1);
}
