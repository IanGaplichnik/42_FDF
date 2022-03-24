/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:53:37 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/24 14:44:47 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	choose_direct(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	return (-1);
}

int	error_calc(int xd, int yd)
{
	if (xd > yd)
		return (xd / 2);
	return (-yd / 2);
}

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
}

int	close_fdf(t_fdf *d)
{
	int	y;

	y = 0;
	free(d->addr);
	while (y < d->height)
	{
		free(d->z_matrix[y]);
		y++;
	}
	/* system("leaks fdf"); */
	exit(0);
	return (0);
}
