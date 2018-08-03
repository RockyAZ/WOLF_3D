/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:34:28 by azaporoz          #+#    #+#             */
/*   Updated: 2018/08/03 16:34:29 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "wolf.h"

void	active_keys(t_main *win)
{
	win->gg.r_x = win->gg.posX / 64;
	win->gg.r_y = win->gg.posY / 64;
	if (win->keys.right)
	{
		win->gg.angle -= win->rotate;
		if (win->gg.angle > 360)
			win->gg.angle -= 360;
	}
	if (win->keys.left)
	{
		win->gg.angle += win->rotate;
		if (win->gg.angle < 0)
			win->gg.angle += 360;
	}
	if (win->keys.up)
	{
		win->gg.posX += 15 * ft_cos(win->gg.angle);
		win->gg.posY += 15 * (ft_sin(win->gg.angle) * -1);
	}
	if (win->keys.down)
	{
		win->gg.posX -= 15 * ft_cos(win->gg.angle);
		win->gg.posY -= 15 * (ft_sin(win->gg.angle) * -1);
	}
}
