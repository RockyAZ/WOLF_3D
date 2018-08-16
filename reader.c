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

void	check_line(char *line)
{
	char *pos;

	pos = line;
	while (*pos != '\0')
	{
		if (!ft_isdigit(*pos) && *pos != 'P' && *pos != '\n' && *pos != ' ')
			error("invalid char somewhere  :<\n");
		pos++;
	}
}

void	valid(t_data *data, char *line)
{
	check_line(line);
	if (data->col != 0)
	{
		if (ft_count_words(line) != data->col || ft_count_words(line) > MAX_COL)
		{
			ft_putnbr(data->line);
			error("-error in line or too many column\n");
		}
	}
	else
		data->col = ft_count_words(line);
}

void	counter(t_data *data)
{
	char	*line;

	if ((data->fd = open(data->name, O_RDONLY)) < 0)
		error("open error 1\n");
	while (get_next_line(data->fd, &line) > 0)
	{
		valid(data, line);
		if (data->line > MAX_LINE)
			error("too many lines!\n");
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
}

void	reader(t_data *data)
{
	data->col = 0;
	data->line = 0;
	data->error = 1;
	data->pos[0] = -1;
	counter(data);
	if ((data->fd = open(data->name, O_RDONLY)) < 0)
		error("open error 2\n");
	data->map = (int**)malloc(sizeof(int*) * data->line);
	data_writer(data);
	if (data->pos[0] == -1)
		error("error 404: 'P'-(player position) not found...\n\
		OR YOU TRY TO OPEN DIR!!!\n");
	data->m_x = CUBE * data->col;
	data->m_y = CUBE * data->line;
	close(data->fd);
}
