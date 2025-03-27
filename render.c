/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:43:17 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/25 00:43:19 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *image, int color)
{
	int	offset;

	offset = (y * image->line_bytes) + ((x * image->bpp) / 8);
	*(unsigned int *)(image->buffer + offset) = color;
}

void	mandel_or_julia(t_complex *c, t_complex *z, t_mlx *fractol)
{
	if (ft_strncmp(fractol->name, "julia", ft_strlen("julia")) == 0)
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else if (ft_strncmp(fractol->name, "mandelbrot",
			ft_strlen("mandelbrot")) == 0)
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_mlx *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, 2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	mandel_or_julia(&c, &z, fractol);
	while (i < fractol->iterations)
	{
		z = sum_complexe(square_complexe(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, DARK_RED, ORANGE, fractol->iterations);
			my_pixel_put(x, y, &fractol->image, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->image, WHITE);
}

void	fractal_render(t_mlx *fractol)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_conn, fractol->mlx_window,
		fractol->image.img, 0, 0);
}
