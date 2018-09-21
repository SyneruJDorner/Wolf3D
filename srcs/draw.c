/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:41:50 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 10:45:46 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_pxl_to_img(t_mlx *t, int x, int y)
{
	if (x < WINWIDTH && y < WINHEIGHT)
	{
		t->skybox.texture_cood.y =
		abs((((y * 256 - WINHEIGHT * 128 + t->draw.lineheight * 128) * 64)
		/ t->draw.lineheight) / 256);
		ft_memcpy(t->render_image.data + 4 * WINWIDTH * y + x * 4,
		&t->texture_array[t->raycast.texture_hit_id].data[
		(int)t->skybox.texture_cood.y % 64 *
		t->texture_array[t->raycast.texture_hit_id].sizeline +
		(int)t->skybox.texture_cood.x % 64 *
		t->texture_array[t->raycast.texture_hit_id].bpp / 8], sizeof(int));
	}
}

void	draw_wall(int x, int start, int end, t_mlx *t)
{
	t->raycast.texture_hit_id =
	t->map[(int)t->raycast.raycast_map.x][(int)t->raycast.raycast_map.y];
	if (t->raycast.side == 0)
		t->draw.wall_at_ray_pos = t->raycast.raypos.y +
		t->raycast.walldistance * t->raycast.raydir.y;
	else
		t->draw.wall_at_ray_pos =
		t->raycast.raypos.x + t->raycast.walldistance * t->raycast.raydir.x;
	t->skybox.texture_cood.x = (int)(t->draw.wall_at_ray_pos * (double)(64));
	if (t->raycast.side == 0 && t->raycast.raydir.x > 0)
		t->skybox.texture_cood.x = 64 - t->skybox.texture_cood.x - 1;
	if (t->raycast.side == 1 && t->raycast.raydir.y < 0)
		t->skybox.texture_cood.x = 64 - t->skybox.texture_cood.x - 1;
	t->skybox.texture_cood.x = fabs(t->skybox.texture_cood.x);
	while (++start <= end)
		put_pxl_to_img(t, x, start);
}

void	draw_sky(t_mlx *t)
{
	int	texture_cood_x;
	int	texture_cood_y;

	texture_cood_x = 0;
	while (texture_cood_x < WINWIDTH)
	{
		texture_cood_y = 0;
		while (texture_cood_y < WINHEIGHT)
		{
			ft_memcpy(t->render_image.data + 4 * WINWIDTH * texture_cood_y +
			texture_cood_x * 4,
			&t->texture_array[6].data[texture_cood_y % (SKYBOX_RES / 20) *
			t->texture_array[6].sizeline +
			texture_cood_x % (SKYBOX_RES / 20) * t->texture_array[6].bpp / 8],
			sizeof(int));
			texture_cood_y++;
		}
		texture_cood_x++;
	}
	t->skybox.texture_cood.x = texture_cood_x;
	t->skybox.texture_cood.y = texture_cood_y;
}

void	draw_ground(t_mlx *t, int x, int ground_colour)
{
	int	y;

	if (t->raycast.end > 0)
	{
		y = t->raycast.end - 1;
		if (x < WINWIDTH && y < WINHEIGHT)
			while (++y < WINHEIGHT)
				ft_memcpy(t->render_image.data + 4 * WINWIDTH * y + x * 4,
				&ground_colour, sizeof(int));
	}
}
