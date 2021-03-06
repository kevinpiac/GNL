/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:45:08 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/04 14:40:38 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"

typedef	struct		s_gnl
{
	void			*content;
	size_t			content_size;
	struct s_gnl	*next;
	int				fd;
}					t_gnl;

int					get_next_line(int fd, char **line);

#endif
