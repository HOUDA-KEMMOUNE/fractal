/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:35:41 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/22 23:35:42 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

// (Deep Ocean Theme) + white
# define DEEP_BLUE 0x000033
# define BRIGHT_BLUE 0x0066FF
# define LIGHT_BLUE 0x66CCFF

//Neon Cyberpunk (Glowing Effect) + black + white
# define MAGENTA 0xFF00FF
# define CYAN 0x00FFFF
# define YELLOW 0xFFFF00

//Fire & Lava (Hot Colors) + yellow + white
# define DARK_RED 0x330000
# define ORANGE 0xFF6600
# define MAGENTA 0xFF00FF

//Space & Galaxy (Mystical Colors) + white
# define DEEP_PURPLE 0x220033
# define BRIGHT_PINK 0xFF00CC
# define ELECTRIC_BLUE 0x00CCFF

//Earth Tones (Natural Look) + light_blue
# define DARK_GREEN 0x003300
# define FOREST_GREEN 0x228B22
# define OLIVE 0x808000
# define BEIGE 0xF5DEB3

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_img
{
	void	*img;//mlx_new_image
	char	*buffer;//mlx_get_data_addr
	int		bpp;
	int		line_bytes;
	int		endian;
	void	*mlx_window;
}				t_img;

typedef struct s_mlx
{
	char	*name;
	void	*mlx_conn;
	void	*mlx_window;
	t_img	image;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_mlx;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
void		ft_putstr(char *s);
double		ft_atod(char *s);
void		fractal_init(t_mlx *fractol);
void		fractal_render(t_mlx *fractol);
void		events_init(t_mlx *fractol);
void		mandel_or_julia(t_complex *c, t_complex *z, t_mlx *fractol);
void		error_msg(void);
void		usage_msg(void);
void		outside_values_msg(void);
void		invalid_input_msg(void);
int			close_handler(t_mlx *fractol);
int			key_handler(int keysym, void *fractol);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	sum_complexe(t_complex z, t_complex c);
t_complex	square_complexe(t_complex z);

#endif
