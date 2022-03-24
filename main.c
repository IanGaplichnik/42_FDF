/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:53:23 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/24 15:05:41 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	error_print_exit(char *error_text)
{
	ft_putendl(error_text);
	exit(1);
}

void	positions_init(t_fdf *d)
{
	d->x_s = 0;
	d->x_e = 1;
	d->y_s = 0;
	d->y_e = 0;
}

void	params_init(t_fdf *d)
{
	d->width = 0;
	d->height = 0;
	d->z_matrix = NULL;
	d->x_off = WIN_WID / 2;
	d->y_off = WIN_HEI / 2;
	d->z_mult = 2;
	d->angle = 0.8;
	d->img = NULL;
	d->mlx = NULL;
	d->win = NULL;
	d->bits_p_p = 0;
	d->size_line = 0;
	d->endian = 0;
	d->iso = 0;
	d->mouse_press = 0;
	d->c_flag = 0;
}

void	mlx_first_call(t_fdf *d)
{
	d->zoom = (WIN_HEI / (d->width + d->height));
	d->mlx = mlx_init();
	if (!d->mlx)
		error_print_exit("Error !d->mlx");
	d->win = mlx_new_window(d->mlx, WIN_WID, WIN_HEI, "mlx 42");
	if (!d->win)
		error_print_exit("Error !d->win");
}

int	main(int argc, char **argv)
{
	t_fdf	*d;

	if (argc != 2)
		error_print_exit("Usage: ./fdf %map_name%");
	d = (t_fdf *)malloc(sizeof(t_fdf));
	if (!d)
		error_print_exit("Error allocating struct");
	positions_init(d);
	params_init(d);
	file_operations(d, argv[1]);
	mlx_first_call(d);
	drawing_algo(d, &d->bits_p_p, &d->size_line, &d->endian);
	controls_call(d);
	mlx_loop(d->mlx);
	return (0);
}
