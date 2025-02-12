/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:12:21 by psirault          #+#    #+#             */
/*   Updated: 2025/02/12 13:20:23 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

t_complex	squared_complex(t_complex z)
{
	t_complex	res;

	res.r = (z.r * z.r) - (z.im * z.im);
	res.im = z.r * 2 * z.im;
	return (res);
}

t_complex	squared_complex_abs(t_complex z)
{
	t_complex	res;

	z.r = fabs(z.r);
	z.im = fabs(z.im);
	res.r = (z.r * z.r) - (z.im * z.im);
	res.im = z.r * 2 * z.im;
	return (res);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.r = z1.r + z2.r;
	res.im = z1.im + z2.im;
	return (res);
}

double scale1(double nb, double n_min, double n_max)
{
    return (n_max - n_min) * nb + n_min;
}

double scale2(double nb, double o_min, double o_max)
{
    return (nb - o_min) / (o_max - o_min);
}

