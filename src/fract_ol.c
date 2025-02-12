/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:44 by psirault          #+#    #+#             */
/*   Updated: 2025/02/12 12:52:15 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int main(int argc, char **argv)
{
	t_fractal fractal;
	
	if ((argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		|| (argc == 4 && ft_strcmp(argv[1], "julia") == 0)
		|| (argc == 2 && ft_strcmp(argv[1], "burningship") == 0))
	{
		if (ft_strcmp(argv[1], "julia") == 0)
		{
			fractal.julia_r = ft_atof(argv[2]);
			fractal.julia_im = ft_atof(argv[3]);
		}
		else
		{
			fractal.julia_r = 0.4;
			fractal.julia_im = 0.4;
		}
		init_fractal(&fractal, argv);
		render_fractal(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		ft_putstr_fd("Please enter a valid parameter (\"mandelbrot\" or \"julia\" + [value1] [value2])", 2);
		exit(EXIT_FAILURE);
	}
}
