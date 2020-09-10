/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:20:19 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:52:29 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_all	all;

	ft_init_struct(&all);
	if (!ft_valid_arguments(argc, argv)
			|| !ft_valid_file(&all, argv[1])
			|| !ft_parse_file(&all))
		ft_close_window(&all);
	if (!(ft_init_mlx(&all)) || !(ft_init_textures(&all)))
	{
		ft_putstr_fd("Error: Invalid address\n", 2);
		ft_close_window(&all);
	}
	ft_rend_all(argc, &all);
	ft_close_window(&all);
	return (0);
}
