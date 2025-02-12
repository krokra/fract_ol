/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:41:39 by psirault          #+#    #+#             */
/*   Updated: 2025/02/12 13:23:42 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	pixel_handling_burningship(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = -1;
	z.r = 0.0;
	z.im = 0.0;
	c.r = (scale1(scale2(x, 0, 800), -2, 2) * fractal->zoom_value) + fractal->offset_x;
	c.im = ((scale1(scale2(y, 0, 800), 2, -2) * fractal->zoom_value) + fractal->offset_y) * -1;
	while (++i < fractal->max_iterations)
	{
		z = sum_complex(squared_complex_abs(z), c);
		if ((z.r * z.r) + (z.im * z.im) > 4)
		{
			color = color_gradient_burningship(smooth_color(z, i, fractal));
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(&fractal->img, x, y, 0x000000);
}
