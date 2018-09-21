/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 09:24:35 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/05 08:03:16 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*nxtlst;
	t_list	*begin;

	if (lst == NULL)
		return (NULL);
	nxtlst = f(lst);
	newlst = ft_lstnew(nxtlst->content, nxtlst->content_size);
	if (newlst == NULL)
		return (NULL);
	begin = newlst;
	lst = lst->next;
	while (lst)
	{
		nxtlst = f(lst);
		newlst->next = ft_lstnew(nxtlst->content, nxtlst->content_size);
		if (newlst == NULL)
			return (NULL);
		newlst = newlst->next;
		lst = lst->next;
	}
	return (begin);
}
