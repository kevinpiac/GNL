/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:13:16 by kevin             #+#    #+#             */
/*   Updated: 2016/03/04 14:18:06 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!(tmp = (char *)ft_memalloc(n)))
		return (NULL);
	ft_memcpy(tmp, s2, n);
	while (i < n)
	{
		((char *)s1)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (s1);
}
