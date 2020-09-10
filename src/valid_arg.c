/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:51:29 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:51:23 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_name(int len, char *str)
{
	int j;
	int flag;

	flag = 0;
	j = len - 4;
	if (j > 0 && str[j - 1] && str[j] == '.' && str[j + 1] == 'c'
		&& str[j + 2] == 'u' && str[j + 3] == 'b' && str[j + 4] == '\0')
		flag = 1;
	return (flag);
}

int			ft_valid_arguments(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (0);
	}
	if (!ft_check_name(ft_strlen(argv[1]), argv[1]))
	{
		ft_putstr_fd("Error: Invalid file\n", 2);
		return (0);
	}
	if (argc == 3)
		if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0)
		{
			ft_putstr_fd("Error: Invalid argument\n", 2);
			return (0);
		}
	return (1);
}

int			ft_valid_file(t_all *all, char *str)
{
	int fd;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error: No such file or directory\n", 2);
		return (0);
	}
	all->fd = fd;
	return (1);
}
