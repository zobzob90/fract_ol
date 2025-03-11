/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertrigna <ertrigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:09:48 by ertrigna          #+#    #+#             */
/*   Updated: 2025/01/16 12:35:15 by ertrigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	draw_fractal(t_data *data, char *av)
{
	if (ft_strncmp(av, "mandelbrot", 10) == 0)
		render_mandelbrot(data);
	else if (ft_strncmp(av, "julia", 5) == 0)
		render_julia(data);
	else if (ft_strncmp(av, "tricorn", 7) == 0)
		render_tricorn(data);
	else if (ft_strncmp(av, "burning", 7) == 0)
		render_burning(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

static void	help_message(void)
{
	ft_putchar_fd('\n', 1);
	ft_putendl_fd("\t\t=== Welcome to Fractol ===\n", 1);
	ft_putendl_fd("\t=== Usage: ./fractol [fractal name] ===\n", 1);
	ft_putendl_fd("\tAvailable fractals: mandelbrot / julia / tricorn\n", 1);
	ft_putendl_fd("\t--- Key: WASD or arrow for controls ---\n", 1);
	ft_putendl_fd("\t--- Mouse: scroll for zoom ---\n", 1);
	ft_putendl_fd("\t--- Mouse: left click for randoming Julia Set ---\n", 1);
	ft_putendl_fd("\t--- Key: R for reset Fractal Set ---\n", 1);
	ft_putendl_fd("\t--- Key: +/- for zoom in/out ---\n", 1);
	ft_putendl_fd("\t--- Key: TAB for change color ---\n", 1);
	ft_putendl_fd("\t--- Key: ESC for exit ---\n", 1);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac == 2)
	{
		help_message();
		if (ft_strncmp(av[1], "mandelbrot", 10) != 0
			&& ft_strncmp(av[1], "julia", 5) != 0
			&& ft_strncmp(av[1], "tricorn", 7) != 0
			&& ft_strncmp(av[1], "burning", 7) != 0)
		{
			ft_putendl_fd("Error: Invalid Fractal Name\n", 2);
			ft_putendl_fd("Available: mandelbrot/ julia/ tricorn/ burning\n", 2);
			return (EXIT_FAILURE);
		}
		init_mlx(&data);
		init_data(&data, av[1]);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_mouse_hook(data.win, mouse_hook, &data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		draw_fractal(&data, av[1]);
		mlx_loop(data.mlx);
	}
	else
		ft_putendl_fd("Error: Invalid Number of Arguments\n", 2);
	return (0);
}
