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
		win->ray.v_dot.pix_x = ((int)win->gg.posX / CUBE) * CUBE - 1;
	else
		win->ray.v_dot.pix_x = ((int)win->gg.posX / CUBE) * CUBE + CUBE;
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
	return (((int)sqrt(powf(win->gg.posX - win->ray.v_dot.pix_x, 2) + powf(win->gg.posY - win->ray.v_dot.pix_y, 2)))*ft_cos(win->gg.angle - angle));
}

int		horiz_inter(t_main *win, float angle)
{
	if (angle == 180 || angle == 0 || angle == 360)
		return (-1);
	if (angle > 0 && angle < 180)
		win->ray.h_dot.pix_y = ((int)win->gg.posY / CUBE) * CUBE - 1;
	else
		win->ray.h_dot.pix_y = ((int)win->gg.posY / CUBE) * CUBE + CUBE;
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
	return (((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2)))*ft_cos(win->gg.angle - angle));
}

void	ray_casting(t_main *win)
{
	int		i;
	int		var;
	float	angle;
	int		v;
	int		h;
	glClear ( GL_COLOR_BUFFER_BIT  |  GL_DEPTH_BUFFER_BIT  |  GL_STENCIL_BUFFER_BIT );
	glBegin(GL_POINTS);
	i = 0;
	angle = win->gg.angle + (win->gg.fov / 2);
	while (i < WIDTH)
	{
	if (angle == win->gg.angle)
		printf("%f\n", angle);
		if (angle > 360)
			angle -= 360;
		else if (angle < 0)
			angle += 360;
		v = vertic_inter(win, angle);
		h = horiz_inter(win, angle);
		if (v == -1)
			line_draw(win, i, ((float)CUBE / (float)h) * win->gg.to_screen, win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x], win->ray.h_dot.pix_x);
		else if (h == -1)
			line_draw(win, i, ((float)CUBE / (float)v) * win->gg.to_screen, win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x], win->ray.v_dot.pix_y);
		else
		{
			if (v < h)
				line_draw(win, i, ((float)CUBE / (float)v) * win->gg.to_screen, win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x], win->ray.v_dot.pix_y);
			else
				line_draw(win, i, ((float)CUBE / (float)h) * win->gg.to_screen, win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x], win->ray.h_dot.pix_x);
			// else
				// line_draw(win, i, ((float)CUBE / (float)v) * win->gg.to_screen, win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x]);
		}
		angle -= win->gg.angle_size;
		i++;
	}
	glEnd();
}
