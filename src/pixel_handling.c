/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:57:22 by psirault          #+#    #+#             */
/*   Updated: 2025/02/07 10:40:32 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	pixel_handling_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int 	i;
	int		color;

	i = 0;
	z.r = 0.0;
	z.im = 0.0;
	c.r = (rescale(x, -2, 2, 0, 800) * fractal->zoom_value) + fractal->offset_x;
	c.im = (rescale(x, 2, -2, 0, 800) * fractal->zoom_value) + fractal->offset_y;

	while (i < fractal->max_iterations)
	{
		z = sum_complex(squared_complex(z), c);
		if ((z.r * z.r) + (z.im * z.im) > 4)
		{
			color = rescale(i, 0x000000, 0xFFFFFF, 0, fractal->max_iterations);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, 0xFFFFFF);
}

void	pixel_handling_julia(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int 	i;
	int		color;

	i = 0;
	z.r = (rescale(x, -2, 2, 0, 800) * fractal->zoom_value) + fractal->offset_x;
	z.im = (rescale(y, 2, -2, 0, 800) * fractal->zoom_value) + fractal->offset_y;
	c.r = fractal->julia_r;
	c.im = fractal->julia_im;

	while (i < fractal->max_iterations)
	{
		z = sum_complex(squared_complex(z), c);
		
		if ((z.r * z.r) + (z.im * z.im) > 4)
		{
			color = rescale(i, 0x000000, 0xFFFFFF, 0, fractal->max_iterations);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, 0xFFFFFF);
}

void pixel_handling(int x, int y, t_fractal *fractal)
{
	if (ft_strcmp(fractal->ID, "mandelbrot") == 0)
		pixel_handling_mandelbrot(x, y, fractal);
	if (ft_strcmp(fractal->ID, "julia") == 0)
		pixel_handling_julia(x, y, fractal);
}
