/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:23:04 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/28 17:27:57 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	size_t	len1;

	len1 = ft_strlen(s1);
	if (!(s = ft_memalloc(len1 + ft_strlen(s2))))
		return (NULL);
	s = ft_strcpy(s, s1);
	s = ft_strcat(s, s2);
	return (s);
}
