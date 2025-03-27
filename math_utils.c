/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:57:04 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/25 00:57:09 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_atod_helper(char *s, long *integer, double *div,
		double *fract)
{
	while (*s != '.' && *s)
	{
		if (*s >= '0' && *s <= '9')
			*integer = (*integer * 10) + (*s++ - '0');
		else
			invalid_input_msg();
	}
	if ('.' == *s)
		++s;
	if ('.' == *s)
		invalid_input_msg();
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			*div /= 10;
			*fract = *fract + (*s++ - '0') * (*div);
		}
		else
			invalid_input_msg();
	}
	return ((*integer) + (*fract));
}

double	ft_atod(char *s)
{
	long	integer;
	double	fract;
	double	div;
	int		sign;
	double	r;

	integer = 0;
	fract = 0;
	sign = +1;
	div = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
	{
		if ('-' == *s++)
			sign = -sign;
		if ('+' == *s || '-' == *s)
			invalid_input_msg();
	}
	if (*s == '.')
		invalid_input_msg();
	r = ft_atod_helper(s, &integer, &div, &fract);
	return (r * sign);
}

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	scale;

	scale = (new_max - new_min) * (unscaled_num)
		/ (old_max) + new_min;
	return (scale);
}

t_complex	sum_complexe(t_complex z, t_complex c)
{
	t_complex	r;

	r.x = z.x + c.x;
	r.y = z.y + c.y;
	return (r);
}

t_complex	square_complexe(t_complex z)
{
	t_complex	r;

	r.x = (z.x * z.x) - (z.y * z.y);
	r.y = 2 * z.x * z.y;
	return (r);
}
