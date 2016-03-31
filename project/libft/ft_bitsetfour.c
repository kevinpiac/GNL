/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsetfour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 18:28:04 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/07 13:47:27 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitsetfour(unsigned int *i, unsigned int val, unsigned int index)
{
	unsigned int	n;

	n = *i;
	n &= ~(15 << index * 4);
	n |= (val << index * 4);
	*i = n;
}
