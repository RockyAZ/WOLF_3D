/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 15:58:37 by azaporoz          #+#    #+#             */
/*   Updated: 2018/08/09 15:58:38 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mouse_pos(t_main *win)
{
	static int	m;

	// if (win->keys.space)
	if (win->e.type == SDL_MOUSEMOTION)
	{
		if (!m)
		{
			win->m.x = win->e.motion.x;
			win->m.y = win->e.motion.y;
			m = 1;
		}
		win->gg.angle -= (win->e.motion.x - win->m.x) * 0.3;
		if (win->gg.angle >= 360)
			win->gg.angle -= 360;
		if (win->gg.angle < 0)
			win->gg.angle += 360;
		win->m.x = win->e.motion.x;
		win->m.y = win->e.motion.y;
	}
}
