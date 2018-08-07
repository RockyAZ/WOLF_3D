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
	int width, height, nrChannels;
	unsigned char *data = stbi_load("./WallPack/Blue.bmp", &width, &height, &nrChannels, 0);
	GLuint texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
// 	unsigned int pid = SOIL_load_OGL_texture("./tex/wood.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS |
	printf("W:%d\nH:%d\nChan:%d\n", width, height, nrChannels);
	free(data);
}

int	main(int ac, char **av)
{
	GLFWwindow	*window;
	t_main		*win;
	void		*data;

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
	// glMatrixMode(GL_MODELVIEW);


	glfwSetWindowUserPointer(window, win);
// ray_player_prepare(win);
		// ray_casting(win);
	f();
	int x, y;
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// glColor3ub(0, 254, 0);
	    glEnable(GL_TEXTURE_2D);
	    glBegin(GL_POINTS);
	    y = 0;
	    while (y < 64)
	    {
	    	x = 0;
		    while (x < 64)
		    {
		    	glTexCoord2d(50, 50);
		    	 glVertex2d(x, y);
		    	x++;
		    }
		    y++;
		}
		glDisable(GL_TEXTURE_2D);
		glEnd();
		active_keys(win);
		// ray_casting(win);
		glfwSwapBuffers(window);
		// getchar();
		glfwWaitEvents();
	}

system ("leaks -quiet wolf3d");
    glfwDestroyWindow(window);
	glfwTerminate();
system ("leaks -quiet wolf3d");
	exit(EXIT_SUCCESS);
}
// /usr/local/include/