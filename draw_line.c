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

// void	draw_floor(int x, int y, t_main *win, int color, int wallX)
// {
// 	float floorXWall;
// 	float floorYWall;

// 	if (win->ray.side == 0 && (win->angle <= 90 || win->angle >= 270))
// 	{
// 		floorXWall = win->ray.mapX;
// 		floorYWall = win->ray.mapY + wallX;
// 	}
// 	else if (win->ray.side == 0 && (win->angle >= 90 && win->angle <= 270))
// 	{
// 		floorXWall = win->ray.mapX + 64;
// 		floorYWall = win->ray.mapY + wallX;
// 	}
// 	else if (win->ray.side == 1 && (win->angle >= 180 && win->angle < 360))
// 	{
// 		floorXWall = win->ray.mapX + wallX;
// 		floorYWall = win->ray.mapY;
// 	}
// 	else
// 	{
// 		floorXWall = win->ray.mapX + wallX;
// 		floorYWall = win->ray.mapY + 64;
// 	}
// 	if (win->huy == 1)
// 	{
// 		printf("GG_X:%d\nGG_Y%d\n\n", (int)win->gg.posX / CUBE, (int)win->gg.posY / CUBE);
// 		printf("AANNGGLLEE:::%f\n", win->angle);
// 		printf("wallX:%d\n", wallX);
// 		// printf("floorXWall::%f\nfloorYWall::%f\n\n\n", floorXWall, floorYWall);
// 		printf("DISTANCE:%d\n", win->ray.dist);
// 	}
// 	while (y < HEIGHT)
// 	{
// 		double currentDist = HEIGHT / (64.0 * y - HEIGHT);
// 		float weight = currentDist / win->ray.dist;
// 		// double currentFloorX = weight * floorXWall + (64.0 - weight) * win->gg.posX;//хуевый
//         // double currentFloorY = weight * floorYWall + (64.0 - weight) * win->gg.posY;
// 		double currentFloorX = weight + (64.0 - weight) * win->gg.posX;//хуевый
//         double currentFloorY = weight + (64.0 - weight) * win->gg.posY;

// 		int floorTexX, floorTexY;
//         floorTexX = (int)(currentFloorX * CUBE) % CUBE;//хуевый
//         floorTexY = (int)(currentFloorY * CUBE) % CUBE;
// 		int i = get_color(floorTexX, floorTexY, win);
		
// if (win->huy == 1 && y == HEIGHT - 2)
// 	printf("+++++++\nY::::%d\ncurrentDist:%f\n weight:%f\n currentFloorX:%f\n currentFloorY:%f\nfloorTexX:%d\n floorTexY:%d\nI:::%d\n+++++++\n\n", y, currentDist, weight, currentFloorX, currentFloorY, floorTexX, floorTexY, i);
// 		glColor3ub((int)win->img.tex[0][i], (int)win->img.tex[0][i + 1], (int)win->img.tex[0][i + 2]);
// 		glVertex2d(x, y);
// 		y++;
// 	}
// }


// void	draw_floor(int x, int y, t_main *win, int color, int wallX)
// {
// 	float floorXWall;
// 	float floorYWall;

// 	if (win->huy == 1)
// 	{
// 	printf("GG_X:%d\nGG_Y%d\n\n", (int)win->gg.posX / CUBE, (int)win->gg.posY / CUBE);
// 	printf("wallX:%d\n", wallX);
// 	printf("floorXWall::%f\nfloorYWall::%f\n\n\n", floorXWall, floorYWall);
// 	printf("DISTANCE:%d\n", win->ray.dist);
// 	}
// 	int i;
// 	int nx,ny;
// 	double floorPointDistance;

// 	while (y < HEIGHT)
// 	{
// 		floorPointDistance = ((win->gg.height * win->gg.to_screen) / ((64 / 2) - y)) / ft_sin(win->gg.angle + win->angle);
// 		nx = ft_abs((-floorPointDistance * ft_sin(win->angle)) + win->gg.posX) % 64;
// 		ny = ft_abs((floorPointDistance * ft_cos(win->angle)) + win->gg.posY) % 64;
// 		i = get_color(nx, ny, win);
// 		if (win->huy == 1 && y == 1078)
// 		printf("minidistance:%f\nnx:%d\nny:%d\nI:%d\n\n", floorPointDistance, nx, ny, i);
// 		glColor3ub((int)win->img.tex[0][i], (int)win->img.tex[0][i + 1], (int)win->img.tex[0][i + 2]);
// 		glVertex2d(x, y);
// 		y++;
// 	}
// }

// void	draw_floor(int x, int y, t_main *win, int color, int wallX)
// {
// 	float floorXWall;
// 	float floorYWall;

// 	// if (win->huy == 1)
// 	// {
// 	// printf("GG_X:%d\nGG_Y%d\n\n", (int)win->gg.posX / CUBE, (int)win->gg.posY / CUBE);
// 	// printf("wallX:%d\n", wallX);
// 	// printf("floorXWall::%f\nfloorYWall::%f\n\n\n", floorXWall, floorYWall);
// 	// printf("DISTANCE:%d\n", win->ray.dist);
// 	// }


// 	int i;
// 	double floorCastingStartPixel = HEIGHT / 2;
// 	int nx,ny;
// 	double distance;

// 	while (y < HEIGHT)
// 	{
// 		distance = (float)(((float)win->gg.height / (y - (HEIGHT / 2))) * win->gg.to_screen);
// 		nx = ((int)distance * ft_cos(win->angle)) + win->gg.posX;
// 		ny = ((int)distance * ft_sin(win->angle)) + win->gg.posY;
// 		i = get_color(nx, ny, win);
// 		// printf("%f\n", distance);
// 		// if (win->huy == 1 && y == 1078)
// 		// printf("minidistance:%f\nnx:%d\nny:%d\nI:%d\n\n", distance, nx, ny, i);
// 		glColor3ub((int)win->img.tex[0][i], (int)win->img.tex[0][i + 1], (int)win->img.tex[0][i + 2]);
// 		glVertex2d(x, y);
// 		y++;
// 	}
// 	// exit(0);
// }

// void	draw_floor(int x, int y, t_main *win, int color, int wallX)
// {

// 	if (win->huy == 1)
// 	{
// 	printf("GG_X:%d\nGG_Y%d\n\n", (int)win->gg.posX / CUBE, (int)win->gg.posY / CUBE);
// 	printf("angle:::%f\n", win->gg.angle);
// 	printf("wallX:%d\n", wallX);
// 	// printf("floorXWall::%f\nfloorYWall::%f\n\n\n", floorXWall, floorYWall);
// 	printf("DISTANCE:%d\n", win->ray.dist);
// 	}

// 	float column_angle = atan((float) (x - (WIDTH/2) ) / HEIGHT);
// 	float rayangle = win->gg.angle + column_angle;
// 	float distance;

// 	int nx;
// 	int ny;

// 	int i;
// 	while (y < HEIGHT)
// 	{
// 		distance = ((float)win->gg.height / (y - HEIGHT / 2)) * win->gg.to_screen * ft_cos(column_angle);
// 		nx = -distance * (ft_sin(win->angle));
// 		ny = distance * (ft_cos(win->angle));

// 		nx += win->gg.posX;
// 		ny += win->gg.posY;

// 		nx = nx >> 6;
// 		ny = ny >> 6;
// 		nx &= 63;
// 		ny &= 63;
// 		if (win->huy == 1 && y == 1078)
// 		printf("minidistance:%f\nnx:%d\nny:%d\nI:%d\n\n", distance, nx, ny, i);
// 		i = get_color(nx, ny, win);
// 		glColor3ub((int)win->img.tex[0][i], (int)win->img.tex[0][i + 1], (int)win->img.tex[0][i + 2]);
// 		glVertex2d(x, y);	
// 		y++;	
// 	}

// }

void	draw_floor(int x, int y, t_main *win)
{
	float dist;

	while (y < HEIGHT)
	{
		dist = ((float)win->gg.height / ((float)y - (float)CENTR_H) * win->gg.to_screen) / ft_cos(win->angle - win->gg.angle);
		printf("H:%d\nY:%d\nCENTER:%d\nS:%f\nft_cos:%f\nDIST::::::::%f\n\n", win->gg.height, y, CENTR_H, win->gg.to_screen, ft_cos(win->angle - win->gg.angle), dist);
	// if (win->huy == 1)
		// printf("%f\n", dist);
		y++;
	}
	// if (win->huy == 1)	
	exit(0);
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
	if (win->huy == 1)
	draw_floor(x, y, win);

}

void	line_draw(t_main *win, int i, float h, int tex, int wallX)
{
	win->img.pos = wallX % CUBE;
	if (win->huy == 1)
		printf("MAIN_HEIGHT::%f\n", h);
	// if (color == 1)
	// 	glColor3ub(0, 254, 0);
	// else if (color == 2)
	// 	glColor3ub(254, 0, 0);
	// else if (color == 3)
	// 	glColor3ub(0, 0, 254);
	// draw(i, CENTR_H + h / 2, i, CENTR_H - h / 2, win, color);
	draw(i, h, win, tex, wallX);
}