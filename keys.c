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

void	key_press_add(int key, t_main *win)
{
	if (key == GLFW_KEY_RIGHT)
		win->keys.right = 1;
	if (key == GLFW_KEY_LEFT)
		win->keys.left = 1;
	if (key == GLFW_KEY_UP)
		win->keys.up = 1;
	if (key == GLFW_KEY_DOWN)
		win->keys.down = 1;
	if (key == GLFW_KEY_W)
		win->keys.w = 1;
	if (key == GLFW_KEY_S)
		win->keys.s = 1;
	if (key == GLFW_KEY_A)
		win->keys.a = 1;
	if (key == GLFW_KEY_D)
		win->keys.d = 1;
	if (key == GLFW_KEY_LEFT_SHIFT)
		win->gg.speed = 10;
}

void	key_release_add(int key, t_main *win)
{
	if (key == GLFW_KEY_RIGHT)
		win->keys.right = 0;
	if (key == GLFW_KEY_LEFT)
		win->keys.left = 0;
	if (key == GLFW_KEY_UP)
		win->keys.up = 0;
	if (key == GLFW_KEY_DOWN)
		win->keys.down = 0;
	if (key == GLFW_KEY_W)
		win->keys.w = 0;
	if (key == GLFW_KEY_S)
		win->keys.s = 0;
	if (key == GLFW_KEY_A)
		win->keys.a = 0;
	if (key == GLFW_KEY_D)
		win->keys.d = 0;
	if (key == GLFW_KEY_LEFT_SHIFT)
		win->gg.speed = 5;
}

void	key_space(GLFWwindow *window, t_main *win, int key)
{
	if (key == GLFW_KEY_SPACE)
	{
		if (win->keys.space == 0)
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			win->keys.space = 1;
		}
		else if (win->keys.space == 1)
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			win->keys.space = 0;
		}
	}
}

void	key_callback(GLFWwindow *window, int key, int scan, int act, int mods)
{
	t_main *win;

	win = glfwGetWindowUserPointer(window);
	(void)scan;
	(void)act;
	(void)mods;
	if (act == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window, 1);
		key_space(window, win, key);
		key_press_add(key, win);
	}
	if (act == GLFW_RELEASE)
		key_release_add(key, win);
}
