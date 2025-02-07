/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:12:21 by psirault          #+#    #+#             */
/*   Updated: 2025/02/07 10:15:52 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

// general formula for squaring : r = r^2 - im^2
// 								  im = 2 * r * im

t_complex	squared_complex(t_complex z)
{
	t_complex res;

	res.r = (z.r * z.r) - (z.im * z.im);
	res.im = z.r * 2 * z.im;
	return (res);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex res;
	
	res.r = z1.r + z2.r;
	res.im = z1.im + z2.im;
	return (res); 
}

double rescale (double nb, double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (nb - old_min) / (old_max - old_min) + new_min);
}
