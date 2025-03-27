/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:31:52 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/26 01:31:53 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int button, int x, int y, void *param)
{
	t_mlx	*fractol;

	fractol = (t_mlx *)param;
	if (button == 4)
		fractol->zoom *= 0.78;
	else if (button == 5)
		fractol->zoom *= 1.0;
	fractal_render(fractol);
	return (0);
}

int	close_handler(t_mlx *fractol)
{
	mlx_destroy_image(fractol->mlx_conn, fractol->image.img);
	mlx_destroy_window(fractol->mlx_conn, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_conn);
	free(fractol->mlx_conn);
	exit (0);
}

int	key_handler(int keysym, void *data)
{
	t_mlx	*fractol;

	fractol = (t_mlx *)data;
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_KP_Add)
		fractol->iterations += 10;
	else if (keysym == 65453)
		fractol->iterations -= 10;
	else if (keysym == XK_Left)
		fractol->shift_x -= 0.5 * fractol->zoom;
	else if (keysym == XK_Right)
		fractol->shift_x += 0.5 * fractol->zoom;
	else if (keysym == XK_Up)
		fractol->shift_y -= 0.5 * fractol->zoom;
	else if (keysym == XK_Down)
		fractol->shift_y += 0.5 * fractol->zoom;
	fractal_render(fractol);
	return (0);
}

void	events_init(t_mlx *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, key_handler, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify,
		StructureNotifyMask, close_handler, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress,
		ButtonPressMask, mouse_handler, fractol);
}
