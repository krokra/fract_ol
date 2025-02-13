/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:49:31 by psirault          #+#    #+#             */
/*   Updated: 2025/02/13 10:47:27 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	malloc_error(void)
{
	perror("There was an issue with memory allocation");
	exit(EXIT_FAILURE);
}

static void	window_error(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	free(fractal->mlx);
	malloc_error();
}

static void	image_error(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal);
	malloc_error();
}

static void	fractal_data(t_fractal *fractal, char **argv)
{	
	fractal->max_iterations = 40;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractal->ID = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
		fractal->ID = 2;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		fractal->ID = 3;
	fractal->zoom_value = 1.0;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
}

void	init_fractal(t_fractal *fractal, char **argv)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, 800, 800, "fract_ol");
	if (fractal->win == NULL)
		window_error(fractal);
	fractal->img.data = mlx_new_image(fractal->mlx, 800, 800);
	if (fractal->img.data == NULL)
		image_error(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.data,
			&fractal->img.bits_per_pixel,
			&fractal->img.line_length, &fractal->img.endian);
	events_handling(fractal);
	fractal_data(fractal, argv);
}
