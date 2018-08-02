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

int			mouse_pos(GLFWwindow* window, double x, double y)
{
	printf("X::%f, Y::%f\n", x, y);
	return (0);
}

void	f()
{
	int i = 0;
	int j = 0;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3ub(100, 20, 200);
	// while (i < WIDTH)
	// {
	// 	glVertex2d(i, 0);
	// 	glVertex2d(i, HEIGHT);
	// 	i++;
	// }
	while (i < HEIGHT)
	{
		glVertex2d(0, i);
		glVertex2d(WIDTH, i);
		i++;
	}
	glEnd();
}

int	main(int ac, char **av)
{
	GLFWwindow *window;
	t_main *win;

	main_prepare(ac, av, &win);
	reader(win->data);
	if (!glfwInit())
		error("init error\n");
glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!(window = glfwCreateWindow(WIDTH, HEIGHT, "WOLF", NULL, NULL)))
		error("window open error\n");

glfwMakeContextCurrent(window);

glfwSetKeyCallback(window, key_callback);
// glfwSetCursorPosCallback(window, *mouse_pos);
	glfwSwapInterval(1);

	glViewport(0, 0, WIDTH * 2, HEIGHT * 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1, WIDTH, HEIGHT, 1, -1, 0);
	// glOrtho(1, WIDTH, HEIGHT, 1, -1, 1);
	// glOrtho(0, WIDTH, HEIGHT, 0, 0, 1);	
	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();

	glfwSetWindowUserPointer(window, win);
ray_player_prepare(win);
		// ray_casting(win);
	while (!glfwWindowShouldClose(window))
	{
		// f();
		ray_casting(win);
		glfwSwapBuffers(window);
		glfwWaitEvents();
	}
system ("leaks -quiet wolf3d");
    glfwDestroyWindow(window);
	glfwTerminate();
system ("leaks -quiet wolf3d");
	exit(EXIT_SUCCESS);
}
// /usr/local/include/