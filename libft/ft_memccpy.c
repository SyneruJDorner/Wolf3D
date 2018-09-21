/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:48:34 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/05 07:50:05 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *desination, const void *source, int c, size_t n)
{
	char	char_c;
	char	*dst;
	char	*src;

	dst = (char*)desination;
	src = (char*)source;
	char_c = (char)c;
	while (n > 0)
	{
		if (*src == char_c)
		{
			*dst++ = *src++;
			return (dst);
		}
		*dst++ = *src++;
		n--;
	}
	return (0);
}
