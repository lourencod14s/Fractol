/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:48:18 by ldias-fe          #+#    #+#             */
/*   Updated: 2023/02/01 21:22:50 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	armageddom(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit (0);
}

int	close_win(int key, t_data *data)
{
	if (key == ESC)
		armageddom(data);
	return (0);
}

int	mouse_zoom(int m_key, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (m_key == 4)
	{
		data->img.minre -= data->img.minre * 0.1;
		data->img.maxre -= data->img.maxre * 0.1;
		data->img.minim -= data->img.minim * 0.1;
		data->img.maxim -= data->img.maxim * 0.1;
	}
	if (m_key == 5)
	{
		data->img.minre += data->img.minre * 0.1;
		data->img.maxre += data->img.maxre * 0.1;
		data->img.minim += data->img.minim * 0.1;
		data->img.maxim += data->img.maxim * 0.1;
	}
	if (data->choice == '1')
		mandelbrot(data);
	if (data->choice == '2')
		julia(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (1);
}

int	key_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 0, armageddom, data);
	mlx_key_hook(data->win_ptr, close_win, data);
	mlx_mouse_hook(data->win_ptr, mouse_zoom, data);
	return (0);
}
