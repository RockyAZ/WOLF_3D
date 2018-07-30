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

# define WIDTH 320
# define HEIGHT 200
# define FOV 60

# include "./libft/libft.h"
# include <GLFW/glfw3.h>
# include <fcntl.h>
# include <math.h>
#include <stdio.h>
typedef struct	s_ray
{
	float		posX;
	float		posY;
	float		angl;
	float		to_screen;
	float		centrX;
	float		centrY;
	float		new_time;
	float		old_time;
}				t_ray;

typedef struct  s_data
{
	char		*name;
	int         **map;
	int         col;
	int         line;
	int			error;
	int			fd;
	int			pos[2];
}               t_data;

typedef struct	s_main
{
	t_data		*data;
	t_ray		ray;
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

/*
** preparation.c
*/
void			main_prepare(int ac, char **av, t_main **win);
void			ray_casting_prepare(t_main *win);

//
void print_coord(t_data *data);
//
#endif
