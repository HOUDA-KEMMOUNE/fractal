/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:33:56 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/22 23:33:57 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	data_init(t_mlx *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.1;
}

void	fractal_init(t_mlx *fractol)
{
	fractol->mlx_conn = mlx_init();
	if (fractol->mlx_conn == NULL)
		error_msg();
	fractol->mlx_window = mlx_new_window(fractol->mlx_conn, WIDTH,
			HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_conn);
		free(fractol->mlx_conn);
		error_msg();
	}
	fractol->image.img = mlx_new_image(fractol->mlx_conn, WIDTH, HEIGHT);
	if (fractol->image.img == NULL)
	{
		mlx_destroy_window(fractol->mlx_conn, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_conn);
		free(fractol->mlx_conn);
		error_msg();
	}
	fractol->image.buffer = mlx_get_data_addr(fractol->image.img,
			&fractol->image.bpp, &fractol->image.line_bytes,
			&fractol->image.endian);
	events_init(fractol);
	data_init(fractol);
}
