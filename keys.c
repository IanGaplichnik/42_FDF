/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:46:06 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/21 20:09:10 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	close_fdf(t_fdf *data)
{
	(void)data;
	exit(0);
	return (0);
}

int	key_press(int key, t_fdf *data)
{
	if (key == 53)
		close_fdf(data);
	if (key == 126)
		data->y_off -= 15;
	if (key == 125)
		data->y_off += 15;
	if (key == 123)
		data->x_off -= 15;
	if (key == 124)
		data->x_off += 15;
	if (key == 69)
		data->zoom += 1;
	if (key == 78)
		data->zoom -= 1;
	if (key == 91)
		data->z_mult++;
	if (key == 87)
		data->z_mult--;
	if (key == 89)
		data->angle -= 0.1;
	if (key == 92)
		data->angle += 0.1;
	draw(data, &data->bits_p_p, &data->size_line, &data->endian);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	data->mouse_press = 1;
	if (button == 4)
		data->zoom += 1;
	if (button == 5)
		data->zoom -= 1;
	draw(data, &data->bits_p_p, &data->size_line, &data->endian);
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	(void)button;
	if (data->mouse_press == 1)
		data->mouse_press = 0;
	draw(data, &data->bits_p_p, &data->size_line, &data->endian);
	return (0);
}

void	controls_call(t_fdf *data)
{
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 17, 0, close_fdf, data);
	mlx_hook(data->win, 4, 0, mouse_press, data);
	mlx_hook(data->win, 5, 0, mouse_release, data);
}
