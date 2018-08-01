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
	{
		printf("VERIC_DONE\n");
		return (-1);
	}
	if (angle > 90 && angle < 270)
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE - 1;
	else
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE + CUBE;

	if (angle == 180 || angle == 0 || angle == 360)
		win->ray.v_dot.pix_y = win->gg.posY;
	else
		if ((win->ray.v_dot.pix_y = win->gg.posY + (win->gg.posX - win->ray.v_dot.pix_x) * ft_tan(angle)) >= win->data->max_y)
		{
			printf("VERIC_DONE\n");
			return (-1);
		}
	win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
	win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
	if (angle > 90 && angle < 270)
		win->ray.v_dot.var_x = -CUBE;
	else
		win->ray.v_dot.var_x = CUBE;
	if (angle == 180 || angle == 0 || angle == 360)
		win->ray.v_dot.var_y = 0;
	else if (angle > 90 && angle < 270)
		win->ray.v_dot.var_y = (CUBE * ft_tan(angle)) * -1;
	else
		win->ray.v_dot.var_y = CUBE * ft_tan(angle);
	while (win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x] == 0)
	{
		win->ray.v_dot.pix_y += win->ray.v_dot.var_y;
		win->ray.v_dot.pix_x += win->ray.v_dot.var_x;
		win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
		win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
	}
	printf("VERIC_DONE\n");
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
		if ((win->ray.h_dot.pix_x = win->gg.posX + (win->gg.posY - win->ray.h_dot.pix_y) / ft_tan(angle)) >= win->data->max_x)
			return (-1);
// win->ray.h_dot.pix_x = win->gg.posX + (win->gg.posY - win->ray.h_dot.pix_y) / ft_tan(angle);
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
	}
	printf("HORIZ_DONE\n");
	return ((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2)));
}


void	ray_casting(t_main *win)
{
	int		i;
	float	angle;
	int		v;
	int		h;

	i = 0;
	// if (win->gg.angle > 360)
	// 	win->gg.angle -= 360;
	angle = win->gg.angle - (win->gg.fov / 2);
	printf("VERTIC""%d\n", vertic_inter(win, 360.062500));
	glClear(GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/);
	glBegin(GL_LINES);
	while (i < WIDTH)
	{
		if (angle > 360)
			angle -= 360;
printf("angle::%f\n", angle);
printf("I::%d\n", i);
		v = vertic_inter(win, angle);
		h = horiz_inter(win, angle);
		printf("HORIZ::%d\nVERIC::%d\n", h, v);
		if (v == -1)
			line_draw(win, i, h);
		else if (h == -1)
			line_draw(win, i, v);
		else
			line_draw(win, i, (float)((float)CUBE / (float)ft_min(h, v)) * win->gg.to_screen);
		angle += win->gg.angle_size;
		i++;
	}
	glEnd();
}
