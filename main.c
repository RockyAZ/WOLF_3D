/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:30:39 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/23 17:30:40 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int ac, char **av)
{
	GLFWwindow *window;
	t_main *win;

	if (!(win = (t_main*)malloc(sizeof(t_main))))
		error("main malloc error\n");
	win->data = (t_data*)malloc(sizeof(t_data));
	if (ac != 2)
		error("number of arguments error\n");
	win->data->name = av[1];
	reader(win->data);
	return (0);
}
// /usr/local/include/