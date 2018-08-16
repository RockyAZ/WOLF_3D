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

void	moving_up(t_main *win, int lr)
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
	if (win->keys.up || win->keys.w || lr)
	{
		posX += win->gg.speed * ft_cos(win->gg.angle) + f_x;
		if (!(win->data->map[(int)win->gg.posY >> BIT][(int)posX >> BIT]))		
			win->gg.posX = posX - f_x;
		posY += win->gg.speed * (ft_sin(win->gg.angle) * -1) + f_y;
		if (!(win->data->map[(int)posY >> BIT][(int)win->gg.posX >> BIT]))
			win->gg.posY = posY - f_y;
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
		// posX -= 5 * ft_cos(win->gg.angle);
		// posY -= 5 * (ft_sin(win->gg.angle) * -1);
		// if (!(win->data->map[(int)posY / CUBE][(int)posX / CUBE]))
		// {
		// 	win->gg.posX = posX;
		// 	win->gg.posY = posY;
		// }
		posX -= win->gg.speed * ft_cos(win->gg.angle);
		if (!(win->data->map[(int)win->gg.posY >> BIT][(int)posX >> BIT]))		
			win->gg.posX = posX;
		posY -= win->gg.speed * (ft_sin(win->gg.angle) * -1);
		if (!(win->data->map[(int)posY >> BIT][(int)win->gg.posX >> BIT]))
			win->gg.posY = posY;
	}
}

void	moving_side(t_main *win)
{
	if (win->keys.a || win->keys.d)
	{
		if (win->keys.a)
			win->gg.angle += 90;
		if(win->keys.d)
			win->gg.angle -= 90;
		if (win->gg.angle >= 360)
			win->gg.angle -= 360;
		if (win->gg.angle < 0)
			win->gg.angle += 360;
		moving_up(win, 1);
		if (win->keys.a)
			win->gg.angle -= 90;
		if (win->keys.d)
			win->gg.angle += 90;
		if (win->gg.angle >= 360)
			win->gg.angle -= 360;
		if (win->gg.angle < 0)
			win->gg.angle += 360;
	}
}

void	active_keys(t_main *win)
{
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
	if (win->gg.angle >= 360)
		win->gg.angle -= 360;
	if (win->gg.angle < 0)
		win->gg.angle += 360;
	moving_up(win, 0);
	moving_down(win);
	moving_side(win);
	win->gg.r_x = (int)win->gg.posX >> BIT;
	win->gg.r_y = (int)win->gg.posY >> BIT;
}
