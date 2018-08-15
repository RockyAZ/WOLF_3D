/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:29:42 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/31 15:29:43 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		get_color(int x, int y)
{
	return((x * 3) + (y * 3 * CUBE));
}

void	draw_floor(int x, int y, t_main *win)
{
	float dist;
	float var;
	int nx;
	int ny;
	int		i;

	while (y < HEIGHT)
	{
		var = (((float)win->gg.height / ((float)y - (float)CENTR_H)) * win->gg.to_screen);
		dist = var / ft_cos(ft_abs(win->angle - win->gg.angle));
			ny = win->gg.posY - (dist * ft_sin(win->angle));
		if (win->angle >= 90 && win->angle <= 270)
			nx = win->gg.posX + (dist * ft_cos(win->angle));
		else
			nx = win->gg.posX + (dist * ft_cos(win->angle));
		i = get_color(nx % CUBE, ny % CUBE);
		// glColor3ub((int)win->img.tex[0][i], (int)win->img.tex[0][i + 1], (int)win->img.tex[0][i + 2]);
		glColor3ub((int)win->img.tex[2][i], (int)win->img.tex[2][i + 1], (int)win->img.tex[2][i + 2]);
		glVertex2d(x, y);
		glVertex2d(x, HEIGHT - y);		
		y++;
	}
}

void	draw(int x, int y, t_main *win, int color, int wallX)
{
	int i;
	int h;
	float tex;
	float tex_size;

	tex_size = (float)CUBE / (float)y;
	tex = tex_size;
	h = CENTR_H + (y >> 1);							// h = CENTR_H + y >> 1;				 ->looks like camera downing
	y = CENTR_H - (y >> 1);							// y = CENTR_H - y >> 1;				 ->looks like camera downing
	if (h > HEIGHT)
		h = HEIGHT;
	if (y < 0)
	{
		tex = tex_size * (ft_abs(y));
		y = 0;
	}
	while (y < h)
	{
		i = (win->img.pos * 3) + ((int)tex * (CUBE * 3));
		glColor3ub((int)win->img.tex[color][i], (int)win->img.tex[color][i + 1], (int)win->img.tex[color][i + 2]);
		glVertex2d(x, y);
		tex += tex_size;
		y++;
	}
	// if (win->huy == 1)
	draw_floor(x, y, win);
}

void	line_draw(t_main *win, int i, float h, int tex, int wallX)
{
	win->img.pos = wallX % CUBE;
// if (win->huy == 1)
// printf("MAIN_HEIGHT::%f\n", h);
	// draw(i, CENTR_H + h / 2, i, CENTR_H - h / 2, win, color);
	draw(i, h, win, tex, wallX);
}
