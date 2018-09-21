/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 09:26:47 by jdorner           #+#    #+#             */
/*   Updated: 2018/07/25 12:43:57 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static char	*readtobuf(const int fd, char *buf, int *ret)
{
	char	buffer[BUFF_SIZE + 1];
	char	*store;

	store = buf;
	*ret = read(fd, buffer, BUFF_SIZE);
	buffer[*ret] = '\0';
	if (!(buf = ft_strjoin(store, buffer)))
		return (0);
	ft_strdel(&store);
	store = NULL;
	return (buf);
}

int			cleanbuf(char **buf)
{
	ft_bzero(*buf, ft_strlen(*buf));
	return (-1);
}

int			put_end(char **line, char **buf)
{
	if (!(*line = ft_strdup(*buf)))
		return (cleanbuf(buf));
	cleanbuf(buf);
	return (1);
}

int			cacheline(char **line, char *buf)
{
	char	*str;
	char	*charstr;

	if ((str = ft_strchr(buf, '\n')) != NULL)
	{
		*str = '\0';
		*line = ft_strnew(ft_strlen(buf));
		charstr = *line;
		if (!(*line = ft_strdup(buf)))
			return (cleanbuf(&buf));
		ft_memmove(buf, str + 1, ft_strlen(str + 1) + 1);
		free(charstr);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buf;
	int			ret;

	ret = 1;
	if (buf == NULL)
		buf = ft_strnew(0);
	if (!line || fd < 0)
		return (cleanbuf(&buf));
	while (ret > 0)
	{
		ret = cacheline(line, buf);
		if (ret != 0)
			return (ret);
		if (!(buf = readtobuf(fd, buf, &ret)))
			return (cleanbuf(&buf));
	}
	if (ret == 0 && ft_strlen(buf))
		ret = put_end(&(*line), &buf);
	cleanbuf(&buf);
	return (ret);
}
