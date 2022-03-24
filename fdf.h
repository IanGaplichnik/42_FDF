/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaplich <igaplich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:54:08 by igaplich          #+#    #+#             */
/*   Updated: 2022/03/24 12:57:08 by igaplich         ###   ########.fr       */
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
	int		**c_matrix;

	int		x_s;
	int		x_e;
	int		y_s;
	int		y_e;
	int		x_off;
	int		y_off;
	int		z;
	int		z1;
	float	z_mult;
	float	angle;
	int		iso;
	int		xd;
	int		yd;
	int		zoom;
	int		color;
	int		mouse_press;
	int		c_flag;
}	t_fdf;

/*--------MAIN--------*/
void	error_print_exit(char *error_text);
void	positions_init(t_fdf *d);
void	params_init(t_fdf *d);
void	mlx_first_call(t_fdf *d);

/*-------DRAW---------*/
int		drawing_algo(t_fdf *d, int *bits_p_p, int *size_line, int *endian);
void	choose_points(t_fdf *d);
void	draw_line(t_fdf d, int i);
void	my_pixel_put(t_fdf *d);

/*------DRAW_PREP-----*/
void	draw_prep(t_fdf d);
void	choose_color(t_fdf *d);
void	apply_zoom(t_fdf *d);

/*------FILE_OPERATIONS-----*/
void	file_operations(t_fdf *d, char *file);
void	read_height_width(char *file, t_fdf *d);
void	read_width(char *line, t_fdf *d, int i, int width);

/*--------KEYS-------------*/
void	controls_call(t_fdf *d);
int		is_key(int key);
int		key_commands(int key, t_fdf *d);
void	mouse_apply(int button, t_fdf *d);
int		mouse_hook(int button, int x, int y, t_fdf *d);

/*-------MATRIX_OPERATIONS------*/
void	create_matrix(t_fdf *d, int i);
void	create_color_matrix(t_fdf *d, int i);
void	init_color_matrix(t_fdf *d);
void	fill_numbers_colors(t_fdf *d, char **numbers, int y);
void	fill_matrix(t_fdf *d, char *file, int fd);

/*--------UTILS------------*/

int		ft_abs(int a);
int		choose_direct(int x1, int x2);
int		error_calc(int xd, int yd);
void	isometric(int *x, int *y, float z, t_fdf *d);
void	controls_print(t_fdf *d);

#endif
