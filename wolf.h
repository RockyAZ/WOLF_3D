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

# include "./libft/libft.h"
# include <GLFW/glfw3.h>
# include <fcntl.h>
#include <stdio.h>
typedef struct  s_data
{
	char		*name;
	int         **map;
	int         col;
	int         line;
}               t_data;

typedef struct	s_main
{
	t_data		*data;
}				t_main;

/*
** reader.c
*/
void			reader(t_data *data);

/*
** error.c
*/
void			error(char *name);

/*
** additional.c
*/
void			ft_arrr_del(char **arr);

//
void	print_coord(t_data *data);
//
#endif
