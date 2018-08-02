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

int		vertic_inter(t_main *win, float angle)
{
	if (angle == 90 || angle == 270)
		return (-1);
	if (angle > 90 && angle < 270)
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE - 1;
	else
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE + CUBE;
	if (angle == 180 || angle == 0 || angle == 360)
		win->ray.v_dot.pix_y = win->gg.posY;
	else
		win->ray.v_dot.pix_y = win->gg.posY + (win->gg.posX - win->ray.v_dot.pix_x) * ft_tan(angle);
	if (win->ray.v_dot.pix_y >= win->data->max_y || win->ray.v_dot.pix_y < 0)
		return (-1);
	win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
	win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
	if (angle > 90 && angle < 270)
		win->ray.v_dot.var_x = -CUBE;
	else
		win->ray.v_dot.var_x = CUBE;
	if (angle == 180 || angle == 0 || angle == 360)
		win->ray.v_dot.var_y = 0;
	else if (angle < 90 || angle > 270)
		win->ray.v_dot.var_y = (CUBE * ft_tan(angle)) * -1;
	else
		win->ray.v_dot.var_y = CUBE * ft_tan(angle);
	while (win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x] == 0)
	{
		win->ray.v_dot.pix_y += win->ray.v_dot.var_y;
		win->ray.v_dot.pix_x += win->ray.v_dot.var_x;
		win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
		win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
		if (win->ray.v_dot.pix_y >= win->data->max_y || win->ray.v_dot.pix_y < 0)
			return (-1);
	}
	return ((int)sqrt(powf(win->gg.posX - win->ray.v_dot.pix_x, 2) + powf(win->gg.posY - win->ray.v_dot.pix_y, 2)));
}

int		horiz_inter(t_main *win, float angle)
{
	if (angle == 180 || angle == 0 || angle == 360)
		return (-1);
	if (angle > 0 && angle < 180)
		win->ray.h_dot.pix_y = (win->gg.posY / CUBE) * CUBE - 1;
	else
		win->ray.h_dot.pix_y = (win->gg.posY / CUBE) * CUBE + CUBE;
	if (angle == 90 || angle == 270)
		win->ray.h_dot.pix_x = win->gg.posX;
	else
		win->ray.h_dot.pix_x = win->gg.posX + (win->gg.posY - win->ray.h_dot.pix_y) / ft_tan(angle);
		if (win->ray.h_dot.pix_x >= win->data->max_x || win->ray.h_dot.pix_x < 0)
			return (-1);
	win->ray.h_dot.real_x = win->ray.h_dot.pix_x / CUBE;
	win->ray.h_dot.real_y = win->ray.h_dot.pix_y / CUBE;
	if (angle == 90 || angle == 270)
		win->ray.h_dot.var_x = 0;
	else if (angle > 180)
		win->ray.h_dot.var_x = (CUBE / ft_tan(angle)) * -1;
	else
		win->ray.h_dot.var_x = CUBE / ft_tan(angle);
	if (angle >= 0 && angle <= 180)
		win->ray.h_dot.var_y = -CUBE;
	else
		win->ray.h_dot.var_y = CUBE;
	while (win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x] == 0)
	{
		win->ray.h_dot.pix_x += win->ray.h_dot.var_x;
		win->ray.h_dot.pix_y += win->ray.h_dot.var_y;
		win->ray.h_dot.real_x = win->ray.h_dot.pix_x / CUBE;
		win->ray.h_dot.real_y = win->ray.h_dot.pix_y / CUBE;
		if (win->ray.h_dot.pix_x >= win->data->max_x || win->ray.h_dot.pix_x < 0)
			return (-1);
	}
	return ((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2)));
}

void	ray_casting(t_main *win)
{
	int		i;
	int		var;
	float	angle;
	int		v;
	int		h;

	i = 0;
	angle = win->gg.angle + (win->gg.fov / 2);
	// printf("VERTIC:%d\n", vertic_inter(win, 299));
	// exit(1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);
	while (i < WIDTH)
	{
		if (angle > 360)
			angle -= 360;
		else if (angle < 0)
			angle += 360;
		v = vertic_inter(win, angle);
		h = horiz_inter(win, angle);
win->huy = 0;
if (angle == win->gg.angle)
{
printf("angle::%f\n", angle);
printf("PLAYER_X:%d\nPLAYER_Y:%d\n", win->gg.posX, win->gg.posY);
printf("<><>PLAYER_ANGLE::%f\n", win->gg.angle);
printf("I::%d\n", i);
printf("HORIZ_return::%d\nVERIC_return::%d\n\n", h, v);
printf("HORIZ_REAL_X::%d\n", win->ray.h_dot.real_x);
printf("HORIZ_REAL_Y::%d\n\n\n", win->ray.h_dot.real_y);
printf("VERTIC_REAL_X::%d\n", win->ray.v_dot.real_x);
printf("VERTIC_REAL_Y::%d\n", win->ray.v_dot.real_y);
win->huy = 1;
}
		if (v == -1)
		{
			if (win->huy)
			write(1, "-v\n", 3);
			line_draw(win, i, ((float)CUBE / (float)h) * win->gg.to_screen, win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x]);
		}
		else if (h == -1)
		{
			if (win->huy)
			write(1, "-h\n", 3);
			line_draw(win, i, ((float)CUBE / (float)v) * win->gg.to_screen, win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x]);
		}
		else
		{
			if (v < h)
			{
				if (win->huy)
					write(1, "1\n", 2);
				line_draw(win, i, ((float)CUBE / (float)v) * win->gg.to_screen, win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x]);
			}
			else if (h < v)
			{
				if (win->huy)
					write(1, "2\n", 2);
				line_draw(win, i, ((float)CUBE / (float)h) * win->gg.to_screen, win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x]);	
			}
			else
			{
				if (win->huy)
					write(1, "3\n", 2);
				line_draw(win, i, ((float)CUBE / (float)v) * win->gg.to_screen, win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x]);
			}
			// line_draw(win, i, (float)((float)CUBE / (float)ft_min(h, v)) * win->gg.to_screen);
		}
		angle -= win->gg.angle_size;
		i++;
win->huy = 0;
	}
	glEnd();
}
