/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:49:31 by psirault          #+#    #+#             */
/*   Updated: 2025/02/06 14:08:25 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static void	malloc_error(void)
{
	perror("There was an issue with memory allocation");
	exit(EXIT_FAILURE);
}

static void window_error(t_fractal *fractal)
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

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx, 1920, 1080, "fract_ol");
	if (fractal->win == NULL)
		window_error(fractal);
	fractal->img.data = mlx_new_image(fractal->mlx, 1920, 1080);
	if (fractal->img.data == NULL)
		image_error(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.data, &fractal->img.bits_per_pixel,
											&fractal->img.line_length, &fractal->img.endian);
}
