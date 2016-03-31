/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:16:26 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/28 12:18:24 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*res;
	char		*b;

	if (!(res = ft_strnew(ft_strlen(s))))
		return (NULL);
	b = res;
	while (*s)
		*res++ = f(*s++);
	return (b);
}
