/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:09:14 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:09 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_key_action(int keycode, t_all *all)
{
	int		flag;

	flag = 0;
	if (keycode == 13)
		flag = ft_key_up(all);
	else if (keycode == 1)
		flag = ft_key_down(all);
	else if (keycode == 0)
		flag = ft_key_left(all);
	else if (keycode == 2)
		flag = ft_key_right(all);
	else if (keycode == 123)
		flag = ft_key_turn_left(all);
	else if (keycode == 124)
		flag = ft_key_turn_right(all);
	else if (keycode == 53)
		ft_close_window(all);
	return (flag);
}

int			ft_key_turn_left(t_all *all)
{
	all->player.a_pos -= 0.1;
	if (all->player.a_pos < 0)
		all->player.a_pos += 2 * M_PI;
	return (1);
}

int			ft_key_turn_right(t_all *all)
{
	all->player.a_pos += 0.1;
	if (all->player.a_pos > 2 * M_PI)
		all->player.a_pos -= 2 * M_PI;
	return (1);
}

int			ft_key_press(int keycode, t_all *all)
{
	if (!ft_key_action(keycode, all))
		return (1);
	ft_fill_black(all);
	ft_rend_window(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	return (1);
}
