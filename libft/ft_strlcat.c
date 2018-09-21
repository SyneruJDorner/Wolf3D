/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:17:38 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/01 12:38:54 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t n)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	counter;

	src_len = ft_strlen(source);
	dst_len = ft_strlen(destination);
	counter = 0;
	if (n < dst_len || (int)src_len < 0 || (int)dst_len < 0)
		return (src_len + n);
	while (source[counter] != '\0' && counter < (n - dst_len) - 1)
	{
		destination[dst_len + counter] = source[counter];
		counter++;
	}
	destination[dst_len + counter] = '\0';
	return (dst_len + src_len);
}
