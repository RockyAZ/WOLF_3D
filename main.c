/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:30:39 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/23 17:30:40 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_main		*win;

	main_prepare(ac, av, &win);
	reader(win->data);
	SDL_Init(SDL_INIT_VIDEO);
	win->win = SDL_CreateWindow("WOLF_SDL", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	win->ren = SDL_CreateRenderer(win->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// SDL_SetHint(SDL_HINT_RENDER_VSYNC, "0");
	
	texture_prepare(win);
	ray_player_prepare(win);
	ray_casting(win);
int i = 0;
	while (!win->quit)
	{
		win->fps = SDL_GetTicks();
		SDL_SetRenderDrawColor(win->ren, 0, 0, 0, 0);
		SDL_RenderClear(win->ren);
		event_callback(win);
		active_keys(win);
		ray_casting(win);
		// if (i++ % 70 == 0)
			printf("FPS:%d\n", 1000 /(SDL_GetTicks() - win->fps));
		SDL_RenderPresent(win->ren);
	}
	SDL_DestroyRenderer(win->ren);
	SDL_DestroyWindow(win->win);
	SDL_Quit();
}
