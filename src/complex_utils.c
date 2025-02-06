/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:12:21 by psirault          #+#    #+#             */
/*   Updated: 2025/02/06 14:24:22 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

// general formula for squaring : r = r^2 - im^2
// 								  im = 2 * r * im

t_complex	squared_complex(t_complex c)
{
	t_complex res;

	res.r = (c.r * c.r) - (c.im * c.im);
	res.im = c.r * 2 * c.im;
	return (res);
}

t_complex sum_complex(t_complex c1, t_complex c2)
{
	t_complex res;
	
	res.r = c1.r + c2.r;
	res.im = c1.im + c2.im;
	return (res); 
}
