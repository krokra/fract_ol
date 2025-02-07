/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:11:28 by psirault          #+#    #+#             */
/*   Updated: 2025/02/07 09:57:11 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	render_fractal(t_fractal *fractal)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 800)
	{
		j = -1;
		while (++j < 800)
		{
			pixel_handling(j, i, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.data, 0, 0);
}
