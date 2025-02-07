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

void	pixel_handling(int x, int y, t_fractal *fractal)
{
	t_complex z;
	t_complex c;
	int 	i;
	int		color;

	i = 0;
	z.r = 0.0;
	z.im = 0.0;
	c.r = (rescale(x, -2, 2, 0, 800));
	c.im = (rescale(y, 2, -2, 0, 800));

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