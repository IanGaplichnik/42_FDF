/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:07 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/23 20:39:13 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	drawing_algo(t_fdf *d, int *bits_p_p, int *size_line, int *endian)
{
	mlx_clear_window(d->mlx, d->win);
	d->img = mlx_new_image(d->mlx, WIN_WID, WIN_HEI);
	if (!d->img)
		error_print_exit("Error !d->img");
	d->addr = mlx_get_data_addr(d->img, bits_p_p, size_line, endian);
	if (!d->addr)
		error_print_exit("Error !d->addr");
	choose_points(d);
	positions_init(d);
	mlx_put_image_to_window(d, d->win, d->img, 0, 0);
	controls_print(d);
	mlx_destroy_image(d->mlx, d->img);
	d->img = NULL;
	d->addr = NULL;
	return (0);
}

void	choose_points(t_fdf *d)
{
	while (d->y_s < d->height)
	{
		while (d->x_s < d->width)
		{
			if (d->x_e < d->width)
				draw_prep(*d);
			d->x_e = d->x_s;
			d->y_e = d->y_s + 1;
			if (d->y_e < d->height)
				draw_prep(*d);
			d->x_s++;
			d->x_e = d->x_s + 1;
			d->y_e = d->y_s;
		}
		d->x_s = 0;
		d->x_e = 1;
		d->y_s++;
		d->y_e++;
	}
}

void	draw_line(t_fdf d, int i)
{
	int	err;
	int	x_dir;
	int	y_dir;
	int	e2;

	err = error_calc(d.xd, d.yd);
	x_dir = choose_direct(d.x_s, d.x_e);
	y_dir = choose_direct(d.y_s, d.y_e);
	while (++i < d.xd || i < d.yd)
	{
		if ((d.x_s + d.x_off) > 0 && (d.x_s + d.x_off) < WIN_WID
			&& d.y_s + d.y_off > 0 && (d.y_s + d.y_off < WIN_HEI))
			my_pixel_put(&d);
		e2 = err;
		if (e2 > -d.xd)
		{
			err -= d.yd;
			d.x_s += x_dir;
		}
		if (e2 < d.yd)
		{
			err += d.xd;
			d.y_s += y_dir;
		}
	}
}

void	my_pixel_put(t_fdf *d)
{
	char	*dst;

	dst = d->addr + ((d->y_s + d->y_off) * d->size_line
			+ (d->x_off + d->x_s) * (d->bits_p_p / 8));
	if (dst == NULL)
		error_print_exit("Error putting pixel");
	*(unsigned int *)dst = d->color;
}
