/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:13:43 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/23 18:13:44 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	reader(t_data *data)
{
	char	*arr;
	char	*line;
	int i;
	int j;
	int fd;

	if (((win->fd = open(win->name, O_RDONLY)) < 0) || !(count_line(win)))
		error('o');

}