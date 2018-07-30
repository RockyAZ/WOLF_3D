/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:06:16 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/30 13:06:16 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	main_prepare(int ac, char **av, t_main **win)
{
	t_main *cp_win;

	if (ac != 2)
		error("number of arguments error\n");
	if (!(cp_win = (t_main*)malloc(sizeof(t_main))))
		error("main malloc error\n");
	cp_win->data = (t_data*)malloc(sizeof(t_data));
	cp_win->data->name = av[1];
	*win = cp_win;
}

void	ray_casting_prepare(t_main *win)
{
	win->ray.posX = win->data->pos[0];
	win->ray.posX = win->data->pos[1];
	win->ray.angl = 45;
	win->ray.to_screen = WIDTH / tan(30);
	win->ray.centrX = WIDTH / 2;
	win->ray.centrY = HEIGHT / 2;
	win->ray.new_time = 0;
	win->ray.old_time = 0;
}
