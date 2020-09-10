/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 11:32:17 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:50:58 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

void				bmp_header(t_all *all, int file_size, int fd)
{
	unsigned char bmp_arr[54];

	ft_bzero(bmp_arr, 54);
	bmp_arr[0] = (unsigned char)('B');
	bmp_arr[1] = (unsigned char)('M');
	int_to_char(file_size, bmp_arr + 2);
	bmp_arr[10] = (unsigned char)(54);
	bmp_arr[14] = (unsigned char)(40);
	int_to_char(all->scr_width, bmp_arr + 18);
	int_to_char(all->scr_height, bmp_arr + 22);
	bmp_arr[26] = (unsigned char)(1);
	bmp_arr[28] = (unsigned char)(24);
	write(fd, bmp_arr, 54);
}

void				ft_fool_bmp(t_all *all, int fd)
{
	int				i;
	int				j;
	int				color;

	i = all->scr_height - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < all->scr_width)
		{
			color = ft_get_color_win(all, j, i);
			write(fd, &color, 3);
		}
		i--;
	}
}

int					ft_screen_shot(t_all *all)
{
	int				fd;
	unsigned int	len;

	while (all->scr_width % 4 != 0)
		all->scr_width--;
	len = 54 + (4 * all->scr_height * all->scr_width);
	if (!(fd = open("SCREENSHOT.bmp", O_WRONLY | O_CREAT
			| O_TRUNC | O_APPEND, 0666)))
	{
		perror("Error");
		return (0);
	}
	bmp_header(all, len, fd);
	ft_fool_bmp(all, fd);
	close(fd);
	return (1);
}
