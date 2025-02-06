/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:08:04 by psirault          #+#    #+#             */
/*   Updated: 2025/02/06 14:15:13 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
	void	*mlx;
	void	*win;
	t_img	img;
}				t_fractal;

typedef struct	s_complex {
	double r;
	double im;
}				t_complex;


int	ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	init_fractal(t_fractal *fractal);
#endif