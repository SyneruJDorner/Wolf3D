/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:50:06 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 13:46:27 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		cleansplit(char ***split)
{
	char		**str;
	int			i;

	i = 0;
	str = *split;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*split)[i];
	}
	ft_memdel((void **)split);
	return (0);
}

t_list	*readfile(int argc, char **argv, t_list *readcontents)
{
	int		fd;
	char	*line;

	readcontents = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			line = NULL;
			while ((get_next_line(fd, &line)) > 0)
			{
				ft_strcat(line, "\n");
				ft_lstadd(&readcontents, ft_lstnew(line, ft_strlen(line) + 1));
				ft_strdel(&line);
			}
		}
	}
	if (readcontents != NULL)
		close(fd);
	return (readcontents);
}

int		legalfilewidth(char *str)
{
	char	**split;
	int		i;
	int		legalcount;

	split = ft_strsplit(str, ' ');
	i = 0;
	legalcount = 0;
	while (split[i])
	{
		i++;
		legalcount++;
	}
	cleansplit(&split);
	return (legalcount);
}

void	fill_map(t_mlx *mlx, t_list *readcontents)
{
	int		x;
	int		y;
	char	**split;

	y = -1;
	if (!(mlx->map = malloc(sizeof(int) *
					mlx->read.line_width * mlx->read.line_height)))
		return ;
	while (++y < mlx->read.line_height)
	{
		x = -1;
		if (!(mlx->map[y] = malloc(sizeof(int) * mlx->read.line_width)))
			return ;
		if ((split = ft_strsplit(readcontents->content, ' ')) == NULL)
			return ;
		while (++x < mlx->read.line_width)
			mlx->map[y][x] = ft_atoi(split[x]);
		cleansplit(&split);
		if (readcontents->next != NULL)
			readcontents = readcontents->next;
	}
}

int		readmap(int argc, char **argv, t_mlx *mlx)
{
	t_list	*readcontents;

	readcontents = NULL;
	if (!(readcontents = readfile(argc, argv, readcontents)))
		return (-1);
	ft_lstrev(&readcontents);
	mlx->read.line_width = legalfilewidth(readcontents->content);
	mlx->read.line_height = ft_lstcount(readcontents);
	fill_map(mlx, readcontents);
	ft_lstfree(readcontents);
	return (0);
}
