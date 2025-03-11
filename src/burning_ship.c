/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:06:46 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/16 11:17:31 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calculate_burning(double c_r, double c_i)
{
	int		i;
	double	z_r;
	double	z_i;
	double	tmp;

	i = 0;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < 100)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * fabs(z_i * tmp) + c_i;
		i++;
	}
	return (i);
}

void	render_burning(t_data *data)
{
	data->y = 0;
	while (data->y < SIZE)
	{
		data->x = 0;
		while (data->x < SIZE)
		{
			data->iter = calculate_burning((data->x - SIZE / 2)
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
