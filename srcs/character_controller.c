/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:53:07 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 10:32:22 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <ApplicationServices/ApplicationServices.h>

void	rotate_player_right(t_mlx *mlx)
{
	int i;

	i = 0;
	while (++i < 5)
	{
		if (mlx->player.move[2] == 1)
		{
			mlx->player.rotation.x =
			mlx->player.rotation.x * cos(-mlx->player.rotation_speed) -
			mlx->player.rotation.y * sin(-mlx->player.rotation_speed);
			mlx->player.rotation.y =
			mlx->player.old_rotation.x * sin(-mlx->player.rotation_speed) +
			mlx->player.rotation.y * cos(-mlx->player.rotation_speed);
			mlx->camera.old_field_of_view.x =
			mlx->camera.field_of_view.x;
			mlx->camera.field_of_view.x =
			mlx->camera.field_of_view.x * cos(-mlx->player.rotation_speed) -
			mlx->camera.field_of_view.y * sin(-mlx->player.rotation_speed);
			mlx->camera.field_of_view.y =
			mlx->camera.old_field_of_view.x * sin(-mlx->player.rotation_speed) +
			mlx->camera.field_of_view.y * cos(-mlx->player.rotation_speed);
		}
	}
	mlx->player.old_rotation.x = mlx->player.rotation.x;
}

void	rotate_player_left(t_mlx *mlx)
{
	int i;

	i = 0;
	while (++i < 5)
	{
		if (mlx->player.move[3] == 1)
		{
			mlx->player.rotation.x =
			mlx->player.rotation.x * cos(mlx->player.rotation_speed) -
			mlx->player.rotation.y * sin(mlx->player.rotation_speed);
			mlx->player.rotation.y =
			mlx->player.old_rotation.x * sin(mlx->player.rotation_speed) +
			mlx->player.rotation.y * cos(mlx->player.rotation_speed);
			mlx->camera.old_field_of_view.x =
			mlx->camera.field_of_view.x;
			mlx->camera.field_of_view.x =
			mlx->camera.field_of_view.x * cos(mlx->player.rotation_speed) -
			mlx->camera.field_of_view.y * sin(mlx->player.rotation_speed);
			mlx->camera.field_of_view.y =
			mlx->camera.old_field_of_view.x * sin(mlx->player.rotation_speed) +
			mlx->camera.field_of_view.y * cos(mlx->player.rotation_speed);
		}
	}
	mlx->player.old_rotation.x = mlx->player.rotation.x;
}

void	move_player(t_mlx *mlx)
{
	if (mlx->player.move[0] == 1)
	{
		if (mlx->map[(int)(mlx->player.position.x + mlx->player.rotation.x *
			mlx->player.player_speed)][(int)(mlx->player.position.y)] == 0)
			mlx->player.position.x +=
			mlx->player.rotation.x * mlx->player.player_speed;
		if (mlx->map[(int)(mlx->player.position.x)]
			[(int)(mlx->player.position.y + mlx->player.rotation.y *
			mlx->player.player_speed)] == 0)
			mlx->player.position.y += mlx->player.rotation.y *
			mlx->player.player_speed;
	}
	if (mlx->player.move[1] == 1)
	{
		if (mlx->map[(int)(mlx->player.position.x - mlx->player.rotation.x *
			mlx->player.player_speed)][(int)(mlx->player.position.y)] == 0)
			mlx->player.position.x -=
			mlx->player.rotation.x * mlx->player.player_speed;
		if (mlx->map[(int)(mlx->player.position.x)]
			[(int)(mlx->player.position.y - mlx->player.rotation.y *
			mlx->player.player_speed)] == 0)
			mlx->player.position.y -= mlx->player.rotation.y *
			mlx->player.player_speed;
	}
}

void	strafe_player(t_mlx *mlx)
{
	if (mlx->player.move[4] == 1)
	{
		if (mlx->map[(int)(mlx->player.position.x + mlx->player.rotation.x *
			mlx->player.player_speed)][(int)(mlx->player.position.y)] == 0)
			mlx->player.position.y += mlx->player.rotation.x *
			mlx->player.player_speed;
		if (mlx->map[(int)(mlx->player.position.x)]
			[(int)(mlx->player.position.y - mlx->player.rotation.y *
			mlx->player.player_speed)] == 0)
			mlx->player.position.x -=
			mlx->player.rotation.y * mlx->player.player_speed;
	}
	if (mlx->player.move[5] == 1)
	{
		if (mlx->map[(int)(mlx->player.position.x + mlx->player.rotation.x *
			mlx->player.player_speed)][(int)(mlx->player.position.y)] == 0)
			mlx->player.position.y -=
			mlx->player.rotation.x * mlx->player.player_speed;
		if (mlx->map[(int)(mlx->player.position.x)]
			[(int)(mlx->player.position.y - mlx->player.rotation.y *
			mlx->player.player_speed)] == 0)
			mlx->player.position.x += mlx->player.rotation.y *
			mlx->player.player_speed;
	}
}

void	control_player(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	move_player(mlx);
	strafe_player(mlx);
	rotate_player_right(mlx);
	rotate_player_left(mlx);
	ray_casting(mlx);
}
