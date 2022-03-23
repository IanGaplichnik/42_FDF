/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:22:02 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/23 20:25:48 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	file_operations(t_fdf *d, char *file)
{
	read_height_width(file, d);
	create_matrix(d, 0);
	create_color_matrix(d, 0);
	init_color_matrix(d);
	fill_matrix(d, file, 0);
}

void	read_height_width(char *file, t_fdf *d)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_print_exit("Error reading");
	while (get_next_line(fd, &line))
	{
		read_width(line, d, -1, 0);
		d->height += 1;
		free(line);
	}
	if (d->height == 0)
		error_print_exit("Empty file");
	close(fd);
}

void	read_width(char *line, t_fdf *d, int i, int width)
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
	if (d->height == 0)
		d->width = width;
	else if (d->width != width)
		error_print_exit("Map lines have different length");
	if (d->width == 0)
		error_print_exit("Empty file");
}
