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


#include "wolf.h"
int		vertic_inter(t_main *win, float angle)
{
if (angle == win->gg.angle)
{
printf("--------------------------------\nangle:%f\n", angle);
}
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
if (angle == win->gg.angle)
{
printf("TAN:%f\n", ft_tan(angle));
printf("-->PIX_X::%f\n", win->ray.v_dot.pix_x);
printf("-->PIX_Y::%f\n", win->ray.v_dot.pix_y);
}
	win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
	win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
if (angle == win->gg.angle)
{
printf("VERTI_REAL:x::%d      y::%d\n", win->ray.v_dot.real_x, win->ray.v_dot.real_y);
}
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
if (angle == win->gg.angle)
{
printf("VAR_X::%f\n", win->ray.v_dot.var_x);
printf("VAR_Y::%f\n\n\n", win->ray.v_dot.var_y);
}
	while (win->data->map[win->ray.v_dot.real_y][win->ray.v_dot.real_x] == 0)
	{
		win->ray.v_dot.pix_y += win->ray.v_dot.var_y;
		win->ray.v_dot.pix_x += win->ray.v_dot.var_x;
		win->ray.v_dot.real_x = win->ray.v_dot.pix_x / CUBE;
		win->ray.v_dot.real_y = win->ray.v_dot.pix_y / CUBE;
		if (win->ray.v_dot.pix_y >= win->data->max_y || win->ray.v_dot.pix_y < 0)
			return (-1);
if (angle == win->gg.angle)
{
printf("-->PIX_X::%f\n", win->ray.v_dot.pix_x);
printf("-->PIX_Y::%f\n", win->ray.v_dot.pix_y);
printf("VERTIC_REAL:x::%d      y::%d\n", win->ray.v_dot.real_x, win->ray.v_dot.real_y);
}
	}
if (angle == win->gg.angle)
{	
printf("\n----------------------------------\n");
}
	return ((int)sqrt(powf(win->gg.posX - win->ray.v_dot.pix_x, 2) + powf(win->gg.posY - win->ray.v_dot.pix_y, 2)));
}

int		horiz_inter(t_main *win, float angle)
{
	printf("angle:%f\n", angle);
	if (angle == 180 || angle == 0)
	{
		printf("HORIZ_DONE\n");
		return (-1);
	}

	if (angle > 0 && angle < 180)
		win->ray.h_dot.pix_y = (win->gg.posY / CUBE) * CUBE - 1;
	else
		win->ray.h_dot.pix_y = (win->gg.posY / CUBE) * CUBE + CUBE;

	if (angle == 90 || angle == 270)
		win->ray.h_dot.pix_x = win->gg.posX;
	else
		win->ray.h_dot.pix_x = win->gg.posX + (win->gg.posY - win->ray.h_dot.pix_y) / ft_tan(angle);
		if (win->ray.h_dot.pix_x >= win->data->max_x || win->ray.h_dot.pix_x < 0)
		{
			printf("HORIZ_DONE\n");
			return (-1);
		}
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
		if (win->ray.h_dot.pix_x >= win->data->max_x || win->ray.h_dot.pix_x < 0)
		{
			printf("HORIZ_DONE\n");
			return (-1);
		}
	printf("-->PIX_X::%d\n", win->ray.h_dot.pix_x);
	printf("-->PIX_Y::%d\n", win->ray.h_dot.pix_y);
	printf("HORIZ_REAL:x::%d      y::%d\n", win->ray.h_dot.real_x, win->ray.h_dot.real_y);
	}
	printf("HOORIZON END\n");
	return ((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2)));
}



















==================================NORMAL===============================================
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
	return ((int)sqrt(powf(win->gg.posX - win->ray.h_dot.pix_x, 2) + powf(win->gg.posY - win->ray.h_dot.pix_y, 2)));
}