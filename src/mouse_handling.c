/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:23:08 by psirault          #+#    #+#             */
/*   Updated: 2025/02/11 14:23:08 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	mbuttons_handling(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4)
	{
		fractal->zoom_value *= 1.1;
		render_fractal(fractal);
	}
	else if (button == 5)
	{
		fractal->zoom_value *= 0.9;
		render_fractal(fractal);
	}
}
