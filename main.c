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

void	f()
{
	int width, height, nrChannels, i;
	unsigned char *data = stbi_load("./WallPack/Flag5.png", &width, &height, &nrChannels, 0);
	printf("W:%d\nH:%d\nChan:%d\n", width, height, nrChannels);
	// for(int i = 0; i < 64 * 3; i += 3)
	i = 0;
		printf("R:%d  G:%d  B:%d\n", (int)data[i], (int)data[i + 1], (int)data[i + 2]);
	i = 64 * 3;
		printf("R:%d  G:%d  B:%d\n", (int)data[i], (int)data[i + 1], (int)data[i + 2]);
	free(data);
}

int	main(int ac, char **av)
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
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, *mouse_pos);
	glfwSwapInterval(1);

	glViewport(0, 0, WIDTH * 2, HEIGHT * 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(1, WIDTH, HEIGHT, 1, -1, 0);
	// glMatrixMode(GL_MODELVIEW);
	glfwSetWindowUserPointer(window, win);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// char *ver = glGetString(GL_VERSION);
	// printf("%s\n", ver);
	texture_prepare(win);
	ray_player_prepare(win);
	ray_casting(win);
	// f();
	while (!glfwWindowShouldClose(window))
	{
		active_keys(win);
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
//convert stb_image to static library???