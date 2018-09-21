/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:31:43 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 13:17:46 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <ApplicationServices/ApplicationServices.h>

#define BLACK 0x000000
#define RED 0xFF0000
#define BLUE 0x0000FF
#define WHITE 0xFFFFFF
#define SILVER 0xC0C0C0
#define GRAY 0x808080
#define MAROON 0x800000
#define YELLOW 0xFFFF00
#define OLIVE 0x808000
#define LIME 0x00FF00
#define GREEN 0x008000
#define AQUA 0x00FFFF
#define TEAL 0x008080
#define NAVY 0x000080
#define FUCHSIA 0xFF00FF
#define PURPLE 0x800080

#define KEYRELEASED 0
#define KEYPRESSED 1

void	gui(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->window, 5, 0, WHITE, "MOUSE");
}

void	keyboardinputs(t_mlx *mlx, int key, int key_state)
{
	if (key == W || key == UPARROW)
		mlx->player.move[0] = key_state;
	else if (key == S || key == DOWNARROW)
		mlx->player.move[1] = key_state;
	else if (key == A || key == LEFTARROW)
		mlx->player.move[4] = key_state;
	else if (key == D || key == RIGHTARROW)
		mlx->player.move[5] = key_state;
	if (key == LEFTSHIFT || key == RIGHTSHIFT)
	{
		if (key_state == KEYRELEASED)
			mlx->player.player_speed = 0.05f;
		else if (key_state == KEYPRESSED)
			mlx->player.player_speed = 0.15f;
	}
	if (key == ESCAPE)
		exit(1);
}

void	mouseinputs(t_mlx *mlx)
{
	if (mlx->input.mouse.position.x > 0)
	{
		mlx->player.move[2] = 1;
		mlx->player.move[3] = 0;
	}
	else if (mlx->input.mouse.position.x < 0)
	{
		mlx->player.move[2] = 0;
		mlx->player.move[3] = 1;
	}
	else if (mlx->input.mouse.position.x == 0)
	{
		mlx->player.move[2] = 0;
		mlx->player.move[3] = 0;
	}
	mlx->input.mouse.position.x = 0;
}

int		update(t_mlx *mlx)
{
	mouseinputs(mlx);
	control_player(mlx);
	gui(mlx);
	return (0);
}
