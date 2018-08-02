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
/*
void			get_buff(double *buff, t_coord cd1, t_coord cd2)
{
	buff[0] = fabs(cd1.x - cd2.x);
	buff[1] = fabs(cd1.y - cd2.y);
	buff[2] = cd1.x < cd2.x ? 1 : -1;
	buff[3] = cd1.y < cd2.y ? 1 : -1;
	buff[4] = (buff[0] > buff[1] ? buff[0] : -buff[1]);
	buff[6] = 1;
}

static void		draw_point(t_win *win)
{
	glVertex2d()
}

void			line_draw(t_main *win, int i, int h)
{
	float buff[7];

	if (v1.x < 0 && v1.x > WIDTH && v1.y < 0 && v1.y > HEIGHT)
		return ;
	get_buff(buff, v1, v2);
	while (buff[6] == 1 && !((int)v1.x == (int)v2.x && (int)v1.y == (int)v2.y))
	{
		if (v1.x >= 0 && v1.x <= WIDTH && v1.y >= 0 && v1.y <= HEIGHT)
			draw_point(&v1, win, v1.color);
		buff[5] = buff[4];
		buff[6] = 0;
		if (buff[5] > -buff[0] && (int)v1.x != (int)v2.x)
		{
			buff[4] -= buff[1];
			v1.x += buff[2];
			buff[6] = 1;
		}
		if (buff[5] < buff[1] && (int)v1.y != (int)v2.y)
		{
			buff[4] += buff[0];
			v1.y += buff[3];
			buff[6] = 1;
		}
	}
}
*/
void	line_draw(t_main *win, int i, float h, int color)
{
	// printf("--->%f\n", h);
	if (color == 1)
		glColor3ub(0, 254, 0);
	else
		glColor3ub(254, 0, 0);
	glVertex2d(i, CENTR_H - h / 2);
	glVertex2d(i, CENTR_H + h / 2);
}
