/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:29:11 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:51:48 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		**read_map(t_all *all, t_list **head, int size)
{
	char	**map;
	int		i;
	int		len;
	t_list	*tmp;

	i = -1;
	tmp = *head;
	if (!(map = ft_calloc(size + 1, sizeof(char *))))
		return (NULL);
	while (tmp)
	{
		map[++i] = (char *)tmp->content;
		len = ft_strlen(map[i]);
		if (len > all->map_len)
			all->map_len = len;
		tmp = tmp->next;
	}
	all->map_height = i;
	map[++i] = NULL;
	return (map);
}

int			flood_fill(int map_height, int x, int y, char **map)
{
	if (((size_t)x > ft_strlen(map[y]) - 1) \
			|| map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1')
		return (1);
	else if (y == 0 || y == map_height \
			|| x == 0 || (size_t)x == ft_strlen(map[y]) - 1)
		return (0);
	if (map[y][x] == '*')
		return (1);
	map[y][x] = '*';
	if (!(flood_fill(map_height, x + 1, y, map)))
		return (0);
	if (!(flood_fill(map_height, x - 1, y, map)))
		return (0);
	if (!(flood_fill(map_height, x, y + 1, map)))
		return (0);
	if (!(flood_fill(map_height, x, y - 1, map)))
		return (0);
	return (1);
}

int			ft_check_map(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != '*' && map[i][j] != '1' && map[i][j] != '2')
				map[i][j] = '1';
			if (map[i][j] == '*')
				map[i][j] = '0';
		}
	}
	return (1);
}

int			ft_fill_map(t_all *all, char **map)
{
	int		i;
	char	*tmp;
	int		j;

	i = -1;
	while (map[++i])
	{
		tmp = map[i];
		if (!(map[i] = (char *)malloc((all->map_len + 1) * sizeof(char))))
			return (0);
		j = -1;
		while (tmp[++j])
		{
			map[i][j] = tmp[j];
			if (map[i][j] == ' ')
				map[i][j] = '1';
		}
		while (j++ < all->map_len)
			map[i][j - 1] = '1';
		map[i][j] = '\0';
		free(tmp);
	}
	return (1);
}
