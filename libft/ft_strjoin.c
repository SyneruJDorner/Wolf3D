/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 07:25:23 by jdorner           #+#    #+#             */
/*   Updated: 2018/07/24 13:35:37 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	totallen;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	totallen = ft_strlen(s1) + ft_strlen(s2);
	if ((str = malloc(sizeof(char) * totallen + 1)) == NULL)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	size_t	totallen;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	totallen = ft_strlen(s1) + ft_strlen(s2);
	if ((str = malloc(sizeof(char) * totallen + 1)) == NULL)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
