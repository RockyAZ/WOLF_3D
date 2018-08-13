/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:34:28 by azaporoz          #+#    #+#             */
/*   Updated: 2018/08/03 16:34:29 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "wolf.h"

void	moving_up(t_main *win)
{
	float posX;
	float posY;
	int	f_x;
	int f_y;

	posX = win->gg.posX;
	posY = win->gg.posY;
	if (win->gg.angle <= 270 && win->gg.angle >= 90)
		f_x = -FACE;
	else
		f_x = FACE;
	if (win->gg.angle <= 180 && win->gg.angle >= 0)
		f_y = -FACE;
	else
		f_y = FACE;
	if (win->keys.up || win->keys.w)
	{
		posX += win->gg.speed * ft_cos(win->gg.angle) + f_x;
		if (!(win->data->map[(int)posY / CUBE][(int)posX / CUBE]))
			win->gg.posX = posX - f_x;
		posY += win->gg.speed * (ft_sin(win->gg.angle) * -1) + f_y;
		if (!(win->data->map[(int)posY / CUBE][(int)posX / CUBE]))
			win->gg.posY = posY - f_y;
		// if (!(win->data->map[(int)posY / CUBE][(int)posX / CUBE]))
		// {
		// 	win->gg.posX = posX - f_x;
		// 	win->gg.posY = posY - f_y;
		// }
	}
}

void	moving_down(t_main *win)
{
	float posX;
	float posY;

	posX = win->gg.posX;
	posY = win->gg.posY;
	if (win->keys.down || win->keys.s)
	{
		posX -= 5 * ft_cos(win->gg.angle);
		posY -= 5 * (ft_sin(win->gg.angle) * -1);
		if (!(win->data->map[(int)posY / CUBE][(int)posX / CUBE]))
		{
			win->gg.posX = posX;
			win->gg.posY = posY;
		}
	}
}

void	active_keys(t_main *win)
{
	win->gg.r_x = win->gg.posX / CUBE;
	win->gg.r_y = win->gg.posY / CUBE;
	if (win->keys.right)
	{
		win->gg.angle -= win->rotate;
		if (win->gg.angle > 360)
			win->gg.angle -= 360;
	}
	if (win->keys.left)
	{
		win->gg.angle += win->rotate;
		if (win->gg.angle < 0)
			win->gg.angle += 360;
	}
	moving_up(win);
	moving_down(win);
}
