/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-fe <ldias-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:49:00 by ldias-fe          #+#    #+#             */
/*   Updated: 2023/02/02 21:59:31 by ldias-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     HEADERS_H
# define    HEADERS_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 600
# define MLX_ERROR 1
# define ESC 65307
# define A_LEFT 65361
# define A_UP 65362
# define A_RIGHT 65363
# define A_DOWN 65364
# define MAX_ITER 200
# define PI 3.14159265359

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
}				t_img;

typedef struct s_data
{
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
	double	w_re;
	double	w_im;
	char	choice;
}				t_data;

int			check_arg(t_data *data, int argc, char **argv);
void		initialize(t_data *data);
void		engine(t_data *data);
void		error_msg(void);
int			key_hooks(t_data *data);
int			close_win(int key, t_data *data);
int			mouse_zoom(int m_key, int x, int y, t_data *data);
void		my_mlx_pixel_put(t_img *mlx, int x, int y, int color);
int			p_mandelbrot(double c_re, double c_im, t_data *data);
void		mandelbrot(t_data *data);
int			check_julia(char *c);
int			p_julia(double c_re, double c_im, t_data *data);
void		julia(t_data *data);
double		ft_atof(const char *nptr);
void		ft_putchar_fd(char c, int fd);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
