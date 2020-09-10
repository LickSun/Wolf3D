/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmidori <lmidori@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 21:54:38 by lmidori           #+#    #+#             */
/*   Updated: 2020/09/08 12:51:52 by lmidori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_parse_file(t_all *all)
{
	t_list	*tmp;

	if (!ft_parse_lines(&(all->head), all))
	{
		ft_putstr_fd("Error: File cannot be read\n", 2);
		return (0);
	}
	tmp = all->head;
	if (!ft_init_params(all, &tmp))
		return (0);
	all->rays = (double *)malloc(all->scr_width * sizeof(double));
	return (1);
}

int			ft_parse_lines(t_list **head, t_all *all)
{
	int		res;
	char	*line;

	while ((res = get_next_line(all->fd, &line)) > 0)
		ft_lstadd_back(head, ft_lstnew(line));
	if (res == -1)
		return (0);
	ft_lstadd_back(head, ft_lstnew(line));
	if (!(*head))
		return (0);
	return (1);
}

int			ft_init_params(t_all *all, t_list **head)
{
	t_list	*tmp;
	char	*ptr;

	tmp = *(head);
	while (tmp != NULL)
	{
		ptr = (char *)tmp->content;
		if (*(ptr = ft_skip_spaces(ptr)) == '\0')
		{
			tmp = tmp->next;
			continue;
		}
		if (ft_check_params(all))
			break ;
		if (!ft_find_params(all, ptr))
			break ;
		tmp = tmp->next;
	}
	tmp = ft_skip_empty_lines(tmp);
	if (!ft_check_all(all, tmp))
		return (0);
	ft_check_map(all->map);
	return (1);
}

int			ft_check_params(t_all *all)
{
	if (all->color_ceilling != -1 && all->color_floor != -1
			&& all->scr_height != 0 && all->scr_width != 0
			&& all->texture_e.path != NULL && all->texture_n.path != NULL
			&& all->texture_spr.path != NULL && all->texture_w.path != NULL
			&& all->texture_s.path != NULL)
		return (1);
	return (0);
}

t_list		*ft_skip_empty_lines(t_list *tmp)
{
	char	*ptr;

	while (tmp != NULL)
	{
		ptr = (char *)tmp->content;
		if (*(ptr = ft_skip_spaces(ptr)) == '\0')
		{
			tmp = tmp->next;
			continue;
		}
		else
			break ;
	}
	return (tmp);
}
