/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:55:45 by ldias-fe          #+#    #+#             */
/*   Updated: 2023/02/02 22:17:44 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	check_julia(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (((c[i] >= 65 && c[i] <= 90)
				|| (c[i] >= 97 && c[i] <= 122)) == 0)
			i++;
		else
			return (1);
	}
	return (0);
}

int	p_julia(double c_re, double c_im, t_data *data)
{
	int		iter;
	double	z_re;
	double	z_im;
	double	tmp;

	iter = 0;
	z_re = c_re;
	z_im = c_im;
	while (z_re * z_re + z_im * z_im < 4 && iter < MAX_ITER)
	{
		tmp = 2 * z_re * z_im + data->w_im;
		z_re = z_re * z_re - z_im * z_im + data->w_re;
		z_im = tmp;
		iter++;
	}
	if (iter == MAX_ITER)
		return (0x00000000);
	else
		return (data->color * iter * PI);
}

void	julia(t_data *data)
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
			my_mlx_pixel_put(&data->img, x, y, p_julia(c_re, c_im, data));
			x++;
		}
		y++;
	}
}
/*
** Julia sets:  -0.4000  0.6000 ,  0.2850  0.0000 ,
**               0.2850  0.0100 ,  0.4500  0.1428 ,
**              -0.7017 -0.3842 , -0.8350 -0.2321 ,
**              -0.8000  0.1560 , -0.4000  0.1560 ,
*/
