/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:09:45 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/15 15:10:07 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == UP || keycode == W)
		data->offset_y -= 0.1 / data->zoom;
	else if (keycode == DOWN || keycode == S)
		data->offset_y += 0.1 / data->zoom;
	else if (keycode == LEFT || keycode == A)
		data->offset_x -= 0.1 / data->zoom;
	else if (keycode == RIGHT || keycode == D)
		data->offset_x += 0.1 / data->zoom;
	else if (keycode == ZOOM_IN)
		data->zoom *= 1.1;
	else if (keycode == ZOOM_OUT)
		data->zoom /= 1.1;
	else if (keycode == RESET)
		reset_zoom(data);
	else if (keycode == TAB)
	{
		data->color_shift = (data->color_shift + 1) % 3;
		draw_fractal(data, data->name);
	}
	draw_fractal(data, data->name);
	return (0);
}

void	reset_zoom(t_data *data)
{
	data->zoom = 0.5;
	data->offset_x = 0;
	data->offset_y = 0;
}

static void	mouse_zoom_plus(t_data *data, int x, int y)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - SIZE / 2) / (0.5 * data->zoom * SIZE) + data->offset_x;
	mouse_im = (y - SIZE / 2) / (0.5 * data->zoom * SIZE) + data->offset_y;
	data->zoom *= 1.1;
	data->offset_x = mouse_re - (x - SIZE / 2) / (0.5 * data->zoom * SIZE);
	data->offset_y = mouse_im - (y - SIZE / 2) / (0.5 * data->zoom * SIZE);
}

static void	mouse_zoom_minus(t_data *data, int x, int y)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - SIZE / 2) / (0.5 * data->zoom * SIZE) + data->offset_x;
	mouse_im = (y - SIZE / 2) / (0.5 * data->zoom * SIZE) + data->offset_y;
	data->zoom /= 1.1;
	data->offset_x = mouse_re - (x - SIZE / 2) / (0.5 * data->zoom * SIZE);
	data->offset_y = mouse_im - (y - SIZE / 2) / (0.5 * data->zoom * SIZE);
}

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	if (keycode == SCROLL_UP)
		mouse_zoom_plus(data, x, y);
	else if (keycode == SCROLL_DOWN)
		mouse_zoom_minus(data, x, y);
	else if (keycode == MOUSE_LEFT)
	{	
		data->c_r = (ft_rand(&data->seed, -2.0, 2.0));
		data->c_i = (ft_rand(&data->seed, -2.0, 2.0));
		render_julia(data);
	}
	draw_fractal(data, data->name);
	return (0);
}
