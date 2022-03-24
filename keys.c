/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:46:06 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/24 15:05:40 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	key_press(int key, t_fdf *d)
{
	if (key == 53)
		close_fdf(d);
	if (key == 126)
		d->y_off -= 15;
	if (key == 125)
		d->y_off += 15;
	if (key == 123)
		d->x_off -= 15;
	if (key == 124)
		d->x_off += 15;
	if (key == 69)
		d->zoom += 1;
	if (key == 78)
		d->zoom -= 1;
	if (key == 91)
		d->z_mult++;
	key_press_others(key, d);
	drawing_algo(d, &d->bits_p_p, &d->size_line, &d->endian);
	return (0);
}

int	key_press_others(int key, t_fdf *d)
{
	if (key == 87)
		d->z_mult--;
	if (key == 89)
		d->angle -= 0.1;
	if (key == 92)
		d->angle += 0.1;
	if (key == 35)
	{
		if (d->iso == 0)
			d->iso = 1;
		else
			d->iso = 0;
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_fdf *d)
{
	(void)x;
	(void)y;
	d->mouse_press = 1;
	if (button == 4)
		d->zoom += 1;
	if (button == 5)
		d->zoom -= 1;
	if (button == 1)
	{
		d->x_off = WIN_WID / 2;
		d->y_off = WIN_HEI / 2;
	}
	if (button == 2)
		d->zoom = (WIN_HEI / (d->width + d->height));
	drawing_algo(d, &d->bits_p_p, &d->size_line, &d->endian);
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *d)
{
	(void)x;
	(void)y;
	(void)button;
	if (d->mouse_press == 1)
		d->mouse_press = 0;
	drawing_algo(d, &d->bits_p_p, &d->size_line, &d->endian);
	return (0);
}

void	controls_call(t_fdf *d)
{
	mlx_hook(d->win, 2, 0, key_press, d);
	mlx_hook(d->win, 17, 0, close_fdf, d);
	mlx_hook(d->win, 4, 0, mouse_press, d);
	mlx_hook(d->win, 5, 0, mouse_release, d);
}
