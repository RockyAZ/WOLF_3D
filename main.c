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

	main_prepare(ac, av, &win);
	reader(win->data);
	if (!glfwInit())
		error("init error\n");
	if (!(window = glfwCreateWindow(WIDTH, HEIGHT, "WOLF", NULL, NULL)))
		error("window open error\n");
		glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSwapInterval(1);
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, WIDTH, HEIGHT, 0.0f, 0.0f, 1.0f);
		ray_player_prepare(win);
	while (!glfwWindowShouldClose(window))
	{
		ray_casting(win);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
system ("leaks -quiet wolf3d");
    glfwDestroyWindow(window);
	glfwTerminate();
system ("leaks -quiet wolf3d");
	exit(EXIT_SUCCESS);
}
// /usr/local/include/