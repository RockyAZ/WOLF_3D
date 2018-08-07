/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:39:30 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/30 13:39:31 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_callback(GLFWwindow* window, int key, int scan, int act, int mods)
{
	t_main *win;

	win = glfwGetWindowUserPointer(window);
	if (act == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			exit(1);
//			glfwSetWindowShouldClose(window, 1);
		if (key == GLFW_KEY_SPACE)
			win->rotate = win->gg.angle_size;
		if (key == GLFW_KEY_BACKSPACE)
			win->rotate = 2;

		if (key == GLFW_KEY_RIGHT)
			win->keys.right = 1;
		if (key == GLFW_KEY_LEFT)
			win->keys.left = 1;
		if (key == GLFW_KEY_UP)
			win->keys.up = 1;
		if (key == GLFW_KEY_DOWN)
			win->keys.down = 1;
		// if (key == GLFW_KEY_W)
			// win->gg.to_screen += 6;
		// if (key == GLFW_KEY_S)
			// win->gg.to_screen -= 6;
	}
	if (act == GLFW_RELEASE)
	{
		if (key == GLFW_KEY_RIGHT)
			win->keys.right = 0;
		if (key == GLFW_KEY_LEFT)
			win->keys.left = 0;
		if (key == GLFW_KEY_UP)
			win->keys.up = 0;
		if (key == GLFW_KEY_DOWN)
			win->keys.down = 0;
	}
		// ray_casting(win);
}
