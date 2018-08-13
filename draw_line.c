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

int		get_color(int x, int y, t_main *win)
{
	return((x * 3) + (y * 3 * win->data->col));
}

void	draw_floor(int x, int y, int dist, t_main *win, int color)
{
	float	cur;
	float	weight;
	int		fx;
	int		fy;
	int		pix;

	while (y < HEIGHT)
	{
		cur = HEIGHT / (2.0f * y - HEIGHT);
		weight = cur / dist;
		fx = (int)((weight * ft_cos(win->angle) + (1.0f - weight) * (win->gg.posX / CUBE)) * 32) % 32;
		fy = (int)((weight * ft_sin(win->angle) + (1.0f - weight) * (win->gg.posY / CUBE)) * 32) % 32;
		pix = get_color(fx, fy, win);
		glColor3ub((int)win->img.tex[0][pix], (int)win->img.tex[0][pix + 1], (int)win->img.tex[0][pix + 2]);
		glVertex2d(x, y);
		y++;
	}
}

void	draw(int x, int y, t_main *win, int color)
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
}

void	line_draw(t_main *win, int i, float h, int tex, int xy)
{
	win->img.pos = xy % CUBE;
	// if (color == 1)
	// 	glColor3ub(0, 254, 0);
	// else if (color == 2)
	// 	glColor3ub(254, 0, 0);
	// else if (color == 3)
	// 	glColor3ub(0, 0, 254);
	// draw(i, CENTR_H + h / 2, i, CENTR_H - h / 2, win, color);
	draw(i, h, win, tex);
}