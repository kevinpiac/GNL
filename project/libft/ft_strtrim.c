/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:48:57 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/27 22:25:55 by kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			len;
	size_t			less;

	i = 0;
	less = 0;
	len = ft_strlen(s);
	while (ft_istoskip(" \n\t", s[i]) && s[i])
		i++;
	if (!s[i])
		return ("");
	while (ft_istoskip(" \n\t", s[--len]))
		less++;
	len = ft_strlen(s) - i - less;
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_strncpy(str, &s[i], len);
	return (str);
}
