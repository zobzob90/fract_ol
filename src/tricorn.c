/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:01:07 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/17 12:33:03 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calculate_tricorn(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = cr;
	zi = ci;
	n = 0;
	while (n < 100)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}

void	render_tricorn(t_data *data)
{
	data->y = 0;
	while (data->y < SIZE)
	{
		data->x = 0;
		while (data->x < SIZE)
		{
			data->iter = calculate_tricorn((data->x - SIZE / 2)
					/ (0.5 * data->zoom * SIZE) + data->offset_x,
					(data->y - SIZE / 2)
					/ (0.5 * data->zoom * SIZE) + data->offset_y);
			if (data->iter == 100)
				data->color = 0x000000;
			else
				data->color = get_color(data->iter, data);
			data->pixel = (data->y * data->size_line)
				+ (data->x * (data->bpp / 8));
			put_pixel_to_image(data, data->x, data->y, data->color);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
