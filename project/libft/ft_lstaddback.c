/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 09:59:23 by kpiacent          #+#    #+#             */
/*   Updated: 2016/03/04 12:52:34 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list	*alstcp;

	alstcp = *alst;
	if (*alst == NULL)
	{
		*alst = ft_lstnew(new->content, new->content_size);
		return ;
	}
	while (alstcp->next)
		alstcp = alstcp->next;
	alstcp->next = new;
}
