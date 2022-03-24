/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_prep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:33:12 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/24 12:42:18 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_prep(t_fdf d)
{
	d.z = d.z_matrix[d.y_s][d.x_s];
	d.z1 = d.z_matrix[d.y_e][d.x_e];
	choose_color(&d);
	apply_zoom(&d);
	if (d.iso == 1)
	{
		isometric(&d.x_s, &d.y_s, d.z, &d);
		isometric(&d.x_e, &d.y_e, d.z1, &d);
	}
	d.xd = ft_abs(d.x_e - d.x_s);
	d.yd = ft_abs(d.y_e - d.y_s);
	draw_line(d, -1);
}

void	choose_color(t_fdf *d)
{
	if ((d->z != 0 || d->z1 != 0) && d->c_flag == 0)
		d->color = 0xFF2153;
	else if (d->c_matrix[d->y_s][d->x_s] != 7232896 && d->c_flag == 1)
		d->color = d->c_matrix[d->y_s][d->x_s];
	else if (d->c_matrix[d->y_e][d->x_e] != 7232896 && d->c_flag == 1)
		d->color = d->c_matrix[d->y_e][d->x_e];
	else
		d->color = 7232896;
}

void	apply_zoom(t_fdf *d)
{
	d->x_s = (d->x_s - (d->width / 2)) * d->zoom;
	d->x_e = (d->x_e - (d->width / 2)) * d->zoom;
	d->y_s = (d->y_s - (d->height / 2)) * d->zoom;
	d->y_e = (d->y_e - (d->height / 2)) * d->zoom;
}
