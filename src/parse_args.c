/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:05:38 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 13:42:27 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_find_params(t_all *all, char *ptr)
{
	int		flag;

	flag = 0;
	if (*ptr == 'R')
		flag = ft_read_sizes(all, ptr + 1);
	else if (*ptr == 'F' || *ptr == 'C')
		flag = ft_read_floor_cell(all, ptr);
	else if (*ptr == 'N')
		flag = ft_read_texture("NO", ptr, &(all->texture_n));
	else if (*ptr == 'W')
		flag = ft_read_texture("WE", ptr, &(all->texture_w));
	else if (*ptr == 'E')
		flag = ft_read_texture("EA", ptr, &(all->texture_e));
	else if (*ptr == 'S' && *(ptr + 1) == 'O')
		flag = ft_read_texture("SO", ptr, &(all->texture_s));
	else if (*ptr == 'S')
		flag = ft_read_texture("S", ptr, &(all->texture_spr));
	return (flag);
}

int			ft_read_sizes(t_all *all, char *str)
{
	char	*ptr;
	int		width;
	int		height;

	if (all->scr_height != 0 && all->scr_width != 0)
		return (0);
	mlx_get_screen_size(all->mlx.mlx, &(all->scr_width), &(all->scr_height));
	ptr = str;
	if (*ptr != ' ')
		return (0);
	ptr = ft_skip_spaces(ptr);
	width = ft_valid_atoi(ptr);
	if (*(ptr = ft_skip_numb(ptr)) != ' ')
		return (0);
	ptr = ft_skip_spaces(ptr);
	height = ft_valid_atoi(ptr);
	ptr = ft_skip_numb(ptr);
	ptr = ft_skip_spaces(ptr);
	if (*ptr != '\0')
		return (0);
	if (all->scr_height > height)
		all->scr_height = height;
	if (all->scr_width > width)
		all->scr_width = width;
	return (1);
}

int			ft_read_floor_cell(t_all *all, char *str)
{
	char	*ptr;
	int		tmp[3];
	int		i;

	if (all->color_floor != -1 && all->color_ceilling != -1)
		return (0);
	if (*(ptr = str + 1) != ' ')
		return (0);
	ptr = ft_skip_spaces(ptr);
	i = -1;
	while (++i < 3)
	{
		tmp[i] = ft_valid_atoi(ptr);
		ptr += ft_numb_len(tmp[i]);
		if (*ptr != ',' && i != 2)
			return (0);
		if (*ptr != '\0')
			ptr++;
	}
	ptr = ft_skip_spaces(ptr);
	if (*ptr != '\0')
		return (0);
	if (!ft_read_colors(*str, tmp, all))
		return (0);
	return (1);
}

int			ft_read_texture(char *name, char *str, t_texture *texture)
{
	char	*ptr;
	int		len;
	char	*path;
	int		i;

	i = 0;
	len = 0;
	if (texture->path != NULL)
		return (0);
	ptr = str;
	if (ft_strncmp(name, ptr, ft_strlen(name)) != 0)
		return (0);
	if (*(ptr += ft_strlen(name)) != ' ')
		return (0);
	ptr = ft_skip_spaces(ptr);
	while (ptr[len] != ' ' && ptr[len] != '\0')
		len++;
	if (!(path = ft_strtrim(ptr, " ")))
		return (0);
	if (ft_strlen(path) != (size_t)len)
		return (0);
	texture->path = path;
	return (1);
}

int			ft_read_colors(char ch, int *tmp, t_all *all)
{
	int color;

	if (tmp[0] > 255 || tmp[1] > 255 || tmp[2] > 255)
		return (0);
	color = 0 << 24 | tmp[0] << 16 | tmp[1] << 8 | tmp[2] << 0;
	if (ch == 'F')
	{
		if (all->color_floor != -1)
			return (0);
		all->color_floor = color;
	}
	else
	{
		if (all->color_ceilling != -1)
			return (0);
		all->color_ceilling = color;
	}
	return (1);
}
