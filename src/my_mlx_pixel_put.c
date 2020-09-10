/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:14:02 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:01 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->mlx.addr + (y * all->mlx.line_length
		+ x * (all->mlx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			ft_get_color_texture(t_texture *texture, int x, int y)
{
	char	*dst;
	int		color;

	dst = texture->addr + (y * texture->line_length
		+ x * (texture->bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

int			ft_get_color_win(t_all *data, int x, int y)
{
	char	*dst;
	int		color;

	dst = data->mlx.addr + (y * data->mlx.line_length
		+ x * (data->mlx.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}

void		ft_fill_black(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < all->scr_height)
	{
		j = -1;
		while (++j < all->scr_width)
			my_mlx_pixel_put(all, j, i, 0x00000);
	}
}
