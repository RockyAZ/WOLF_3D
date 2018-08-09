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

// void	draw(int X0, int Y0, int X1, int Y1, t_main *win, int color)
// {
//     int dx = X1 - X0;
//     int dy = Y1 - Y0;
//     int steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
//     float Xinc = dx / (float) steps;
//     float Yinc = dy / (float) steps;
//     float X = X0;
//     float Y = Y0;
//     for (int i = 0; i <= steps; i++)
//     {
//         glVertex2d(X,Y);
//         X += Xinc;
//         Y += Yinc;
//     }
// }

// void	draw(int x, int y, t_main *win)
// {
// 	int h;
// 	printf("%d   ", y);
// 	h = CENTR_H + y / 2;
// 	y = CENTR_H - y / 2;
// 	while (y < h)
// 	{
// 		glColor3ub(255, 0, 0);
// 		glVertex2d(x, y);
// 		y++;
// 	}
// 	exit(0);
// }


void	draw(int x, int y, t_main *win, int col)
{
int huy = 0;
	int i;
	int h;
	float tex;
	float tex_size;
	int	pos;

	tex_size = (float)CUBE / (float)y;
	tex = tex_size;
	h = CENTR_H + y / 2;
	y = CENTR_H - y / 2;
	while (y < h)
	{
		i = (win->img.pos * 3) + ((int)tex * (CUBE * 3));
// printf("=============================%d======================\n", huy);
// printf("X::%d\n", x);
// printf("Y::%d\n", y);
// printf("I::%d\n", i);
// printf("TEX:%f\n", tex);
// printf("TEX_size:%f\n", tex_size);
// printf("IMG.POS::%d\n", win->img.pos);
// printf("R:%d  G:%d  B:%d\n", (int)win->img.img[i], (int)win->img.img[i + 1], (int)win->img.img[i + 2]);
		// glColor3ub((int)win->img.flag[i], (int)win->img.flag[i + 1], (int)win->img.flag[i + 2]);
		glColor3ub((int)win->img.tex[col][i], (int)win->img.tex[col][i + 1], (int)win->img.tex[col][i + 2]);
		glVertex2d(x, y);
		tex += tex_size;
		y++;
huy++;
	}
// exit(0);
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
