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

// void	f()
// {
// 	int width, height, nrChannels;
// 	// unsigned char *data = stbi_load("./WallPack/Flag9.bmp", &width, &height, &nrChannels, 0);
// 	// unsigned char *data = stbi_load("./Drawing.png", &width, &height, &nrChannels, 0);
// 	unsigned char *data = stbi_load("./Eridu757.bmp", &width, &height, &nrChannels, 0);
// 	GLuint texture;

// 	glGenTextures(1, &texture);
// 	glBindTexture(GL_TEXTURE_2D, texture);
// 	// gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
// 	// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
// 	for(int i = 0; i < 64 * 3; i += 3)
// 		printf("R:%d  G:%d  B:%d\n", (int)data[i], (int)data[i + 1], (int)data[i + 2]);
// 	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
// 	// glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// 	// 	unsigned int pid = SOIL_load_OGL_texture("./tex/wood.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS |
// 	printf("W:%d\nH:%d\nChan:%d\n", width, height, nrChannels);
// 	free(data);
// }
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
	// void		*data;

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

	win->img.img = stbi_load("./WallPack/Flag5.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0);
	// for(int i = 0; i < 64 * 3; i += 3)
		// printf("R:%d  G:%d  B:%d\n", (int)win->img.img[i], (int)win->img.img[i + 1], (int)win->img.img[i + 2]);


	// int width, height, nrChannels;
	// unsigned char *data = stbi_load("./WallPack/Flag5.png", &width, &height, &nrChannels, 0);
	// for(int i = 0; i < 64 * 3; i += 3)
	// 	printf("R:%d  G:%d  B:%d\n", (int)data[i], (int)data[i + 1], (int)data[i + 2]);

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