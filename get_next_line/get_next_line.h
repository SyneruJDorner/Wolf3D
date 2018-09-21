/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:10:05 by jdorner           #+#    #+#             */
/*   Updated: 2018/07/25 13:04:00 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define TRUE (1 == 1)
# define FALSE (!TRUE)
# define BUFF_SIZE 8

int	get_next_line(const int fd, char **line);
#endif
