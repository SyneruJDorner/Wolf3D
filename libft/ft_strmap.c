/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:43:27 by jdorner           #+#    #+#             */
/*   Updated: 2018/06/01 12:41:48 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		str[len] = f(s[len]);
		len++;
	}
	str[len] = '\0';
	return (str);
}
