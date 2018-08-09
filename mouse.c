/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:58:37 by azaporoz          #+#    #+#             */
/*   Updated: 2018/08/09 15:58:38 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    mouse_pos(GLFWwindow *window, double x, double y)
{
    t_main *win;

    win = glfwGetWindowUserPointer(window);
    // printf("X:%f\nY:%f\n\n", x, y);
    win->gg.angle -= (x - win->m.x) * 0.6;
    win->m.x = (int)x;
    win->m.y = (int)y;
}