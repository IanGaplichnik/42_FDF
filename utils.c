/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:53:37 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/23 20:48:36 by igaplich         ###   ########.fr       */
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

int		ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	base(int c, int base)
{
	char	*str = "0123456789abcdef";
	char	*str2 = "0123456789ABCDEF";
	int		i = 0;

	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
	int	nb = 0;
	int	negatif = 0;
	int	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = 1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	if (negatif)
		return (-nb);
	return (nb);
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

