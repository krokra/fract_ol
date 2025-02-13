/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:44 by psirault          #+#    #+#             */
/*   Updated: 2025/02/13 11:28:13 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static	void	init_all(t_fractal *fractal, char **argv)
{
	init_fractal(fractal, argv);
	render_fractal(fractal);
	mlx_loop(fractal->mlx);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		|| (argc == 4 && ft_strcmp(argv[1], "julia") == 0
			&& is_julia_param_valid(argv[2]) && is_julia_param_valid(argv[3]))
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
		init_all(&fractal, argv);
	}
	else
	{
		ft_putstr_fd("Enter a valid parameter \"mandelbrot\" or ", 2);
		ft_putstr_fd("\"burningship\" or \"julia\" + [value1] [value2])", 2);
		exit(EXIT_FAILURE);
	}
}
