/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:53:54 by ldias-fe          #+#    #+#             */
/*   Updated: 2023/02/02 22:09:19 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	p_mandelbrot(double c_re, double c_im, t_data *data)
{
	int		iter;
	double	z_re;
	double	z_im;
	double	tmp;

	iter = 0;
	z_re = 0;
	z_im = 0;
	while (z_re * z_re + z_im * z_im < 4 && iter < MAX_ITER)
	{
		tmp = 2 * z_re * z_im + c_im;
		z_re = z_re * z_re - z_im * z_im + c_re;
		z_im = tmp;
		iter++;
	}
	if (iter == MAX_ITER)
		return (0x00000000);
	else
		return (data->color * iter * iter * PI);
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	c_re;
	double	c_im;

	y = 0;
	while (y < HEIGHT)
	{
		c_im = data->img.minim + y * (data->img.maxim
				- data->img.minim) / HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			c_re = data->img.minre + x * (data->img.maxre
					- data->img.minre) / WIDTH;
			my_mlx_pixel_put(&data->img, x, y, p_mandelbrot(c_re, c_im, data));
			x++;
		}
		y++;
	}
}
