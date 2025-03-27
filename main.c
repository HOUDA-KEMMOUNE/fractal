/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:58:36 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/24 14:58:38 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_mlx	fractol;

	if ((ac == 2) && (ft_strncmp(av[1], "mandelbrot",
				ft_strlen("mandelbrot")) == 0)
		|| (ac == 4) && (ft_strncmp(av[1], "julia", ft_strlen("julia")) == 0))
	{
		fractol.name = av[1];
		if ((ft_strncmp(fractol.name, "julia", ft_strlen("julia")) == 0)
			&& ((ft_atod(av[2]) >= -2.0 && ft_atod(av[2]) <= 2.0)
				&& (ft_atod(av[3]) >= -2.0 && ft_atod(av[3]) <= 2.0)))
		{
			fractol.julia_x = ft_atod(av[2]);
			fractol.julia_y = ft_atod(av[3]);
		}
		else if ((ft_strncmp(fractol.name, "julia", ft_strlen("julia")) == 0)
			&& !((ft_atod(av[2]) >= -2.0 && ft_atod(av[2]) <= 2.0)
				&& (ft_atod(av[3]) >= -2.0 && ft_atod(av[3]) <= 2.0)))
			outside_values_msg();
		fractal_init(&fractol);
		fractal_render(&fractol);
		mlx_loop(fractol.mlx_conn);
	}
	else
		usage_msg();
}
