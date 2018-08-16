/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:36:29 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/23 17:37:35 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define WIDTH 640
# define HEIGHT 400
# define CENTR_W WIDTH / 1
# define CENTR_H HEIGHT / 2
# define CUBE 64
# define BIT 6
# define FACE 10
# define TEXTURES 10
# define PLAYERHEIGHT 32
# define MAX_COL 50
# define MAX_LINE 20

# include "./libft/libft.h"
# include "./include/GLFW/glfw3.h"
# include <fcntl.h>
# include <math.h>
# include "./include/stb_image.h"

typedef struct		s_keys
{
	int				right;
	int				left;
	int				up;
	int				down;
	int				w;
	int				s;
	int				a;
	int				d;
	int				shift;
	int				space;
}					t_keys;

typedef struct		s_mouse
{
	int				x;
	int				y;
}					t_mouse;

typedef struct		s_img
{
	unsigned char	*tex[TEXTURES];
	int				width;
	int				height;
	int				nr_channel;
	int				pos;
}					t_img;

typedef struct		s_dot
{
	float			pix_x;
	float			pix_y;
	int				real_x;
	int				real_y;
	float			var_x;
	float			var_y;
}					t_dot;

typedef struct		s_player
{
	float			p_x;
	float			p_y;
	int				r_x;
	int				r_y;
	int				height;
	float			angle;
	float			angle_size;
	float			fov;
	float			to_screen;
	int				speed;
}					t_player;

typedef struct		s_ray
{
	t_dot			h_dot;
	t_dot			v_dot;
	int				horiz_int;
	int				vertic_int;
	float			angle;
}					t_ray;

typedef struct		s_data
{
	char			*name;
	int				**map;
	int				col;
	int				line;
	int				m_x;
	int				m_y;
	int				error;
	int				fd;
	float			pos[2];
}					t_data;

typedef struct		s_main
{
	t_data			*data;
	t_ray			ray;
	t_player		gg;
	t_keys			keys;
	t_img			img;
	t_mouse			m;
	int				v_is;
	int				h_is;
	float			rotate;
}					t_main;

/*
** reader.c
*/
void				reader(t_data *data);

/*
** ray_casting.h
*/
void				ray_casting(t_main *win);
int					vertic_inter_left(t_main *win, float angle);
int					vertic_inter_right(t_main *win, float angle);
int					horiz_inter_top(t_main *win, float angle);
int					horiz_inter_bot(t_main *win, float angle);

/*
** keys.c
*/
void				key_callback(GLFWwindow *window, int key,\
					int scan, int act, int mods);

/*
** mouse.c
*/
void				mouse_pos(GLFWwindow *window, double x, double y);

/*
** error.c
*/
void				error(char *name);

/*
** additional.c && ray_simple.c
*/
void				ft_arrr_del(char **arr, char *line);
float				ft_tan(float angle);
float				ft_sin(float angle);
float				ft_cos(float angle);
int					pifagor(t_main *win, float angle, char c);
void				ray_simple(t_main *win, float angle, int v, int h);

/*
** action.c
*/
void				active_keys(t_main *win);

/*
** preparation.c
*/
void				main_prepare(int ac, char **av, t_main **win);
void				ray_player_prepare(t_main *win);
void				texture_prepare(t_main *win);

/*
** draw_line.c
*/
void				line_draw(t_main *win, int i, float h, int tex);
#endif
