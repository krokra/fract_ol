/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:01:20 by psirault          #+#    #+#             */
/*   Updated: 2025/02/13 12:10:02 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	key_hook(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_window(fractal);
	if (keysym == XK_Left)
		fractal->offset_x -= (0.5 * fractal->zoom_value);
	else if (keysym == XK_Right)
		fractal->offset_x += (0.5 * fractal->zoom_value);
	else if (keysym == XK_Up)
		fractal->offset_y += (0.5 * fractal->zoom_value);
	else if (keysym == XK_Down)
		fractal->offset_y -= (0.5 * fractal->zoom_value);
	else if (keysym == XK_k)
		fractal->max_iterations += 20;
	else if (keysym == XK_j)
		fractal->max_iterations -= 20;
	else if (keysym == XK_p)
		fractal->zoom_value *= 1.1;
	else if (keysym == XK_o)
		fractal->zoom_value *= 0.9;
	key_hook_extended(keysym, fractal);
	render_fractal(fractal);
	return (0);
}

int	key_hook_extended(int keysym, t_fractal *fractal)
{
	if (keysym == XK_1)
	{
		fractal->ID = 1;
		fractal->zoom_value = 1.0;
		fractal->offset_x = 0.0;
		fractal->offset_y = 0.0;
	}
	else if (keysym == XK_2)
	{
		fractal->ID = 2;
		fractal->zoom_value = 1.0;
		fractal->offset_x = 0.0;
		fractal->offset_y = 0.0;
	}
	else if (keysym == XK_3)
	{
		fractal->ID = 3;
		fractal->zoom_value = 1.0;
		fractal->offset_x = 0.0;
		fractal->offset_y = 0.0;
	}
	return (0);
}

int	ft_close_window(t_fractal *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.data);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
}

void	events_handling(t_fractal *fractal)
{
	mlx_hook(fractal->win, 02, (1L << 0), key_hook, fractal);
	mlx_mouse_hook(fractal->win, mbuttons_handling, fractal);
	mlx_hook(fractal->win, 17, (1L << 17), ft_close_window, fractal);
}
