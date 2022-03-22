/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:54:08 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/22 14:07:13 by igaplich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIN_HEI	1440
# define WIN_WID	2560

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_p_p;
	char	*addr;
	int		size_line;
	int		endian;

	int		width;
	int		height;
	int		**z_matrix;

	int		x_s;
	int		x_e;
	int		y_s;
	int		y_e;
	int		x_off;
	int		y_off;
	int		z;
	int		z1;
	int		z_mult;
	float	angle;
	int		iso;
	int		xd;
	int		yd;
	int		zoom;
	int		color;
	int		mouse_press;
}	t_fdf;

void	error_print_exit(char *error_text);
void	reading_file(t_fdf *data, char *file);
void	read_height_width(char *file, t_fdf *data);
void	read_width(char *line, t_fdf *data, int i, int width);
void	create_matrix(t_fdf *data, int i);
void	fill_matrix(t_fdf *data, char *file, int fd);

/*--------KEYS-------------*/
void	controls_call(t_fdf *data);
int		is_key(int key);
int		key_commands(int key, t_fdf *data);
void	mouse_apply(int button, t_fdf *data);
int		mouse_hook(int button, int x, int y, t_fdf *data);

/*-------BRESENHEIM---------*/
void	my_pixel_put(t_fdf *data);
void	draw_line(t_fdf data, int i);
void	draw_prep(t_fdf data);
void	draw_points(t_fdf *data);
int		draw(t_fdf *data, int *bits_p_p, int *size_line, int *endian);
void	isometric(int *x, int *y, float z, t_fdf *data);

/*--------UTILS------------*/
int		ft_abs(int a);
int		choose_direct(int x1, int x2);
int		error_calc(int xd, int yd);
void	my_pixel_put(t_fdf *data);
int		mouse_hook(int button, int x, int y, t_fdf *data);
void	positions_init(t_fdf *data);

#endif
