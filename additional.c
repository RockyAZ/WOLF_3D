/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:23:00 by azaporoz          #+#    #+#             */
/*   Updated: 2018/07/23 19:23:00 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

float	ft_tan(float angle)
{
	return(tan((angle * 2 * M_PI) / 360));
}

float	ft_cos(float angle)
{
	return(cos((angle * 2 * M_PI) / 360));
}

float	ft_sin(float angle)
{
	return(sin((angle * 2 * M_PI) / 360));
}

void	ft_arrr_del(char **arr, char *line)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(line);
}

void	print_coord(t_data *data)
{
	int i = 0;
	int j = 0;

	while (i < data->line)
	{
		j = 0;
		while (j < data->col)
		{
			printf("%d   ", data->map[i][j]);
			j++;
		}
		i++;
		printf("\n\n");
	}
		printf("MAX_X::%d\nMAX_Y::%d\n", data->max_x, data->max_y);
		printf("PLAYER_X::%f\nPLAYER_Y::%f\n\n\n", data->pos[0],data->pos[1]);
}
