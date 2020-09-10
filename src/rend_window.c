/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:18:27 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:51:37 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_rend_window(t_all *all)
{
	int		i;
	double	angle;
	double	h_wall;
	double	min_len;

	i = 0;
	while (i < all->scr_width)
	{
		angle = all->player.a_pos - FOV / 2 + (FOV * i) / all->scr_width;
		ft_raycast(all, angle);
		min_len = sqrt((pow(all->player.y_break - all->player.y_pos, 2))
			+ (pow(all->player.x_break - all->player.x_pos, 2)));
		all->rays[i] = min_len;
		h_wall = all->scr_height * CUB_SIZE / min_len
				/ cos(angle - all->player.a_pos);
		ft_rend_3d(all, i++, h_wall, angle);
	}
	if (all->spr_flag)
		ft_rend_sprites(all);
}

int			ft_rend_all(int argc, t_all *all)
{
	ft_rend_window(all);
	if (argc == 3)
	{
		ft_screen_shot(all);
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
		ft_close_window(all);
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	mlx_hook(all->mlx.win, 2, 1L << 0, ft_key_press, all);
	mlx_hook(all->mlx.win, 17, 0L, &ft_close_window, all);
	mlx_loop(all->mlx.mlx);
	ft_free_all(all);
	ft_close_window(all);
	return (1);
}
