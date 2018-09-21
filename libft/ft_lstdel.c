/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 08:46:47 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/01 11:46:32 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nextnode;

	if (*alst)
	{
		while (*alst)
		{
			nextnode = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			(*alst) = nextnode;
		}
		(*alst) = NULL;
	}
}
