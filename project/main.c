/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:55:13 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/03 11:07:21 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main only for smooth testing.

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int		main(int ac, char **av)
{
	char *line;
	int	fd;
	(void)ac;
	line = ft_strnew(1);

	fd = open(av[1], O_RDONLY);
	int i;
	i = 0;

	while (get_next_line(fd, &line) > 0)
	{
		printf("line[%d]->%s\n",i,line);
		i++;
	}
}
