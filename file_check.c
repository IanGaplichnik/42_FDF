/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:53:45 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/21 13:10:19 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	reading_file(t_fdf *data, char *file)
{
	read_height_width(file, data);
	create_matrix(data, 0);
	fill_matrix(data, file, 0);
}

void	read_height_width(char *file, t_fdf *data)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_print_exit("Error reading");
	while (get_next_line(fd, &line))
	{
		read_width(line, data, -1, 0);
		data->height += 1;
		free(line);
	}
	close(fd);
}

void	read_width(char *line, t_fdf *data, int i, int width)
{
	int	inside;

	inside = 0;
	while (line[++i])
	{
		if (inside && line[i] == ' ')
			inside = 0;
		if (!inside && line[i] != ' ')
		{
			inside++;
			width++;
		}
	}
	if (data->height == 0)
		data->width = width;
	else if (data->width != width)
		error_print_exit("Map lines have different length");
}

void	create_matrix(t_fdf *data, int i)
{
	data->z_matrix = (int **)malloc((data->height + 1) * sizeof(int *));
	if (!data->z_matrix)
		error_print_exit("Error allocating z_matrix height");
	data->z_matrix[data->height] = NULL;
	while (i <= data->height)
	{
		data->z_matrix[i] = (int *)malloc((data->width) * sizeof(int));
		if (!data->z_matrix[i])
			error_print_exit("Error allocating z_matrix width");
		i++;
	}
}

void	fill_matrix(t_fdf *data, char *file, int fd)
{
	char	**numbers;
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_print_exit("Opening error");
	while (get_next_line(fd, &line))
	{
		numbers = ft_strsplit(line, ' ');
		while (numbers[x])
		{
			data->z_matrix[y][x] = ft_atoi(numbers[x]);
			free(numbers[x]);
			x++;
		}
		x = 0;
		y++;
		free(line);
	}
	close(fd);
}
