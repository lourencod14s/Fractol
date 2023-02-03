/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:41:24 by ldias-fe          #+#    #+#             */
/*   Updated: 2023/02/02 22:04:09 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	check_arg(t_data *data, int argc, char **argv)
{
	if (argc == 2 && ft_strncmp("mandelbrot", argv[1], 11) == 0)
	{
		data->choice = '1';
		return (1);
	}
	else if (argc == 4 && ft_strncmp("julia", argv[1], 5) == 0
		&& (check_julia(argv[2]) || check_julia(argv[3])))
		error_msg();
	else if (argc == 4 && ft_strncmp("julia", argv[1], 5) == 0
		&& ft_atof(argv[2]) >= -2.0 && ft_atof(argv[2]) <= 2.0
		&& ft_atof(argv[3]) >= -2.0 && ft_atof(argv[3]) <= 2.0)
	{
		data->choice = '2';
		data->w_re = ft_atof(argv[2]);
		data->w_im = ft_atof(argv[3]);
		return (1);
	}
	else
		error_msg();
	return (0);
}

void	error_msg(void)
{
	ft_putstr_fd(" \n\033[6;1;31m#########\033[0m", 1);
	ft_putstr_fd(" \033[6;1;31m INVALID PARAMETERS  ##########\033[0m\n", 1);
	ft_putstr_fd("\033[6;1;31m#\033[0m", 1);
	ft_putstr_fd("Try like this: \"\033[0;7;32m./fract-ol mandelbrot\033[0m\"", 1);
	ft_putstr_fd("\t\033[6;1;31m#\033[0m\n", 1);
	ft_putstr_fd("\033[6;1;31m#\033[0m", 1);
	ft_putstr_fd("      or   \t\t\t", 1);
	ft_putstr_fd("\t\033[6;1;31m#\033[0m\n", 1);
	ft_putstr_fd("\033[6;1;31m#\033[0m", 1);
	ft_putstr_fd("this:\"\033[0;7;32m./fract-ol julia -0.8213 -0.1213\033[0m\"", 1);
	ft_putstr_fd("\033[6;1;31m#\n####", 1);
	ft_putstr_fd("\033[6;1;31m####### PLEASE TRY AGAIN ############\033[0m\n", 1);
}

void	initialize(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "My fractol!");
	data->img.minre = -2.0;
	data->img.maxre = 2.0;
	data->img.minim = -2.0;
	data->img.maxim = 2.0;
	data->color = 0x000000FF;
	engine(data);
}

void	engine(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, (WIDTH), HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	if (data->choice == '1')
		mandelbrot(data);
	else if (data->choice == '2')
		julia(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	key_hooks(data);
	mlx_loop(data->mlx_ptr);
}

void	my_mlx_pixel_put(t_img *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = (color);
}
