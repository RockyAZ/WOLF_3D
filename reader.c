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

void	counter(t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	data->col = 0;
	data->line = 0;
	i = 0;
	if ((fd = open(data->name, O_RDONLY)) < 0)
		error("open error 1\n");
	while (get_next_line(fd, &line) > 0)
	{
		if (data->col != 0)
		{
			if (ft_count_words(line) != data->col)
			{
				ft_putstr("invalid number of chars in line:");
				ft_putnbr(i);
				error(">:(\n");
			}
		}
		else
			data->col = ft_count_words(line);
		data->line++;
		free(line);
	}
	close(fd);
}

void	reader(t_data *data)
{
	char	**arr;
	char	*line;
	int		i;
	int		j;
	int		fd;

	counter(data);
	if ((fd = open(data->name, O_RDONLY)) < 0)
		error("open error 2\n");
	data->map = (int**)malloc(sizeof(int*) * data->line);
	i = 0;
	while (get_next_line(fd, &line))
	{
		arr = ft_strsplit(line, ' ');
		j = 0;
		data->map[i] = (int*)malloc(sizeof(int) * data->col);
		while (arr[j])
		{
			data->map[i][j] = ft_atoi(arr[j]);
			j++;
		}
		free(line);
		ft_arrr_del(arr);
		i++;
	}
	print_coord(data);
	close(fd);
}
