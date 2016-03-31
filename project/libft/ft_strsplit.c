/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:19:21 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/04 13:58:40 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	wordcount(char const *s, int c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c && (i == 0 || *(s - 1) == c))
			i++;
		s++;
	}
	return (i);
}

static size_t	wordlen(char const *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	**tabcpy;
	size_t	len;

	if (!(tab = (char **)ft_memalloc(sizeof(char *) * wordcount(s, c) + 1)))
		return (NULL);
	tabcpy = tab;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = wordlen(s, c);
			if (!(*tabcpy = ft_strnew(len)))
				return (NULL);
			ft_strncpy(*tabcpy, s, len);
			s = (s + len);
			tabcpy++;
		}
	}
	*tabcpy = NULL;
	return (tab);
}
