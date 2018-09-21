/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdorner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:36:48 by jdorner           #+#    #+#             */
/*   Updated: 2018/09/07 13:47:00 by jdorner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define WINWIDTH 1024
# define WINHEIGHT 768
# define SKYBOX_RES 128
# define USAGE "usage: wolf3d \"map\"\n"
# define TRUE (1 == 1)
# define FALSE (!TRUE)

typedef enum			e_keycode
{
	A = 0,
	B = 11,
	C = 8,
	D = 2,
	E = 14,
	F = 3,
	G = 5,
	H = 4,
	I = 34,
	J = 38,
	K = 40,
	L = 37,
	M = 46,
	N = 45,
	O = 31,
	P = 35,
	Q = 12,
	R = 15,
	S = 1,
	T = 17,
	U = 32,
	V = 9,
	W = 13,
	X = 7,
	Y = 16,
	Z = 6,
	ALPHA1 = 18,
	ALPHA2 = 19,
	ALPHA3 = 20,
	ALPHA4 = 21,
	ALPHA5 = 23,
	ALPHA6 = 22,
	ALPHA7 = 26,
	ALPHA8 = 28,
	ALPHA9 = 25,
	ALPHA0 = 29,
	KEYPAD1 = 83,
	KEYPAD2 = 84,
	KEYPAD3 = 85,
	KEYPAD4 = 86,
	KEYPAD5 = 87,
	KEYPAD6 = 88,
	KEYPAD7 = 89,
	KEYPAD8 = 91,
	KEYPAD9 = 92,
	KEYPAD0 = 82,
	KEYPADPERIOD = 65,
	KEYPADMULTIPLY = 67,
	KEYPADMINUS = 78,
	KEYPADPLUS = 69,
	KEYPADDIVIDE = 75,
	KEYPADENTER = 76,
	KEYPADEQUALS = 81,
	LEFTARROW = 123,
	UPARROW = 126,
	DOWNARROW = 125,
	RIGHTARROW = 124,
	NUMLOCK = 71,
	CAPSLOCK = 272,
	ESCAPE = 53,
	RIGHTSHIFT = 258,
	LEFTSHIFT = 257,
	RIGHTALT = 262,
	LEFTALT = 261,
	RIGHTCTRL = 269,
	LEFTCTRL = 256,
	RIGHTCMD = 260,
	LEFTCMD = 259,
	TAB = 48,
	CALL = 10,
	SPACE = 49,
	ENTER = 36,
	BACKSPACE = 51,
	EQUALS = 24,
	MINUS = 27,
	LEFTBRACKET = 33,
	RIGHTBRACKET = 30,
	SEMICOLON = 41,
	DOUBLEQUOTES = 39,
	BACKSLASH = 42,
	LESS_THAN = 43,
	GREATER_THAN = 47,
	QUESTION = 44,
	DELETE = 117,
	PAGEUP = 116,
	PAGEDOWN = 121,
	PAGETOP = 115,
	PAGEBOTTOM = 119,
	FN = 279,
}						t_keycode;

typedef struct			s_vector3
{
	double				x;
	double				y;
	double				z;
}						t_vector3;

typedef struct			s_mouse
{
	t_vector3			position;
	t_vector3			lastposition;
	int					ismoving;
	int					isleftdown;
	int					isrightdown;
	int					isleftdragging;
	int					isrightdragging;
	int					scrolldirection;
}						t_mouse;

typedef struct			s_keyboard
{
	int					keycode;
	int					pressedkeys[100];
	int					lastkeycode;
	int					extendedinputkey;
	int					assignedkey;
}						t_keyboard;

typedef struct			s_input
{
	t_keyboard			keyboard;
	t_mouse				mouse;
}						t_input;

typedef struct			s_readinfo
{
	int					line_height;
	int					line_width;
}						t_readinfo;

typedef struct			s_image
{
	void				*img;
	char				*data;
	int					bpp;
	int					sizeline;
	int					endian;
}						t_image;

typedef struct			s_player
{
	int					move[6];
	double				player_speed;
	double				rotation_speed;
	t_vector3			position;
	t_vector3			old_position;
	t_vector3			rotation;
	t_vector3			old_rotation;
}						t_player;

typedef struct			s_draw
{
	int					lineheight;
	double				wall_at_ray_pos;
}						t_draw;

typedef struct			s_skybox
{
	t_vector3			texture_cood;
}						t_skybox;

typedef struct			s_raycast
{
	t_vector3			raycast_map;
	int					start;
	int					end;
	int					texture_hit_id;
	t_vector3			deltadist;
	t_vector3			raydir;
	t_vector3			steps;
	t_vector3			sidedist;
	t_vector3			raypos;
	int					side;
	int					hit;
	double				walldistance;
}						t_raycast;

typedef struct			s_camera
{
	t_vector3			field_of_view;
	t_vector3			old_field_of_view;
}						t_camera;

typedef struct			s_mlx
{
	void				*mlx;
	void				*window;
	char				*map_name;
	int					**map;
	t_readinfo			read;
	t_image				texture_array[9];
	t_input				input;
	t_camera			camera;
	t_player			player;
	t_raycast			raycast;
	t_skybox			skybox;
	t_draw				draw;
	t_image				render_image;
}						t_mlx;

int						readmap(int argc, char **argv, t_mlx *mlx);
int						update(t_mlx *mlx);
void					control_player(t_mlx *mlx);
void					keyboardinputs(t_mlx *mlx, int key, int key_state);
void					mouse_scroll(int button, int x, int y, t_mlx *mlx);
int						mouse_begin(int button, t_mlx *mlx);
int						mouse_move(int x, int y, t_mlx *mlx);
int						mouse_end(int button, t_mlx *mlx);
int						key_begin(int key, t_mlx *mlx);
int						key_end(int key, t_mlx *mlx);
void					draw_sky(t_mlx *t);
void					draw_ground(t_mlx *t, int x, int ground_colour);
void					draw_wall(int x, int start, int end, t_mlx *t);
void					put_pxl_to_img(t_mlx *t, int x, int y);
void					load_textures(t_mlx *t);
void					load_textures2(t_mlx *t, int a, int b);
int						parser(t_mlx *t, char **av);
void					ray_casting(t_mlx *t);
#endif
