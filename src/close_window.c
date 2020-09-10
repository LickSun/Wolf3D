/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 23:12:08 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:34 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_free_all(t_all *all)
{
	int		i;

	i = -1;
	if (all->rays)
		free(all->rays);
	if (all->sprite)
		ft_sprclear(&(all->sprite));
	if (all->map)
		while (all->map[++i])
			free(all->map[i]);
}

int			ft_close_window(t_all *all)
{
	ft_free_all(all);
	exit(0);
}
