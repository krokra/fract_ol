/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:23:08 by psirault          #+#    #+#             */
/*   Updated: 2025/02/13 11:20:26 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	mbuttons_handling(int button, int x, int y, t_fractal *fractal)
{
	double	old_zoom;
	double	new_zoom;

	old_zoom = fractal->zoom_value;
	if (button == 4)
	{
		fractal->zoom_value *= 0.9;
		new_zoom = old_zoom * 0.9;
	}
	else if (button == 5)
	{
		fractal->zoom_value *= 1.1;
		new_zoom = old_zoom * 1.1;
	}
	fractal->offset_x += (scale1(scale2(x, 0, 800), -2, 2))
		* (old_zoom - new_zoom);
	fractal->offset_y += (scale1(scale2(y, 0, 800), 2, -2))
		* (old_zoom - new_zoom);
	render_fractal(fractal);
	return (0);
}
