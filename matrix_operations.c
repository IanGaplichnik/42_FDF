/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:53:45 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/24 20:18:02 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	create_matrix(t_fdf *d, int i)
{
	d->z_matrix = (int **)malloc((d->height + 1) * sizeof(int *));
	if (!d->z_matrix)
		error_print_exit("Error allocating z_matrix height");
	d->z_matrix[d->height] = NULL;
	while (i <= d->height)
	{
		d->z_matrix[i] = (int *)malloc((d->width) * sizeof(int));
		if (!d->z_matrix[i])
			error_print_exit("Error allocating z_matrix width");
			i++;
	}
}

void	create_color_matrix(t_fdf *d, int i)
{
	d->c_matrix = (int **)malloc((d->height + 1) * sizeof(char *));
	if (!d->c_matrix)
		error_print_exit("Error allocating c_matrix height");
	d->c_matrix[d->height] = NULL;
	while (i <= d->height)
	{
		d->c_matrix[i] = (int *)malloc((d->width) * sizeof(int));
		if (!d->c_matrix[i])
			error_print_exit("Error allocating c_matrix width");
		i++;
	}
}

void	init_color_matrix(t_fdf *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < d->height)
	{
		while (x < d->width)
		{
			d->c_matrix[y][x] = 7232896;
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_numbers_colors(t_fdf *d, char **numbers, int y)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (numbers[x])
	{
		d->z_matrix[y][x] = ft_atoi(numbers[x]);
		while (numbers[x][i] != 'x' && numbers[x][i] != '\0')
			i++;
		if (numbers[x][i++] == 'x')
		{
			d->c_matrix[y][x] = ft_atoi_base(&numbers[x][i], 16);
			d->c_flag = 1;
		}
		free(numbers[x]);
		i = 0;
		x++;
	}
}

void	fill_matrix(t_fdf *d, char *file, int fd)
{
	char	**numbers;
	char	*line;
	int		y;

	y = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_print_exit("Opening error");
	while (get_next_line(fd, &line))
	{
		numbers = ft_strsplit(line, ' ');
		fill_numbers_colors(d, numbers, y);
		y++;
		free(line);
		free(numbers);
	}
	close(fd);
}
