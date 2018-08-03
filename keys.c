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
	if (act == GLFW_PRESS || act == GLFW_REPEAT)
	{
		if (key == GLFW_KEY_ESCAPE)
			exit(1);
//			glfwSetWindowShouldClose(window, 1);
		if (key == GLFW_KEY_RIGHT)
		{
			win->gg.angle -= win->rotate;
			if (win->gg.angle > 360)
				win->gg.angle -= 360;
		}
		if (key == GLFW_KEY_LEFT)
		{
			win->gg.angle += win->rotate;
			if (win->gg.angle < 0)
				win->gg.angle += 360;
		}
		if (key == GLFW_KEY_SPACE)
			win->rotate = win->gg.angle_size;
		if (key == GLFW_KEY_BACKSPACE)
			win->rotate = 2;
		if (key == GLFW_KEY_UP)
			win->gg.posX += 1;
		if (key == GLFW_KEY_DOWN)
			win->gg.posX -= 1;		
		ray_casting(win);
	}
}
