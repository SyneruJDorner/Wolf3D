/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:01:03 by jdorner           #+#    #+#             */
/*   Updated: 2018/07/24 13:45:24 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlennbr(int n)
{
	int				i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	long			tmp;
	char			*str;
	char			*tmpstr;
	unsigned int	len;

	tmp = (long)n;
	len = ft_strlennbr(tmp) + (n < 0);
	if (n < 0)
		tmp = (tmp * -1);
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	tmpstr = str;
	while (len > 0)
	{
		tmpstr[len - 1] = (tmp % 10) + '0';
		len--;
		tmp = tmp / 10;
	}
	if (n < 0)
		tmpstr[0] = '-';
	free(tmpstr);
	return (str);
}
