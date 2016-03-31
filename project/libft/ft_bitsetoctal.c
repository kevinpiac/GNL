/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsetoctal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:47:33 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/07 13:48:06 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitsetoctal(unsigned int *i, unsigned int val, unsigned int index)
{
	unsigned int	n;

	n = *i;
	n &= ~(255 << index * 8);
	n |= (val << index * 8);
	*i = n;
}
