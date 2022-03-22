/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:53:23 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/22 14:35:09 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	error_print_exit(char *error_text)
{
	ft_putendl(error_text);
	exit(1);
}

void	positions_init(t_fdf *data)
{
	data->x_s = 0;
	data->x_e = 1;
	data->y_s = 0;
	data->y_e = 0;
}

void	first_init(t_fdf *data)
{
	data->width = 0;
	data->height = 0;
	data->z_matrix = NULL;
	data->x_off = WIN_WID / 2;
	data->y_off = WIN_HEI / 2;
	data->z_mult = 2;
	data->angle = 0.8;
	data->img = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->bits_p_p = 0;
	data->size_line = 0;
	data->endian = 0;
	data->iso = 0;
	data->mouse_press = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		error_print_exit("Usage: ./fdf %map_name%");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		error_print_exit("Error allocating struct");
	positions_init(data);
	first_init(data);
	reading_file(data, argv[1]);
	data->zoom = WIN_HEI / (data->width + data->height);
	data->mlx = mlx_init();
	if (!data->mlx)
		error_print_exit("Error !data->mlx");
	data->win = mlx_new_window(data->mlx, WIN_WID, WIN_HEI, "mlx 42");
	draw(data, &data->bits_p_p, &data->size_line, &data->endian);
	controls_call(data);
	mlx_loop(data->mlx);
	return (0);
}
