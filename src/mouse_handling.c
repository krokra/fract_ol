/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:23:08 by psirault          #+#    #+#             */
/*   Updated: 2025/02/12 13:39:41 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	mbuttons_handling(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		fractal->zoom_value *= 0.9;
		fractal->offset_x += (scale1(scale2(x, 0, 800), -2, 2)) * fractal->zoom_value;
		fractal->offset_y += (scale1(scale2(y, 0, 800), 2, -2)) * fractal->zoom_value;
	}	
	else if (button == 5)
		fractal->zoom_value *= 1.1;

	render_fractal(fractal);
	return (0);
}
