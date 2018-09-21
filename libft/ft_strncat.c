/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:19:07 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/01 12:47:29 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *source, size_t n)
{
	int i;
	int j;

	i = -1;
	j = (int)ft_strlen(destination);
	while (*(source + ++i) && i < (int)n)
		*(destination + j++) = *(source + i);
	*(destination + j) = '\0';
	return (destination);
}
