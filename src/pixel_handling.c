/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:57:22 by psirault          #+#    #+#             */
/*   Updated: 2025/02/13 11:21:20 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	pixel_handling_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.r = 0.0;
	z.im = 0.0;
	c.r = (scale1(scale2(x, 0, 800), -2, 2) * fractal->zoom_value)
		+ fractal->offset_x;
	c.im = (scale1(scale2(y, 0, 800), 2, -2) * fractal->zoom_value)
		+ fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		z = sum_complex(squared_complex(z), c);
		if ((z.r * z.r) + (z.im * z.im) > 4)
		{
			color = color_gradient(smooth_color(z, i, fractal));
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->img, x, y, 0x000000);
}

void	pixel_handling_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.r = (scale1(scale2(x, 0, 800), -2, 2) * fractal->zoom_value)
		+ fractal->offset_x;
	z.im = (scale1(scale2(y, 0, 800), 2, -2) * fractal->zoom_value)
		+ fractal->offset_y;
	c.r = fractal->julia_r;
	c.im = fractal->julia_im;
	while (++i < fractal->max_iterations)
	{
		z = sum_complex(squared_complex(z), c);
		if ((z.r * z.r) + (z.im * z.im) > 4)
		{
			color = color_gradient(smooth_color(z, i, fractal));
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->img, x, y, 0x000000);
}

void	pixel_handling(int x, int y, t_fractal *fractal)
{
	if (fractal->ID == 1)
		pixel_handling_mandelbrot(x, y, fractal);
	else if (fractal->ID == 2)
		pixel_handling_julia(x, y, fractal);
	else if (fractal->ID == 3)
		pixel_handling_burningship(x, y, fractal);
}
