/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 07:39:36 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/05 07:49:42 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	const char	*src;
	char		*dest;

	dest = (char*)source;
	dest = (char*)destination;
	src = (char*)source;
	if (n <= 0)
	{
		dest = (char*)"";
		return (destination);
	}
	dest = (char*)source;
	dest = (char*)destination;
	src = (char*)source;
	while ((int)n-- > 0)
		*dest++ = *src++;
	return (destination);
}
