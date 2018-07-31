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
	if (angle >= 90 && angle <= 270)
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE - 1;
	else
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE + CUBE;
	win->ray.v_dot.pix_y = win->gg.posY + (win->gg.posX - win->ray.v_dot.pix_x) / tan(angle);
	win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
	win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
	// printf("A::%f\n", angle);	
	// printf("T::%f\n", tan(angle));
	win->ray.v_dot.var_y = CUBE / tan(angle);
	if (angle >= 90 && angle <= 270)
		win->ray.v_dot.var_x -= CUBE;
	else
		win->ray.v_dot.var_x += CUBE;
	while (!win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x])
	{
		win->ray.v_dot.pix_y += win->ray.v_dot.var_y;
		if (angle >= 90 && angle <= 270)
			win->ray.v_dot.var_x -= CUBE;
		else
			win->ray.v_dot.var_x += CUBE;
		win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
		win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
	}
	return (sqrt( (((int)win->gg.posX - win->ray.v_dot.pix_x) ^ 2) + ( ((int)win->gg.posY - win->ray.v_dot.pix_y) ^ 2) ));
}

int		horiz_inter(t_main *win, float angle)
{
	if (angle >= 0 && angle <= 180)
		win->ray.h_dot.pix_y = (win->gg.posY / CUBE) * CUBE - 1;
	else
		win->ray.h_dot.pix_y = (win->gg.posY / CUBE) * CUBE + CUBE;
	win->ray.h_dot.pix_x = win->gg.posX + (win->gg.posY - win->ray.h_dot.pix_y) / tan(angle);
	win->ray.h_dot.real_x = win->ray.h_dot.pix_x / CUBE;
	win->ray.h_dot.real_y = win->ray.h_dot.pix_y / CUBE;

	win->ray.h_dot.var_x = CUBE / tan(angle);
	if (angle >= 0 && angle <= 180)
		win->ray.h_dot.var_y -= CUBE;
	else
		win->ray.h_dot.var_y += CUBE;
	while (!win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x])
	{
		win->ray.h_dot.pix_x += win->ray.h_dot.var_x;
		if (angle >= 0 && angle <= 180)
			win->ray.h_dot.var_y -= CUBE;
		else
			win->ray.h_dot.var_y += CUBE;
		win->ray.h_dot.real_x = win->ray.h_dot.pix_x / CUBE;
		win->ray.h_dot.real_y = win->ray.h_dot.pix_y / CUBE;
	}
	return (sqrt( (((int)win->gg.posX - win->ray.h_dot.pix_x) ^ 2) + ( ((int)win->gg.posY - win->ray.h_dot.pix_y) ^ 2) ));
}

void	ray_casting(t_main *win)
{
	int		i;
	float	angle;

	i = 0;
	angle = win->gg.angle - (win->gg.fov / 2);
	glClear(GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/);
	glBegin(GL_LINES);
	while (i < WIDTH)
	{
		line_draw(win, i, CUBE / ft_min(horiz_inter(win, angle), vertic_inter(win, angle) * win->gg.to_screen));
		// printf("1:%f\n", win->gg.angle);
		// printf("2:%f\n", win->gg.angle_size);
		printf("3:%f\n", angle);
		angle += win->gg.angle_size;
		i++;
	}
	glEnd();
}
