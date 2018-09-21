/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 08:45:37 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/04 10:37:56 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *sentence, const char *pattern, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (pattern[k] != '\0')
		k++;
	if (k == 0)
		return (char*)(sentence);
	while (sentence[i] != '\0')
	{
		k = 0;
		while (sentence[i + k] == pattern[k] && pattern[k] != '\0')
			k++;
		if (pattern[k] == '\0')
		{
			if (i + k > n)
				break ;
			return (char*)(sentence + i);
		}
		i++;
	}
	return (NULL);
}
