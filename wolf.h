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

// # define WIDTH 1200
// # define HEIGHT 1080
# define WIDTH 640
# define HEIGHT 400
# define CENTR_W WIDTH / 2
# define CENTR_H HEIGHT / 2
# define CUBE 64
# define RUN 10

// #ifdef __APPLE__
// #include <GLUT/glut.h>
// #else
// #include <GL/glut.h>
// #endif

# include <GL/glew.h>
# include "./libft/libft.h"
# include <GLFW/glfw3.h>
// # include <GL/eglew.h>
// # include <GL/glxew.h>
// # include <GL/wglew.h>
# include <fcntl.h>
# include <math.h>
#include <stdio.h>

typedef struct	s_keys
{
	int			right;
	int			left;
	int			up;
	int			down;
}				t_keys;

typedef struct	s_dot
{
	float			pix_x;
	float			pix_y;
	int			real_x;
	int			real_y;
	float			var_x;
	float			var_y;
	int			minus;
}				t_dot;

typedef struct	s_player
{
	float		posX;
	float		posY;
	int			r_x;
	int			r_y;	
	float		angle;
	float		angle_size;
	float		fov;
	float		to_screen;
}				t_player;

typedef struct	s_ray
{
	t_dot		h_dot;
	t_dot		v_dot;
	int			horiz_int;
	int			vertic_int;
}				t_ray;

typedef struct  s_data
{
	char		*name;
	int         **map;
	int         col;
	int         line;
	int			max_x;
	int			max_y;
	int			error;
	int			fd;
	float			pos[2];
}               t_data;

typedef struct	s_main
{
	t_data		*data;
	t_ray		ray;
	t_player	gg;
	t_keys		keys;
int huy;
float rotate;
}				t_main;

/*
** reader.c
*/
void			reader(t_data *data);

/*
** ray_casting.h
*/
void			ray_casting(t_main *win);

/*
** keys.c
*/
void			key_callback(GLFWwindow* window, int key, int scan, int act, int mods);

/*
** error.c
*/
void			error(char *name);

/*
** additional.c
*/
void			ft_arrr_del(char **arr, char *line);
float			ft_tan(float angle);
float			ft_sin(float angle);
float			ft_cos(float angle);
float			ft_tan(float angle);

/*
** action.c
*/
void			active_keys(t_main *win);

/*
** preparation.c
*/
void			main_prepare(int ac, char **av, t_main **win);
void			ray_player_prepare(t_main *win);

/*
** draw_line.c
*/
void			line_draw(t_main *win, int i, float h, int color);

//
void print_coord(t_data *data);
//
#endif
