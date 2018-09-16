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

void	data_preparation(t_data *data)
{
	data->col = 0;
	data->line = 0;
	data->error = 1;
	data->pos[0] = -1;
}

void	counter(t_data *data)
{
	char	*line;
	int		i;

	data_preparation(data);
	i = 0;
	if ((data->fd = open(data->name, O_RDONLY)) < 0)
		error("open error 1\n");
	while (get_next_line(data->fd, &line) > 0)
	{
		if (data->col != 0)
		{
			if (ft_count_words(line) != data->col)
			{
				ft_putnbr(i);
				error("-invalid number of chars in line\n");
			}
		}
		else
			data->col = ft_count_words(line);
		data->line++;
		free(line);
	}
	close(data->fd);
}

void	data_writer(t_data *data)
{
	char	**arr;
	char	*line;
	int		i;
	int		j;

	i = 0;
	while ((data->error == get_next_line(data->fd, &line)) == 1)
	{
		arr = ft_strsplit(line, ' ');
		j = -1;
		data->map[i] = (int*)malloc(sizeof(int) * data->col);
		while (arr[++j])
		{
			if (arr[j][0] == 'P')
			{
				data->pos[0] = j;
				data->pos[1] = i;
				data->map[i][j] = 0;
			}
			else
				data->map[i][j] = ft_atoi(arr[j]);
		}
		ft_arrr_del(arr, line);
		i++;
	}
	if (data->error == -1 || i == 0)
		error("dont't mess with directores!!!\n>:(\n");
}

void	reader(t_data *data)
{
	counter(data);
	if ((data->fd = open(data->name, O_RDONLY)) < 0)
		error("open error 2\n");
	data->map = (int**)malloc(sizeof(int*) * data->line);
	data_writer(data);
	if (data->pos[0] == -1)
		error("error 404: 'P' not found\n");
	data->m_x = CUBE * data->col;
	data->m_y = CUBE * data->line;
	// print_coord(data);
	close(data->fd);
}
