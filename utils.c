/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:53:37 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/24 20:17:58 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(int *x, int *y, float z, t_fdf *d)
{
	*x = ((*x - *y) * cos(d->angle));
	*y = ((*x + *y) * sin(d->angle) - (z * d->z_mult));
}

void	controls_print(t_fdf *d)
{
	int	y;

	y = 0;
	mlx_string_put(d->mlx, d->win, 20, y += 25, 0xEAEAEA,
		"Controls (tip - you can press and hold 1 button at a time):");
	mlx_string_put(d->mlx, d->win, 20, y += 25, 0xEAEAEA,
		"Arrows = move picture up/down/right/left");
	mlx_string_put(d->mlx, d->win, 20, y += 25, 0xEAEAEA,
		"Num 8 / Num 5 = increase/decrease the height of non-0 points");
	mlx_string_put(d->mlx, d->win, 20, y += 25, 0xEAEAEA,
		"Num 7 / Num 9 = change the projection angle");
	mlx_string_put(d->mlx, d->win, 20, y += 25, 0xEAEAEA,
		"Num + / Num - / Wheel Up / Wheel Down = Zoom In / Zoom Out");
	mlx_string_put(d->mlx, d->win, 20, y += 25, 0xEAEAEA,
		"Left mouse click = Place back to center");
	mlx_string_put(d->mlx, d->win, 20, y += 25, 0xEAEAEA,
		"Right mouse click = Set to initial zoom");
	mlx_string_put(d->mlx, d->win, 20, y += 25, 0xEAEAEA,
		"p = change projection");
	if (d->iso == 1)
		mlx_string_put(d->mlx, d->win, (WIN_WID / 2) - 100, 20, 0xEAEAEA,
			"Isometric Projection");
	else
		mlx_string_put(d->mlx, d->win, (WIN_WID / 2) - 80, 20, 0xEAEAEA,
			"Plain Projection");
}

int	close_fdf(t_fdf *d)
{
	(void)d;
	exit(0);
	return (0);
}
