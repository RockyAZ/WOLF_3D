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

void	add_main(GLFWwindow *window, t_main *win)
{
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, *mouse_pos);
	glfwSwapInterval(1);
	glViewport(0, 0, WIDTH * 2, HEIGHT * 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1, WIDTH, HEIGHT, 1, 1, 0);
	glfwSetWindowUserPointer(window, win);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

int		main(int ac, char **av)
{
	GLFWwindow	*window;
	t_main		*win;

	main_prepare(ac, av, &win);
	reader(win->data);
	if (!glfwInit())
		error("init error\n");
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!(window = glfwCreateWindow(WIDTH, HEIGHT, "WOLF", NULL, NULL)))
		error("window open error\n");
	add_main(window, win);
	texture_prepare(win);
	ray_player_prepare(win);
	ray_casting(win);
	while (!glfwWindowShouldClose(window))
	{
		active_keys(win);
		ray_casting(win);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
