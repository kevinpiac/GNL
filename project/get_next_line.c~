/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:44:47 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/31 22:05:46 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

t_gnl	*gnl_findbyfd(t_gnl **lst, int fd)
{
	t_gnl	*elem;

	elem = *lst;
	while (elem && elem->fd != fd)
		elem = elem->next;
	if (!elem)
	{
		elem = (t_gnl *)ft_lstnew(0, 0);
		elem->fd = fd;
		ft_lstadd((t_list **)lst, (t_list *)elem);
	}
	return (elem);
}

char	*gnl_findline(t_gnl *old_rest, int end)
{
	char	*line;
	char	*new_rest;
	char	*rest;
	size_t	len;

	line = NULL;
	len = 0;
	new_rest = NULL;
	rest = NULL;
	if (old_rest->content && ft_strlen(old_rest->content))
	{
		if ((new_rest = ft_strchr(old_rest->content, '\n')))
		{
			rest = old_rest->content;
			while (rest[len] != '\n')
				len++;
			line = ft_strsub(rest, 0, len);
			old_rest->content = ft_strdup(&new_rest[1]);
			ft_memdel((void *)&rest);
		}
		else if (end)
		{
			line = ft_strdup(old_rest->content);
			ft_memdel(&(old_rest)->content);
		}
	}
	return (line);
}

void	gnl_setrest(t_gnl *old_rest, char *buf)
{
	char	*new_rest;

	new_rest = NULL;
	if (old_rest->content && buf)
	{
		new_rest = ft_strjoin(old_rest->content, buf);
		ft_memdel(&(old_rest)->content);
		old_rest->content = ft_strdup(new_rest);
//		ft_memdel((void *)&new_rest); // not sure.
	}
	else if (buf)
		old_rest->content = ft_strdup(buf);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*old_rest;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd == -1)
		return (-1);
	old_rest = gnl_findbyfd(&lst, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		gnl_setrest(old_rest, buf);
		if ((*line = gnl_findline(old_rest, 0)))
			return (1);
	}
	gnl_setrest(old_rest, NULL);
	if ((*line = gnl_findline(old_rest, 1)))
		return (1);
	return (0);
}
