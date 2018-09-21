/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:28:40 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/01 13:07:24 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *sentence, const char *pattern)
{
	char	*src;
	char	*find;
	int		size;

	src = (char *)sentence;
	find = (char *)pattern;
	size = ft_strlen(find);
	if (size == 0)
		return (src);
	while (*src)
	{
		if (ft_strncmp(src, find, size) == 0)
			return (src);
		src++;
	}
	return ((char *)NULL);
}
