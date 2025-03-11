/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 08:43:12 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/15 15:09:35 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calculate_julia(t_data *data)
{
	int		i;
	double	temp_zr;

	i = 0;
	data->z_r = (data->x - SIZE / 2)
		/ (0.5 * data->zoom * SIZE) + data->offset_x;
	data->z_i = (data->y - SIZE / 2)
		/ (0.5 * data->zoom * SIZE) + data->offset_y;
	while (data->z_r * data->z_r + data->z_i
		* data->z_i < 4 && i < data->max_iter)
	{
		temp_zr = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * temp_zr + data->c_i;
		i++;
	}
	return (i);
}

void	render_julia(t_data *data)
{
	data->y = 0;
	while (data->y < SIZE)
	{
		data->x = 0;
		while (data->x < SIZE)
		{
			data->iter = calculate_julia(data);
			if (data->iter == data->max_iter)
				data->color = 0x000000;
			else
				data->color = get_color(data->iter, data);
			data->pixel = (data->y * data->size_line)
				+ (data->x * (data->bpp / 8));
			if (data->pixel >= 0 && data->pixel < SIZE * data->size_line)
			{
				data->img_addr[data->pixel + 0] = data->color & 0xFF;
				data->img_addr[data->pixel + 1] = (data->color >> 8) & 0xFF;
				data->img_addr[data->pixel + 2] = (data->color >> 16) & 0xFF;
			}
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
