/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:28:55 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:51:44 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_raycast(t_all *all, double angle)
{
	double		c;
	double		x;
	double		y;

	c = 0;
	x = all->player.x_pos;
	y = all->player.y_pos;
	while (all->map[(int)(y / CUB_SIZE)][(int)(x / CUB_SIZE)] != '1')
	{
		x = all->player.x_pos + c * cos(angle);
		y = all->player.y_pos + c * sin(angle);
		c += 0.05;
	}
	all->player.x_break = x;
	all->player.y_break = y;
}

t_texture		*ft_find_texture(t_all *all, double angle)
{
	t_texture	*text;

	text = &(all->texture_e);
	if (all->map[(int)all->player.y_break / CUB_SIZE]
			[(int)all->player.x_break / CUB_SIZE]
			!= all->map[(int)all->player.y_break / CUB_SIZE]
			[(int)(all->player.x_break - 0.05 * fabs(cos(angle))) / CUB_SIZE])
		text = &(all->texture_e);
	else if (all->map[(int)all->player.y_break / CUB_SIZE]
			[(int)all->player.x_break / CUB_SIZE]
			!= all->map[(int)all->player.y_break / CUB_SIZE]
			[(int)(all->player.x_break + 0.05 * fabs(cos(angle))) / CUB_SIZE])
		text = &(all->texture_w);
	else if (all->map[(int)all->player.y_break / CUB_SIZE]
			[(int)all->player.x_break / CUB_SIZE]
			!= all->map[(int)(all->player.y_break + 0.05 * fabs(sin(angle)))
			/ CUB_SIZE][(int)all->player.x_break / CUB_SIZE])
		text = &(all->texture_n);
	else if (all->map[(int)all->player.y_break / CUB_SIZE]
			[(int)all->player.x_break / CUB_SIZE] !=
			all->map[(int)(all->player.y_break - 0.05 * fabs(sin(angle)))
			/ CUB_SIZE][(int)all->player.x_break / CUB_SIZE])
		text = &(all->texture_s);
	return (text);
}

void			ft_rend_floor_ceilling(t_all *all, int x, int y_start_wall)
{
	int			i;

	i = 0;
	while (i < y_start_wall)
	{
		my_mlx_pixel_put(all, x, i, all->color_ceilling);
		my_mlx_pixel_put(all, x, all->scr_height - i - 1, all->color_floor);
		i++;
	}
	if (y_start_wall != 0)
	{
		my_mlx_pixel_put(all, x, all->scr_height - (i++), all->color_floor);
		my_mlx_pixel_put(all, x, all->scr_height - (i++), all->color_floor);
		my_mlx_pixel_put(all, x, all->scr_height - (i), all->color_floor);
	}
}

double			ft_text_pos(t_all *all, double angle)
{
	double		text_pos;

	if (all->map[(int)(all->player.y_break / CUB_SIZE)]
			[(int)(all->player.x_break / CUB_SIZE)]
			!= all->map[(int)((all->player.y_break - 0.05 * sin(angle))
			/ CUB_SIZE)][(int)(all->player.x_break / CUB_SIZE)])
		text_pos = all->player.x_break;
	else
		text_pos = all->player.y_break;
	return (text_pos);
}

void			ft_rend_3d(t_all *all, int x, double h_wall, double angle)
{
	int			j;
	int			color;
	double		text_pos;
	int			y1;
	t_texture	*text;

	text = ft_find_texture(all, angle);
	all->y_start_wall = all->scr_height / 2 - h_wall / 2;
	y1 = all->y_start_wall;
	if (all->y_start_wall < 0)
	{
		y1 = abs(all->y_start_wall);
		all->y_start_wall = 0;
	}
	all->coef = text->height / h_wall;
	all->y_end_wall = all->scr_height - all->y_start_wall;
	j = all->y_start_wall;
	text_pos = ft_text_pos(all, angle);
	while (all->y_start_wall != all->y_end_wall)
	{
		color = ft_get_color_texture(text, (int)(text_pos * 2)
				% text->height, (y1++ - j) * all->coef);
		my_mlx_pixel_put(all, x, all->y_start_wall++, color);
	}
	ft_rend_floor_ceilling(all, x, j);
}
