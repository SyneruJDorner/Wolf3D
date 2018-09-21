/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:01:09 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 13:15:35 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	assign_dda(t_mlx *mlx)
{
	if (mlx->raycast.raydir.x < 0)
	{
		mlx->raycast.steps.x = -1;
		mlx->raycast.sidedist.x = (mlx->raycast.raypos.x -
		mlx->raycast.raycast_map.x) * mlx->raycast.deltadist.x;
	}
	else
	{
		mlx->raycast.steps.x = 1;
		mlx->raycast.sidedist.x = (mlx->raycast.raycast_map.x + 1.0 -
		mlx->raycast.raypos.x) * mlx->raycast.deltadist.x;
	}
	if (mlx->raycast.raydir.y < 0)
	{
		mlx->raycast.steps.y = -1;
		mlx->raycast.sidedist.y = (mlx->raycast.raypos.y -
		mlx->raycast.raycast_map.y) * mlx->raycast.deltadist.y;
	}
	else
	{
		mlx->raycast.steps.y = 1;
		mlx->raycast.sidedist.y = (mlx->raycast.raycast_map.y + 1.0 -
		mlx->raycast.raypos.y) * mlx->raycast.deltadist.y;
	}
}

void	dda_init(t_mlx *mlx)
{
	mlx->raycast.deltadist.x = sqrt(1 + pow(mlx->raycast.raydir.y /
	mlx->raycast.raydir.x, 2));
	mlx->raycast.deltadist.y = sqrt(1 + pow(mlx->raycast.raydir.x /
	mlx->raycast.raydir.y, 2));
	assign_dda(mlx);
}

void	dda(t_mlx *mlx)
{
	mlx->raycast.hit = 0;
	while (mlx->raycast.hit == 0)
	{
		if (mlx->raycast.sidedist.x < mlx->raycast.sidedist.y)
		{
			mlx->raycast.sidedist.x += mlx->raycast.deltadist.x;
			mlx->raycast.raycast_map.x += mlx->raycast.steps.x;
			mlx->raycast.side = 0;
		}
		else
		{
			mlx->raycast.sidedist.y += mlx->raycast.deltadist.y;
			mlx->raycast.raycast_map.y += mlx->raycast.steps.y;
			mlx->raycast.side = 1;
		}
		if (mlx->map[(int)mlx->raycast.raycast_map.x]
			[(int)mlx->raycast.raycast_map.y] > 0)
			mlx->raycast.hit = 1;
	}
}

void	ray_casting_init(t_mlx *mlx, int x)
{
	double current_rotation_x;

	current_rotation_x = 2 * x / (double)(WINWIDTH) - 1;
	mlx->raycast.raypos.x = mlx->player.position.x;
	mlx->raycast.raypos.y = mlx->player.position.y;
	mlx->raycast.raydir.x =
	mlx->player.rotation.x + mlx->camera.field_of_view.x * current_rotation_x;
	mlx->raycast.raydir.y =
	mlx->player.rotation.y + mlx->camera.field_of_view.y * current_rotation_x;
	mlx->raycast.raycast_map.x = (int)mlx->raycast.raypos.x;
	mlx->raycast.raycast_map.y = (int)mlx->raycast.raypos.y;
	dda_init(mlx);
	dda(mlx);
	if (mlx->raycast.side == 0)
		mlx->raycast.walldistance = (mlx->raycast.raycast_map.x -
		mlx->raycast.raypos.x + (1 - mlx->raycast.steps.x) / 2) /
		mlx->raycast.raydir.x;
	else
		mlx->raycast.walldistance = (mlx->raycast.raycast_map.y -
		mlx->raycast.raypos.y + (1 - mlx->raycast.steps.y) / 2) /
		mlx->raycast.raydir.y;
}

void	ray_casting(t_mlx *mlx)
{
	int	x;

	x = -1;
	mlx->render_image.img = mlx_new_image(mlx->mlx, WINWIDTH, WINHEIGHT);
	mlx->render_image.data = mlx_get_data_addr(mlx->render_image.img,
											&mlx->render_image.bpp,
											&mlx->render_image.sizeline,
											&mlx->render_image.endian);
	draw_sky(mlx);
	while (++x < WINWIDTH)
	{
		ray_casting_init(mlx, x);
		mlx->draw.lineheight = (int)(WINHEIGHT / mlx->raycast.walldistance);
		mlx->raycast.start = -mlx->draw.lineheight / 2 + WINHEIGHT / 2;
		if (mlx->raycast.start < 0)
			mlx->raycast.start = 0;
		mlx->raycast.end = mlx->draw.lineheight / 2 + WINHEIGHT / 2;
		if (mlx->raycast.end >= WINHEIGHT)
			mlx->raycast.end = WINHEIGHT - 1;
		draw_ground(mlx, x, 0x593E1A);
		draw_wall(x, mlx->raycast.start - 1, mlx->raycast.end, mlx);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->render_image.img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->render_image.img);
}
