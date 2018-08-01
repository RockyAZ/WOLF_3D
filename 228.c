#include <stdio.h>
#include <math.h>
int main()
{
	int i = 0;

for (int i = 0; i <= 360; i++)
	printf("%d:::%f\n", i, tan((i * 2 * M_PI) / 360));
return 0;
}
//	printf("((%d - %d)^2 = %d) + ((%d - %d)^2 = %d)", win->gg.posX, win->ray.h_dot.pix_x, (win->gg.posX - win->ray.h_dot.pix_x) ^ 2, win->gg.posY, win->ray.h_dot.pix_y, (win->gg.posY - win->ray.h_dot.pix_y) ^ 2);

/*
#include "wolf.h"

int		vertic_inter(t_main *win, float angle)
{
	printf("angle:%f\n", angle);
	if (angle == 90 || angle == 270)
		return (-1);
	if (angle > 90 && angle < 270)
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE - 1;
	else
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE + CUBE;

	if (angle == 180 || angle == 0)
		win->ray.v_dot.pix_y = win->gg.posY;
	else
		if ((win->ray.v_dot.pix_y = win->gg.posY + (win->gg.posX - win->ray.v_dot.pix_x) * ft_tan(angle)) >= win->data->max_y)
			return (-1);
	printf("TAN:%f\n", ft_tan(angle));
	printf("-->PIX_X::%d\n", win->ray.v_dot.pix_x);
	printf("-->PIX_Y::%d\n", win->ray.v_dot.pix_y);

	win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
	win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;

	printf("VERTI_REAL:x::%d      y::%d\n", win->ray.v_dot.real_x, win->ray.v_dot.real_y);

	if (angle > 90 && angle < 270)
		win->ray.v_dot.var_x = -CUBE;
	else
		win->ray.v_dot.var_x = CUBE;
	if (angle == 180 || angle == 0)
		win->ray.v_dot.var_y = 0;
	else if (angle > 90 && angle < 270)
		win->ray.v_dot.var_y = (CUBE * ft_tan(angle)) * -1;
	else
		win->ray.v_dot.var_y = CUBE * ft_tan(angle);

	printf("VAR_X::%d\n", win->ray.v_dot.var_x);
	printf("VAR_Y::%d\n\n\n", win->ray.v_dot.var_y);

	while (win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x] == 0)
	{
		win->ray.v_dot.pix_y += win->ray.v_dot.var_y;

		win->ray.v_dot.pix_x += win->ray.v_dot.var_x;

		win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
		win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
	printf("-->PIX_X::%d\n", win->ray.v_dot.pix_x);
	printf("-->PIX_Y::%d\n", win->ray.v_dot.pix_y);
	printf("VERTIC_REAL:x::%d      y::%d\n", win->ray.v_dot.real_x, win->ray.v_dot.real_y);
	}
	printf("VERTIC END\n");
	return ((int)sqrt(powf(win->gg.posX - win->ray.v_dot.pix_x, 2) + powf(win->gg.posY - win->ray.v_dot.pix_y, 2)));
}

int		horiz_inter(t_main *win, float angle)
{
	printf("angle:%f\n", angle);
	if (angle == 180 || angle == 0)
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
	printf("TAN:%f\n", ft_tan(angle));
	printf("-->PIX_X::%d\n", win->ray.h_dot.pix_x);
	printf("-->PIX_Y::%d\n", win->ray.h_dot.pix_y);

	win->ray.h_dot.real_x = win->ray.h_dot.pix_x / CUBE;
	win->ray.h_dot.real_y = win->ray.h_dot.pix_y / CUBE;

	printf("HORIZ_REAL:x::%d      y::%d\n", win->ray.h_dot.real_x, win->ray.h_dot.real_y);

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
	printf("VAR_X::%d\n", win->ray.h_dot.var_x);
	printf("VAR_Y::%d\n\n\n", win->ray.h_dot.var_y);

	while (win->data->map[win->ray.h_dot.real_y][win->ray.h_dot.real_x] == 0)
	{
		win->ray.h_dot.pix_x += win->ray.h_dot.var_x;

		win->ray.h_dot.pix_y += win->ray.h_dot.var_y;

		win->ray.h_dot.real_x = win->ray.h_dot.pix_x / CUBE;
		win->ray.h_dot.real_y = win->ray.h_dot.pix_y / CUBE;
	printf("-->PIX_X::%d\n", win->ray.h_dot.pix_x);
	printf("-->PIX_Y::%d\n", win->ray.h_dot.pix_y);
	printf("HORIZ_REAL:x::%d      y::%d\n", win->ray.h_dot.real_x, win->ray.h_dot.real_y);
	}
	printf("HOORIZON END\n");
	return ((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2)));
}


void	ray_casting(t_main *win)
{
	int		i;
	float	angle = win->gg.angle;

	i = 0;
//	angle = win->gg.angle - (win->gg.fov / 2);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_LINES);
//	while (i < WIDTH)
//	{
//		line_draw(win, i, CUBE / ft_min(horiz_inter(win, angle), vertic_inter(win, angle)));

		printf("====\nV_return:%d\n", vertic_inter(win, 45));
		printf("====\nV_return:%d\n", vertic_inter(win, 135));
		printf("====\nV_return:%d\n", vertic_inter(win, 225));
		printf("====\nV_return:%d\n", vertic_inter(win, 315));
		
		// printf("H_return:%d\n", horiz_inter(win, angle));
		// printf("2:%f\n", win->gg.angle_size);
//		printf("3:%f\n", angle);
//		angle += win->gg.angle_size;
//		i++;
//	}
	glEnd();
}
8?
























==================================NORMAL===============================================



int		vertic_inter(t_main *win, float angle)
{
	if (angle == 90 || angle == 270)
		return (-1);
	if (angle > 90 && angle < 270)
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE - 1;
	else
		win->ray.v_dot.pix_x = (win->gg.posX / CUBE) * CUBE + CUBE;

	if (angle == 180 || angle == 0)
		win->ray.v_dot.pix_y = win->gg.posY;
	else
		if ((win->ray.v_dot.pix_y = win->gg.posY + (win->gg.posX - win->ray.v_dot.pix_x) * ft_tan(angle)) >= win->data->max_y)
			return (-1);
	win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
	win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
	if (angle > 90 && angle < 270)
		win->ray.v_dot.var_x = -CUBE;
	else
		win->ray.v_dot.var_x = CUBE;
	if (angle == 180 || angle == 0)
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
	// printf("VERIC_DONE\n");
	return ((int)sqrt(powf(win->gg.posX - win->ray.v_dot.pix_x, 2) + powf(win->gg.posY - win->ray.v_dot.pix_y, 2)));
}

int		horiz_inter(t_main *win, float angle)
{
	if (angle == 180 || angle == 0)
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
	// printf("HORIZ_DONE\n");
	return ((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2)));
}