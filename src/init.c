/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:09:43 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/13 16:05:36 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	data->win_width = WIDTH;
	data->win_height = HEIGHT;
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_addr = mlx_get_data_addr
		(data->img, &data->bpp, &data->size_line, &data->endian);
}

void	init_data(t_data *data, char *name)
{
	data->z_i = 0;
	data->z_r = 0;
	data->c_i = 0.355;
	data->c_r = 0.355;
	data->zoom = 0.5;
	data->offset_x = 0;
	data->offset_y = 0;
	data->max_iter = 200;
	data->name = name;
	data->iter = 0;
	data->pixel = 0;
	data->seed = 123456789;
	data->color_shift = 0;
}
