/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:42:25 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:13 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_init_player(t_all *all, char ch, int i, int j)
{
	if (all->player.flag)
		return (0);
	all->player.x_pos = j * CUB_SIZE + CUB_SIZE / 2;
	all->player.y_pos = i * CUB_SIZE + CUB_SIZE / 2;
	if (ch == 'E')
		all->player.a_pos = 0;
	else if (ch == 'W')
		all->player.a_pos = M_PI;
	else if (ch == 'S')
		all->player.a_pos = M_PI / 2;
	else if (ch == 'N')
		all->player.a_pos = -M_PI / 2;
	all->map[i][j] = '0';
	all->player.flag = 1;
	return (1);
}

int				ft_cell_check(t_all *all, t_sprite **spr, int i, int j)
{
	if (!ft_strchr(" 012NSWE", all->map[i][j]))
		return (0);
	if (all->map[i][j] == '2')
	{
		all->spr_flag = 1;
		ft_lstadd_back_sprite(spr, ft_lstnew_sprite(j * CUB_SIZE \
		+ CUB_SIZE / 2, i * CUB_SIZE + CUB_SIZE / 2));
	}
	if (ft_strchr("NSWE", all->map[i][j]))
		if (!ft_init_player(all, all->map[i][j], i, j))
			return (0);
	return (1);
}

int				ft_init_p_s(t_all *all)
{
	int			i;
	int			j;
	t_sprite	*spr;

	spr = NULL;
	i = -1;
	while (all->map[++i])
	{
		j = -1;
		while (all->map[i][++j])
			if (!ft_cell_check(all, &spr, i, j))
				return (0);
	}
	if ((!(all->sprite = spr) && all->spr_flag) || !all->player.flag)
		return (0);
	return (1);
}
