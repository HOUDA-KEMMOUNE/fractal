/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkemmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 07:59:51 by hkemmoun          #+#    #+#             */
/*   Updated: 2025/03/27 07:59:53 by hkemmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_msg(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void	usage_msg(void)
{
	ft_putstr("Usage: ./program_name mandelbrot or ");
	ft_putstr("./program_name Julia (value of x) (value of y)\n");
	exit (1);
}

void	outside_values_msg(void)
{
	ft_putstr("The values of x and y sould be between -2 and 2\n");
	exit(1);
}

void	invalid_input_msg(void)
{
	ft_putstr("Invalid input :/\n");
	exit(1);
}
