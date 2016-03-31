/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:37:33 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/28 17:45:06 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*s2;
	size_t			len;

	len = ft_strlen(s1);
	if (!(s2 = ft_strnew(len)))
		return (NULL);
	while (len--)
		s2[len] = s1[len];
	return (s2);
}
