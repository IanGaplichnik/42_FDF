/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:34:25 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/24 18:38:48 by igaplich         ###   ########.fr       */
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
