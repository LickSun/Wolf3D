/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:01:09 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:40 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_all(t_all *all, t_list *tmp)
{
	if (!ft_check_params(all))
	{
		ft_putstr_fd("Error file arguments\n", 2);
		return (0);
	}
	if (!(all->map = read_map(all, &tmp, ft_lstsize(tmp))))
	{
		ft_putstr_fd("Error the memory could not be allocated\n", 2);
		return (0);
	}
	if (!ft_init_p_s(all) || !flood_fill(all->map_height, all->player.x_pos
		/ CUB_SIZE, all->player.y_pos / CUB_SIZE, all->map))
	{
		ft_putstr_fd("Error map\n", 2);
		return (0);
	}
	if (!ft_fill_map(all, all->map))
	{
		ft_putstr_fd("Error the memory could not be allocated\n", 2);
		return (0);
	}
	return (1);
}
