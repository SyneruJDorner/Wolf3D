/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:48:46 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 13:20:52 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

#define KEY_BEGIN 2
#define KEY_END 3
#define MOUSE_BEGIN 4
#define MOUSE_END 5
#define MOUSE_MOVE 6

#define EXIT 17
#define EXPOSE 12

int		expose_hook(t_mlx *mlx)
{
	ray_casting(mlx);
	return (0);
}

int		exit_hook(void)
{
	exit(1);
	return (0);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, WINWIDTH, WINHEIGHT, "Wolf 3D");
}

void	wolf3d_init(t_mlx *mlx)
{
	mlx->player.position.x = 3;
	mlx->player.position.y = 3;
	mlx->player.player_speed = 0.05;
	mlx->player.move[0] = 0;
	mlx->player.move[1] = 0;
	mlx->player.move[2] = 0;
	mlx->player.move[3] = 0;
	mlx->player.rotation.x = -1;
	mlx->player.rotation.y = 0;
	mlx->player.rotation_speed = 0.01;
	mlx->camera.field_of_view.x = 0;
	mlx->camera.field_of_view.y = 0.66f;
	mlx->skybox.texture_cood.x = 0;
	mlx->skybox.texture_cood.y = 0;
	mlx->read.line_width = 0;
	mlx->read.line_height = 0;
	load_textures(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx *mlx;

	if (argc != 2)
	{
		ft_putstr(USAGE);
		return (0);
	}
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (0);
	init_mlx(mlx);
	wolf3d_init(mlx);
	if (readmap(argc, argv, mlx) == -1)
		return (0);
	mlx_hook(mlx->window, EXIT, 0, &exit_hook, mlx);
	mlx_hook(mlx->window, EXPOSE, 0, &expose_hook, mlx);
	mlx_hook(mlx->window, KEY_BEGIN, 0, key_begin, mlx);
	mlx_hook(mlx->window, KEY_END, 0, key_end, mlx);
	mlx_hook(mlx->window, MOUSE_MOVE, 0, mouse_move, mlx);
	mlx_loop_hook(mlx->mlx, update, mlx);
	ray_casting(mlx);
	mlx_loop(mlx->mlx);
}
