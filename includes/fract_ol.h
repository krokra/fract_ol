/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:04 by psirault          #+#    #+#             */
/*   Updated: 2025/02/13 11:02:18 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <X11/keysym.h>
#include "../mlx_linux/mlx.h"

typedef struct	s_img {
	void	*data;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;
typedef struct	s_fractal {
	int		ID;
	void	*mlx;
	void	*win;
	t_img	img;
	int		color;
	double offset_x;
	double offset_y;
	double julia_r;
	double julia_im;
	double zoom_value;
	int	max_iterations;
}				t_fractal;
typedef struct	s_complex {
	double r;
	double im;
}				t_complex;
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
void		init_fractal(t_fractal *fractal, char **argv);
double scale1(double nb, double n_min, double n_max);
double scale2(double nb, double o_min, double o_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	squared_complex(t_complex z);
void		pixel_handling(int x, int y, t_fractal *fractal);
void		render_fractal(t_fractal *fractal);
int			mbuttons_handling(int button, int x, int y, t_fractal *fractal);
void		motion_handling(int x, int y, t_fractal *fractal);
void		events_handling(t_fractal *fractal);
double		ft_atof(const char *str);
int			ft_isdigit(char c);
int			ft_close_window(t_fractal *vars);
void		pixel_handling_mandelbrot(int x, int y, t_fractal *fractal);
void		pixel_handling_julia(int x, int y, t_fractal *fractal);
double		smooth_color(t_complex z, int i, t_fractal *fractal);
int			color_gradient(double t);
t_complex	squared_complex_abs(t_complex z);
void		pixel_handling_burningship(int x, int y, t_fractal *fractal);
int			color_gradient_burningship(double t);
int 		key_hook_extended(int keysym, t_fractal *fractal);
int	is_julia_param_valid(char *str);
#endif