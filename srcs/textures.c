/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:36:11 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 10:41:34 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_texture(t_mlx *mlx, char *path, int size_sqrd)
{
	static int	i = 0;

	mlx->texture_array[i].img =
	mlx_xpm_file_to_image(mlx->mlx, path, &size_sqrd, &size_sqrd);
	mlx->texture_array[i].data = mlx_get_data_addr(mlx->texture_array[i].img,
			&mlx->texture_array[i].bpp,
			&mlx->texture_array[i].sizeline,
			&mlx->texture_array[i].endian);
	i++;
}

void	load_textures(t_mlx *mlx)
{
	int	texture_size_sqrd;
	int	skybox_texture_size;

	texture_size_sqrd = 64;
	skybox_texture_size = SKYBOX_RES;
	load_texture(mlx, "textures/wood.xpm", texture_size_sqrd);
	load_texture(mlx, "textures/stone.xpm", texture_size_sqrd);
	load_texture(mlx, "textures/mossy.xpm", texture_size_sqrd);
	load_texture(mlx, "textures/redbrick.xpm", texture_size_sqrd);
	load_texture(mlx, "textures/wood.xpm", texture_size_sqrd);
	load_texture(mlx, "textures/sand.xpm", texture_size_sqrd);
	load_texture(mlx, "textures/sky.xpm", skybox_texture_size);
}
