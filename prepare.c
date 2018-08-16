/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:06:16 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/30 13:06:16 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	main_prepare(int ac, char **av, t_main **win)
{
	t_main *cp_win;

	if (ac != 2)
		error("number of arguments error\n");
	if (!(cp_win = (t_main*)malloc(sizeof(t_main))))
		error("main malloc error\n");
	cp_win->data = (t_data*)malloc(sizeof(t_data));
	cp_win->data->name = av[1];
	cp_win->keys.right = 0;
	cp_win->keys.left = 0;
	cp_win->keys.up = 0;
	cp_win->keys.down = 0;
	cp_win->keys.w = 0;
	cp_win->keys.s = 0;
	cp_win->keys.a = 0;
	cp_win->keys.d = 0;
	cp_win->keys.shift = 0;
	cp_win->m.x = 0;
	cp_win->m.y = 0;
	*win = cp_win;
}

void	ray_player_prepare(t_main *win)
{
	win->gg.posX = (win->data->pos[0] * (float)CUBE) + ((float)CUBE / (float)2);
	win->gg.posY = (win->data->pos[1] * (float)CUBE) + ((float)CUBE / (float)2);
	win->gg.angle = 270;
	win->gg.fov = 60;
	win->gg.angle_size = (float)(win->gg.fov / WIDTH);
	win->gg.to_screen = (WIDTH / 2) / ft_tan(30);
	win->gg.speed = 5;
	win->gg.height = 32;
	win->rotate = 2;
	printf("POS_X:%f         POS_Y:%f\n\n\n", win->gg.posX, win->gg.posY);
}

void	texture_prepare(t_main *win)
{
	if (!(win->img.tex[0] = stbi_load("./tex/floor.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[0] open error D:\n");
	if (!(win->img.tex[1] = stbi_load("./tex/Flag4.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[1] open error D:\n");
	if (!(win->img.tex[2] = stbi_load("./tex/neko.png", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[2] open error D:\n");
	if (!(win->img.tex[3] = stbi_load("./tex/Silver3.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[3] open error D:\n");
	if (!(win->img.tex[4] = stbi_load("./tex/White1.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[4] open error D:\n");
	if (!(win->img.tex[5] = stbi_load("./tex/mand1.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[5] open error D:\n");
	if (!(win->img.tex[6] = stbi_load("./tex/mand2.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[6] open error D:\n");
	if (!(win->img.tex[7] = stbi_load("./tex/mand3.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[7] open error D:\n");
	if (!(win->img.tex[8] = stbi_load("./tex/mand4.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0)))
		error("texture[8] open error D:\n");
}
