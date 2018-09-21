/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:13:03 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/01 13:11:02 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	illegalchar(char s)
{
	return (s == ' ' || s == '\n' || s == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;
	char	*str;

	start = 0;
	if (s == NULL)
		return (NULL);
	while (illegalchar(s[start]))
		start++;
	len = ft_strlen(s);
	while (illegalchar(s[len - 1]) && s[start] != '\0')
		len--;
	str = ft_strsub(s, start, len - start);
	if (str)
		return (str);
	return (0);
}
