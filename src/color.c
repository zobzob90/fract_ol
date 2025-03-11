/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:08:41 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/15 15:03:30 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	calculate_rgb(double t, int color_shift, t_color *color)
{
	if (color_shift == 0)
	{
		color->red = (int)(9 * (1 - t) * t * t * t * 255);
		color->green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		color->blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (color_shift == 1)
	{
		color->red = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		color->green = (int)(9 * (1 - t) * t * t * t * 255);
		color->blue = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	}
	else if (color_shift == 2)
	{
		color->red = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		color->green = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		color->blue = (int)(9 * (1 - t) * t * t * t * 255);
	}
}

int	get_color(int i, t_data *data)
{
	t_color	color;
	double	t;

	color = (t_color){0, 0, 0};
	t = (double)i / data->max_iter;
	calculate_rgb(t, data->color_shift, &color);
	return ((color.red << 16) + (color.green << 8) + color.blue);
}

int	shift_color(int color, int shift)
{
	int	red;
	int	green;
	int	blue;

	red = (color & 0xFF0000) >> 16;
	green = (color & 0x00FF00) >> 8;
	blue = color & 0x0000FF;
	red += shift;
	green += shift;
	blue += shift;
	if (red > 255)
		red = 255;
	if (green > 255)
		green = 255;
	if (blue > 255)
		blue = 255;
	return ((red << 16) + (green << 8) + blue);
}
