/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 10:56:50 by kpiacent          #+#    #+#             */
/*   Updated: 2016/02/29 10:58:11 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputendl(t_list *lst)
{
	while (lst)
	{
		write(1, lst->content, lst->content_size);
		ft_putchar('\n');
		lst = lst->next;
	}
}
