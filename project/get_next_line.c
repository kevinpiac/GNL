/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:44:47 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/31 18:52:50 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

t_gnl	*gnl_findbyfd(t_gnl **lst, int fd)
{

}

char	*gnl_findline(t_gnl *old_rest, int end)
{
	char	*line;
	char	*new_rest;
	size_t	len;

	line = NULL;
	len = 0;
	new_rest = NULL;
	if (old_rest->content)
	{
		if ((new_rest = ft_strchr(old_rest->content, '\n')))
		{
			old_rest->content = ft_strdup(&new_rest[1]);
			while (new_rest[len] != '\n')
				len++;
			line = ft_strnew(len);
			line = ft_strncpy(line, new_rest, len);
		}
		else
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

	if (!old_rest)
	{
		// init the old_rest here
	}
	if (old_rest->content && buf)
	{
		if (!(new_rest = ft_strjoin(old_rest->content, buf)))
			return (NULL);
		ft_memdel(&(old_rest)->content);
		old_rest->content = new_rest;
	}
	else if (buf)
	{
		if (!(new_rest = ft_strdup(buf)))
			return (NULL);
	}
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
		{

		}
	}
	return (0);
}
