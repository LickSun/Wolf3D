/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:04:59 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:05 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_key_up(t_all *all)
{
	double	x;
	double	y;

	y = all->player.y_pos + sin(all->player.a_pos) * CUB_SIZE / 8;
	x = all->player.x_pos + cos(all->player.a_pos) * CUB_SIZE / 8;
	if (all->map[(int)(all->player.y_pos / CUB_SIZE)]
			[(int)(x / CUB_SIZE)] != '1')
		all->player.x_pos = x;
	if (all->map[(int)(y / CUB_SIZE)]
			[(int)(all->player.x_pos / CUB_SIZE)] != '1')
		all->player.y_pos = y;
	return (1);
}

int		ft_key_down(t_all *all)
{
	double	x;
	double	y;

	y = all->player.y_pos - sin(all->player.a_pos) * CUB_SIZE / 8;
	x = all->player.x_pos - cos(all->player.a_pos) * CUB_SIZE / 8;
	if (all->map[(int)(all->player.y_pos / CUB_SIZE)]
			[(int)(x / CUB_SIZE)] != '1')
		all->player.x_pos = x;
	if (all->map[(int)(y / CUB_SIZE)]
			[(int)(all->player.x_pos / CUB_SIZE)] != '1')
		all->player.y_pos = y;
	return (1);
}

int		ft_key_left(t_all *all)
{
	double	x;
	double	y;

	y = all->player.y_pos - cos(all->player.a_pos) * CUB_SIZE / 8;
	x = all->player.x_pos + sin(all->player.a_pos) * CUB_SIZE / 8;
	if (all->map[(int)(all->player.y_pos / CUB_SIZE)]
			[(int)(x / CUB_SIZE)] != '1')
		all->player.x_pos = x;
	if (all->map[(int)(y / CUB_SIZE)]
			[(int)(all->player.x_pos / CUB_SIZE)] != '1')
		all->player.y_pos = y;
	return (1);
}

int		ft_key_right(t_all *all)
{
	double	x;
	double	y;

	x = all->player.x_pos - sin(all->player.a_pos) * CUB_SIZE / 8;
	y = all->player.y_pos + cos(all->player.a_pos) * CUB_SIZE / 8;
	if (all->map[(int)(all->player.y_pos / CUB_SIZE)]
			[(int)(x / CUB_SIZE)] != '1')
		all->player.x_pos = x;
	if (all->map[(int)(y / CUB_SIZE)]
			[(int)(all->player.x_pos / CUB_SIZE)] != '1')
		all->player.y_pos = y;
	return (1);
}
