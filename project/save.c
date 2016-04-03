/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:44:47 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/31 22:22:37 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

t_gnl	*gnl_setrest(char *buf, size_t ret, int fd, t_gnl **lst)
{
  t_gnl		*elem;

  elem = *lst;
  while (elem && elem->fd)
    elem = elem->next;
  if (!elem && ret)
    {
      elem = (t_gnl *)ft_lstnew(buf, ret);
      elem->fd = fd;
      ft_lstadd((t_list **)lst, (t_list *)elem);
    }
  else if (elem && ret)
      elem->content = (void *)ft_strjoin(elem->content, buf);
  return (elem);
}

int	gnl_getline(t_gnl *rest, char **line)
{
  char		*after_lfeed;
  char		*old_rest;
  char		*new_rest;
  int		len;

  len = 0;
  if ((after_lfeed = ft_strchr(rest->content, '\n')))
    {
      old_rest = rest->content;
      while (old_rest[len] != '\n')
	len++;
      //      ft_memdel((void **)line);
      *line = ft_strsub(old_rest, 0, len);
      new_rest = ft_strdup(&after_lfeed[1]);
      ft_memdel((void **)&old_rest);
      rest->content = new_rest;
      return (1);
    }
  else
    return (0);
}

int	get_next_line(int fd, char **line)
{
  static t_gnl	*lst;
  t_gnl		*rest;
  char		buf[BUFF_SIZE + 1];
  size_t	ret;

  if (fd == -1)
    return (-1);
  ret = read(fd, buf, BUFF_SIZE);
  buf[BUFF_SIZE] = '\0';
  //printf("buf: %s, ret: %zu, fd: %d\n", buf, ret, fd);
  rest = gnl_setrest(buf, ret, fd, &lst);
  if (rest)
    {
      if (gnl_getline(rest, line))
	return (1);
      return (get_next_line(fd, line));
    }
  else
    return (0);
}
