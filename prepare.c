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
	win->gg.angle = 60;
	win->gg.fov = 60;
	win->gg.angle_size = (float)(win->gg.fov / WIDTH);
	win->gg.to_screen = (WIDTH / 2) / ft_tan(30);
	win->gg.speed = 5;
win->rotate = 2;
	printf("POS_X:%f         POS_Y:%f\n\n\n", win->gg.posX, win->gg.posY);
}

void	texture_prepare(t_main *win)
{
	win->img.tex[0] = stbi_load("./floor.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0);
	win->img.tex[1] = stbi_load("./WallPack/Flag5.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0);
	win->img.tex[2] = stbi_load("./neko.png", &win->img.width, &win->img.height, &win->img.nrChannel, 0);
	win->img.tex[3] = stbi_load("./WallPack/Black6.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0);
	win->img.tex[4] = stbi_load("./WallPack/White1.bmp", &win->img.width, &win->img.height, &win->img.nrChannel, 0);
	// printf("PICTURE_W:%d\nPICTURE_H:%d\nPICTURE_CHANNEL:%d\n", win->img.width, win->img.height, win->img.nrChannel);
	// for(int i = 0; i < 64 * 3; i += 3)
		// printf("R:%d  G:%d  B:%d\n", (int)win->img.black[i], (int)win->img.black[i + 1], (int)win->img.black[i + 2]);
}
