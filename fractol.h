/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:09:26 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/17 12:43:58 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <stdlib.h>

/*Screen*/
# define WIDTH 800
# define HEIGHT 800

/*key*/
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define A 97
# define S 115
# define D 100
# define ZOOM_IN 61
# define ZOOM_OUT 45
# define RESET 114
# define TAB 65289

/*MOUSE*/
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_MIDDLE 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MINUS_NUM 78
# define PLUS_NUM 69
# define SIZE 800

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}	t_color;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int				win_width;
	int				win_height;
	int				bpp;
	int				size_line;
	int				endian;
	int				color;
	int				color_shift;
	double			offset_x;
	double			offset_y;
	double			x;
	double			y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			zoom;
	char			*name;
	int				max_iter;
	int				iter;
	int				pixel;
	unsigned int	seed;
}	t_data;

/*INIT*/
void	init_mlx(t_data *data);
void	init_data(t_data *data, char *name);

/*KEY*/
void	reset_zoom(t_data *data);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int keycode, int x, int y, t_data *data);

/*MANDLEBROT*/
int		calculate_mandelbrot(double c_r, double c_i);
void	render_mandelbrot(t_data *data);

/*JULIA*/
int		calculate_julia(t_data *data);
void	render_julia(t_data *data);

/*TRICORN*/
int		calculate_tricorn(double cr, double ci);
void	render_tricorn(t_data *data);

/*BURNING*/
int		calculate_burning(double c_r, double c_i);
void	render_burning(t_data *data);

/*UTILS*/
int		close_window(t_data *data);
double	ft_rand(unsigned int *seed, double min, double max);
void	put_pixel_to_image(t_data *data, int x, int y, int color);

/*COLOR*/
int		shift_color(int color, int shift);
int		get_color(int i, t_data *data);
void	calculate_rgb(double t, int color_shift, t_color *color);

/*MAIN*/
int		draw_fractal(t_data *data, char *query);

#endif
