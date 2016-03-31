/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:20:52 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/03 12:31:28 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t len;
	size_t i;

	i = 0;
	while (dst[i] && i < n)
		i++;
	len = i;
	while (src[i - len] && i < n - 1)
	{
		dst[i] = src[i - len];
		i++;
	}
	if (len < n)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
