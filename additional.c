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

void	ft_arrr_del(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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
}