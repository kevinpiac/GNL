/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 09:42:54 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/04 08:17:51 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	len;
	int				tmp;
	int				neg;
	char			*res;

	tmp = n;
	len = 1;
	neg = 0;
	n >= 0 ? 0 : (neg = 1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (tmp /= 10)
		len++;
	if (!(res = ft_strnew(len + neg)))
		return (NULL);
	if (neg)
		res[0] = '-';
	while (len--)
	{
		res[len + neg] = ABS(n % 10) + '0';
		n /= 10;
	}
	return (res);
}
