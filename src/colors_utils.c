/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:14:26 by psirault          #+#    #+#             */
/*   Updated: 2025/02/12 13:15:07 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double	smooth_color(t_complex z, int i, t_fractal *fractal)
{
	double	smooth_i;
	double	t;

	smooth_i = (double)i + 1.0 - (log2(log2(sqrt(z.r * z.r + z.im * z.im))));
	t = smooth_i / fractal->max_iterations;
	t = fmax(0.0, fmin(t, 1.0));
	return (t);
}

int	color_gradient(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	color_gradient_burningship(double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(150 * (1 - t) * t * t * t * 255);
	g = (int)(5 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(1 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}
