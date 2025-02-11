/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:01:20 by psirault          #+#    #+#             */
/*   Updated: 2025/02/11 14:01:20 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	events_handling(t_fractal *fractal)
{
	mlx_hook(fractal->win, 02, (1L<<0), key_hook, fractal);
	mlx_hook(fractal->win, 04, (1L<<2), mbuttons_handling, fractal);
	mlx_hook(fractal->win, 17, (1L<<17), ft_close_window, fractal);
}
int	ft_close_window(t_fractal *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.data);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close_window(fractal);
	if (keysym == XK_Left)
		fractal->offset_x += (0.5 * fractal->zoom_value);
	else if (keysym == XK_Right)
		fractal->offset_x -= (0.5 * fractal->zoom_value);
	else if (keysym == XK_Up)
		fractal->offset_y -= (0.5 * fractal->zoom_value);
	else if (keysym == XK_Down)
		fractal->offset_y += (0.5 * fractal->zoom_value);
	else if (keysym == XK_plus)
		fractal->max_iterations += 10;
	else if (keysym == XK_minus)
		fractal->max_iterations -= 10;
	render_fractal(fractal);
	return (0);
}
