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
	return ((x * 3) + (y * 3 * CUBE));
}

void	draw_floor(int x, int y, t_main *win)
{
	float	dist;
	int		nx;
	int		ny;
	int		i;

	while (y < HEIGHT)
	{
		dist = (((float)win->gg.height / ((float)y - (float)CENTR_H)) *\
		win->gg.to_screen) / ft_cos(ft_abs(win->ray.angle - win->gg.angle));
		ny = win->gg.p_y - (dist * ft_sin(win->ray.angle));
		nx = win->gg.p_x + (dist * ft_cos(win->ray.angle));
		i = get_color(nx % CUBE, ny % CUBE);
		SDL_SetRenderDrawColor(win->ren, (int)win->img.tex[0][i], (int)win->img.tex[0][i + 1],\
		(int)win->img.tex[0][i + 2], 0);
		SDL_RenderDrawPoint(win->ren, x, y);
		SDL_SetRenderDrawColor(win->ren, (int)win->img.tex[9][i], (int)win->img.tex[9][i + 1],\
		(int)win->img.tex[9][i + 2], 0);
		SDL_RenderDrawPoint(win->ren, x, y);
		y++;
	}
}

void	add_draw(t_main *win, int i, int color)
{
	if (color == 5)
	{
		if (win->ray.angle >= 0 && win->ray.angle <= 180 && win->h_is)
			SDL_SetRenderDrawColor(win->ren, (int)win->img.tex[5][i], (int)win->img.tex[5][i + 1],\
			(int)win->img.tex[5][i + 2], 0);
		else if (win->ray.angle >= 90 && win->ray.angle <= 270 && win->v_is)
			SDL_SetRenderDrawColor(win->ren, (int)win->img.tex[6][i], (int)win->img.tex[6][i + 1],\
			(int)win->img.tex[6][i + 2], 0);
		else if (win->ray.angle >= 180 && win->ray.angle < 360 && win->h_is)
			SDL_SetRenderDrawColor(win->ren, (int)win->img.tex[7][i], (int)win->img.tex[7][i + 1],\
			(int)win->img.tex[7][i + 2], 0);
		else if ((win->ray.angle > 270 || win->ray.angle < 90) && win->v_is)
			SDL_SetRenderDrawColor(win->ren, (int)win->img.tex[8][i], (int)win->img.tex[8][i + 1],\
			(int)win->img.tex[8][i + 2], 0);
	}
	else
		SDL_SetRenderDrawColor(win->ren, (int)win->img.tex[color][i],\
		(int)win->img.tex[color][i + 1], (int)win->img.tex[color][i + 2], 0);
}

void	draw(int x, int y, t_main *win, int color)
{
	int		i;
	int		h;
	float	tex;
	float	tex_size;

	tex_size = (float)CUBE / (float)y;
	tex = tex_size;
	h = CENTR_H + (y >> 1);
	y = CENTR_H - (y >> 1);
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
		add_draw(win, i, color);
		SDL_RenderDrawPoint(win->ren, x, y);
		tex += tex_size;
		y++;
	}
	draw_floor(x, y, win);
}

void	line_draw(t_main *win, int i, float h, int tex)
{
	int wall_x;

	wall_x = 0;
	if (win->h_is)
		win->img.pos = (int)win->ray.h_dot.pix_x % CUBE;
	else if (win->v_is)
		win->img.pos = (int)win->ray.v_dot.pix_y % CUBE;
	draw(i, h, win, tex);
}
