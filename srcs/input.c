/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:37:16 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 13:33:08 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <ApplicationServices/ApplicationServices.h>

#define LEFT_CLICK 1
#define RIGHT_CLICK 2
#define SCROLLDOWN 4
#define SCROLLUP 5
#define SCROLLRIGHT 6
#define SCROLLLEFT 7
#define MOUSE_BEGIN 4
#define MOUSE_END 5
#define MOUSE_MOVE 6

int		set_mouse_x_position(CGPoint point)
{
	int	x;

	x = 0;
	if ((int)point.x > 1920 / 2)
		x = -1;
	else if ((int)point.x < 1920 / 2)
		x = 1;
	else
		x = 0;
	return (x);
}

int		set_mouse_y_position(CGPoint point)
{
	int	y;

	y = 0;
	if ((int)point.y > 1080 / 2)
		y = -1;
	else if ((int)point.y < 1080 / 2)
		y = 1;
	else
		y = 0;
	return (y);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	CGEventRef	mousereset;
	CGEventRef	mouseevent;
	CGPoint		point;
	static int	skip = 5;

	mousereset = NULL;
	mouseevent = CGEventCreate(NULL);
	point = CGEventGetLocation(mouseevent);
	if (skip >= 5)
	{
		mousereset = CGEventCreateMouseEvent(NULL, kCGEventMouseMoved,
		CGPointMake(1920 / 2, 1080 / 2), kCGMouseButtonLeft);
		CGEventPost(kCGHIDEventTap, mousereset);
		skip = 0;
		CFRelease(mousereset);
	}
	x = set_mouse_x_position(point);
	y = set_mouse_y_position(point);
	mlx->input.mouse.position.x = x;
	mlx->input.mouse.position.y = y;
	CFRelease(mouseevent);
	skip++;
	return (1);
}

int		key_begin(int key, t_mlx *mlx)
{
	keyboardinputs(mlx, key, 1);
	return (0);
}

int		key_end(int key, t_mlx *mlx)
{
	keyboardinputs(mlx, key, 0);
	return (0);
}
