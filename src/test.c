/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psirault <psirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:09:48 by psirault          #+#    #+#             */
/*   Updated: 2025/02/06 14:23:19 by psirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/fract_ol.h"

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	color_screen(t_fractal *vars, int color)
// {
// 	int i, j;

// 	i = -1;
// 	while (++i < 800)
// 	{
// 		j = -1;
// 		while (++j < 800)
// 		{
// 			my_mlx_pixel_put(&vars->img, i, j, color);
// 		}
// 	}
// }

// int	key_hook(int keysym, t_fractal *vars)
// {
// 	if (keysym == XK_r)
// 	{
// 		color_screen(vars, 0xff0000);
// 	}
// 	else if (keysym == XK_g)
// 	{
// 		color_screen(vars, 0xff00);
// 	}
// 	else if (keysym == XK_b)
// 	{
// 		color_screen(vars, 0xff);
// 	}
// 	else if (keysym == XK_Escape)
// 		exit(1);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.data, 0, 0);
// 	return (0);
// }

// int	main(void)
// {
// 	t_fractal	mlx;

// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, 800, 800, "Hello world!");
// 	mlx.img.data = mlx_new_image(mlx.mlx, 800, 800);
// 	mlx.img.addr = mlx_get_data_addr(mlx.img.data, &mlx.img.bits_per_pixel,
// 								&mlx.img.line_length,
// 								&mlx.img.endian);
// 	mlx_key_hook(mlx.win, key_hook, &mlx);
// 	mlx_loop(mlx.mlx);
// }
