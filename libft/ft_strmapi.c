/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 06:58:04 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/01 12:43:14 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len])
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	len = 0;
	while (s[len])
	{
		str[len] = f(len, s[len]);
		len++;
	}
	str[len] = '\0';
	return (str);
}
