/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:14:26 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/30 13:14:26 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		vertic_inter_left(t_main *win, float angle)
{
	win->ray.v_dot.pix_x = (((int)win->gg.posX >> BIT) << BIT) - 1;
	if (angle == 180)
		win->ray.v_dot.pix_y = win->gg.posY;
	else
		win->ray.v_dot.pix_y = win->gg.posY + (win->gg.posX - win->ray.v_dot.pix_x) * ft_tan(angle);
	if (win->ray.v_dot.pix_y >= win->data->max_y || win->ray.v_dot.pix_y < 0)
		return (-1);
	win->ray.v_dot.real_x = (int)win->ray.v_dot.pix_x >> BIT;
	win->ray.v_dot.real_y = (int)win->ray.v_dot.pix_y >> BIT;
	win->ray.v_dot.var_x = -CUBE;
	if (angle == 180)
		win->ray.v_dot.var_y = 0;
	win->ray.v_dot.var_y = CUBE * ft_tan(angle);
	while (win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x] == 0)
	{
		win->ray.v_dot.pix_y += win->ray.v_dot.var_y;
		win->ray.v_dot.pix_x += win->ray.v_dot.var_x;
		win->ray.v_dot.real_x = (int)win->ray.v_dot.pix_x >> BIT;
		win->ray.v_dot.real_y = (int)win->ray.v_dot.pix_y >> BIT;
		if (win->ray.v_dot.pix_y >= win->data->max_y || win->ray.v_dot.pix_y < 0)
			return (-1);
	}
	return (((int)sqrt(powf(win->gg.posX - win->ray.v_dot.pix_x, 2) + powf(win->gg.posY - win->ray.v_dot.pix_y, 2))) * ft_cos(win->gg.angle - angle));
}

int		vertic_inter_right(t_main *win, float angle)
{
	win->ray.v_dot.pix_x = (((int)win->gg.posX >> BIT) << BIT) + CUBE;
	if (angle == 0)
		win->ray.v_dot.pix_y = win->gg.posY;
	else
		win->ray.v_dot.pix_y = win->gg.posY + (win->gg.posX - win->ray.v_dot.pix_x) * ft_tan(angle);
	if (win->ray.v_dot.pix_y >= win->data->max_y || win->ray.v_dot.pix_y < 0)
		return (-1);
	win->ray.v_dot.real_x = (int)win->ray.v_dot.pix_x >> BIT;
	win->ray.v_dot.real_y = (int)win->ray.v_dot.pix_y >> BIT;
	win->ray.v_dot.var_x = CUBE;
	if (angle == 0)
		win->ray.v_dot.var_y = 0;
	win->ray.v_dot.var_y = (CUBE * ft_tan(angle)) * -1;
	while (win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x] == 0)
	{
		win->ray.v_dot.pix_y += win->ray.v_dot.var_y;
		win->ray.v_dot.pix_x += win->ray.v_dot.var_x;
		win->ray.v_dot.real_x = (int)win->ray.v_dot.pix_x >> BIT;
		win->ray.v_dot.real_y = (int)win->ray.v_dot.pix_y >> BIT;
		if (win->ray.v_dot.pix_y >= win->data->max_y || win->ray.v_dot.pix_y < 0)
			return (-1);
	}
	return (((int)sqrt(powf(win->gg.posX - win->ray.v_dot.pix_x, 2) + powf(win->gg.posY - win->ray.v_dot.pix_y, 2))) * ft_cos(win->gg.angle - angle));
}

int		horiz_inter_top(t_main *win, float angle)
{
	win->ray.h_dot.pix_y = (((int)win->gg.posY >> BIT) << BIT) - 1;
	if (angle == 90)
		win->ray.h_dot.pix_x = win->gg.posX;
	else
		win->ray.h_dot.pix_x = win->gg.posX + (win->gg.posY - win->ray.h_dot.pix_y) / ft_tan(angle);
	if (win->ray.h_dot.pix_x >= win->data->max_x || win->ray.h_dot.pix_x < 0)
		return (-1);
	win->ray.h_dot.real_x = (int)win->ray.h_dot.pix_x >> BIT;
	win->ray.h_dot.real_y = (int)win->ray.h_dot.pix_y >> BIT;
	if (angle == 90)
		win->ray.h_dot.var_x = 0;
	else
		win->ray.h_dot.var_x = CUBE / ft_tan(angle);
	win->ray.h_dot.var_y = -CUBE;
	while (win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x] == 0)
	{
		win->ray.h_dot.pix_x += win->ray.h_dot.var_x;
		win->ray.h_dot.pix_y += win->ray.h_dot.var_y;
		win->ray.h_dot.real_x = (int)win->ray.h_dot.pix_x >> BIT;
		win->ray.h_dot.real_y = (int)win->ray.h_dot.pix_y >> BIT;
		if (win->ray.h_dot.pix_x >= win->data->max_x || win->ray.h_dot.pix_x < 0)
			return (-1);
	}
	return (((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2))) * ft_cos(win->gg.angle - angle));
}

int		horiz_inter_bot(t_main *win, float angle)
{
	win->ray.h_dot.pix_y = (((int)win->gg.posY >> BIT) << BIT) + CUBE;
	if (angle == 270)
		win->ray.h_dot.pix_x = win->gg.posX;
	else
		win->ray.h_dot.pix_x = win->gg.posX + (win->gg.posY - win->ray.h_dot.pix_y) / ft_tan(angle);
	if (win->ray.h_dot.pix_x >= win->data->max_x || win->ray.h_dot.pix_x < 0)
		return (-1);
	win->ray.h_dot.real_x = (int)win->ray.h_dot.pix_x >> BIT;
	win->ray.h_dot.real_y = (int)win->ray.h_dot.pix_y >> BIT;
	if (angle == 270)
		win->ray.h_dot.var_x = 0;
	else
		win->ray.h_dot.var_x = (CUBE / ft_tan(angle)) * -1;
	win->ray.h_dot.var_y = CUBE;
	while (win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x] == 0)
	{
		win->ray.h_dot.pix_x += win->ray.h_dot.var_x;
		win->ray.h_dot.pix_y += win->ray.h_dot.var_y;
		win->ray.h_dot.real_x = (int)win->ray.h_dot.pix_x >> BIT;
		win->ray.h_dot.real_y = (int)win->ray.h_dot.pix_y >> BIT;
		if (win->ray.h_dot.pix_x >= win->data->max_x || win->ray.h_dot.pix_x < 0)
			return (-1);
	}
	return (((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2)))*ft_cos(win->gg.angle - angle));
}

void	ray_casting(t_main *win)
{
	int		i;
	float	angle;
	int		v;
	int		h;

	i = 0;
	angle = win->gg.angle + (win->gg.fov / 2);
	v = -5;
	h = -5;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glBegin(GL_POINTS);
	while (i < WIDTH)
	{
	if (i == WIDTH / 2)
		printf("ANGLE-->>%f\npX-->>%f\npY-->>%f\nX--->>>%d\nY--->>>%d\n\n", win->gg.angle, win->gg.posX, win->gg.posY, win->gg.r_x, win->gg.r_y);
		if (angle >= 360)
			angle -= 360;
		if (angle < 0)
			angle += 360;
		win->ray.angle = angle;
		if (angle > 0 && angle < 180)
			h = horiz_inter_top(win, angle);
		else if (angle > 180 && angle < 360)
			h = horiz_inter_bot(win, angle);
		if (angle > 90 && angle < 270)
			v = vertic_inter_left(win, angle);
/*
** be carfull with || insted && in the case bellow!!!
*/
		else if (angle > 270 || angle < 90)
			v = vertic_inter_right(win, angle);
/*
** last argument in functions for serching places on textures
*/
		if (v < 0)
			line_draw(win, i, ((float)CUBE / (float)h) * win->gg.to_screen, win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x], win->ray.h_dot.pix_x);
		else if (h < 0)
			line_draw(win, i, ((float)CUBE / (float)v) * win->gg.to_screen, win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x], win->ray.v_dot.pix_y);
		else
		{
			if (v < h)
				line_draw(win, i, ((float)CUBE / (float)v) * win->gg.to_screen, win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x], win->ray.v_dot.pix_y);
			else
				line_draw(win, i, ((float)CUBE / (float)h) * win->gg.to_screen, win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x], win->ray.h_dot.pix_x);
		}
		angle -= win->gg.angle_size;
		i++;
	}
	glEnd();
}
