/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 09:29:50 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 13:49:06 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount(t_list *lst)
{
	int		size;
	t_list	*tmp_lst;

	size = 0;
	tmp_lst = lst;
	while (tmp_lst != NULL)
	{
		size++;
		tmp_lst = tmp_lst->next;
	}
	ft_lstfree(tmp_lst);
	return (size);
}
