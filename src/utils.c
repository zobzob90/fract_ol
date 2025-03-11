/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:14:03 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/17 12:31:40 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(t_data *data)
{
	mlx_loop_end(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

static unsigned int	ft_rand_int(unsigned int *seed)
{
	*seed = (1103515245 * (*seed) + 12345) & 0x7fffffff;
	return (*seed);
}

double	ft_rand(unsigned int *seed, double min, double max)
{
	return (min + ((double)ft_rand_int(seed) / 0x7fffffff) * (max - min));
}

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	int	pixel;

	pixel = (y * data->size_line) + (x * (data->bpp / 8));
	if (pixel >= 0 && pixel < SIZE * data->size_line)
	{
		data->img_addr[pixel + 0] = color & 0xFF;
		data->img_addr[pixel + 1] = (color >> 8) & 0xFF;
		data->img_addr[pixel + 2] = (color >> 16) & 0xFF;
	}
}
