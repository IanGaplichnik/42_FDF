/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:15:07 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/22 14:37:08 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	controls_print(t_fdf *data)
{
	int	y;

	y = 0;
	mlx_string_put(data->mlx, data->win, 20, y += 25, 0xEAEAEA,
		"Controls (tip - you can press and hold 1 button at a time):");
	mlx_string_put(data->mlx, data->win, 20, y += 25, 0xEAEAEA,
		"Arrows = move picture up/down/right/left");
	mlx_string_put(data->mlx, data->win, 20, y += 25, 0xEAEAEA,
		"Num 8 / Num 5 = increase/decrease the height of non-0 points");
	mlx_string_put(data->mlx, data->win, 20, y += 25, 0xEAEAEA,
		"Num 7 / Num 9 = change the projection angle");
	mlx_string_put(data->mlx, data->win, 20, y += 25, 0xEAEAEA,
		"Num + / Num - / Wheel Up / Wheel Down = Zoom In / Zoom Out");
	mlx_string_put(data->mlx, data->win, 20, y += 25, 0xEAEAEA,
		"Left mouse click = Place back to center");
	mlx_string_put(data->mlx, data->win, 20, y += 25, 0xEAEAEA,
		"Right mouse click = Set to initial zoom");
}

int	draw(t_fdf *data, int *bits_p_p, int *size_line, int *endian)
{
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, WIN_WID, WIN_HEI);
	data->addr = mlx_get_data_addr(data->img, bits_p_p, size_line, endian);
	draw_points(data);
	positions_init(data);
	mlx_put_image_to_window(data, data->win, data->img, 0, 0);
	controls_print(data);
	mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
	data->addr = NULL;
	return (0);
}

void	draw_points(t_fdf *data)
{
	while (data->y_s < data->height)
	{
		while (data->x_s < data->width)
		{
			if (data->x_e < data->width)
				draw_prep(*data);
			data->x_e = data->x_s;
			data->y_e = data->y_s + 1;
			if (data->y_e < data->height)
				draw_prep(*data);
			data->x_s++;
			data->x_e = data->x_s + 1;
			data->y_e = data->y_s;
		}
		data->x_s = 0;
		data->x_e = 1;
		data->y_s++;
		data->y_e++;
	}
}

void	draw_prep(t_fdf data)
{
	data.z = data.z_matrix[data.y_s][data.x_s];
	data.z1 = data.z_matrix[data.y_e][data.x_e];
	if (data.z_matrix[data.y_s][data.x_s] == 0
			&& data.z_matrix[data.y_e][data.x_e] == 0)
		data.color = 0x6e5d80;
	else
		data.color = 0xff4173;
	data.x_s = (data.x_s - (data.width / 2)) * data.zoom;
	data.x_e = (data.x_e - (data.width / 2)) * data.zoom;
	data.y_s = (data.y_s - (data.height / 2)) * data.zoom;
	data.y_e = (data.y_e - (data.height / 2)) * data.zoom;
	isometric(&data.x_s, &data.y_s, data.z, &data);
	isometric(&data.x_e, &data.y_e, data.z1, &data);
	data.xd = ft_abs(data.x_e - data.x_s);
	data.yd = ft_abs(data.y_e - data.y_s);
	draw_line(data, -1);
}

void	draw_line(t_fdf data, int i)
{
	int	err;
	int	x_dir;
	int	y_dir;
	int	e2;

	err = error_calc(data.xd, data.yd);
	x_dir = choose_direct(data.x_s, data.x_e);
	y_dir = choose_direct(data.y_s, data.y_e);
	while (++i < data.xd || i < data.yd)
	{
		if ((data.x_s + data.x_off) > 0 && (data.x_s + data.x_off) < WIN_WID
			&& data.y_s + data.y_off > 0 && (data.y_s + data.y_off < WIN_HEI))
			my_pixel_put(&data);
		e2 = err;
		if (e2 > -data.xd)
		{
			err -= data.yd;
			data.x_s += x_dir;
		}
		if (e2 < data.yd)
		{
			err += data.xd;
			data.y_s += y_dir;
		}
	}
}

void	my_pixel_put(t_fdf *data)
{
	char	*dst;

	dst = data->addr + ((data->y_s + data->y_off) * data->size_line
			+ (data->x_off + data->x_s) * (data->bits_p_p / 8));
	*(unsigned int *)dst = data->color;
}
