/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_criation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:19:44 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/08 10:55:11 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mlx_creation(t_cub3d *cub)
{
	cub->mlx_connection = mlx_init();
	if (!cub->mlx_connection)
	{
		ft_printf("Error: Failed to initialize mlx_connection.\n");
		free(cub);
		exit (0);
	}
	cub->mlx_win = mlx_new_window(
			cub->mlx_connection,
			WIDTH,
			HEIGHT,
			"Quack"
			);
	if (!cub->mlx_win)
	{
		ft_printf("Error: Failed to create window.\n");
		mlx_destroy_display(cub->mlx_connection);
		free(cub->mlx_connection);
		free(cub);
		exit (0);
	}
	mlx_creation2(cub);
}

void	mlx_creation2(t_cub3d *cub)
{
	cub->img = mlx_new_image(cub->mlx_connection, WIDTH, HEIGHT);
	if (!cub->img)
	{
		ft_printf("Error: Failed to create image.\n");
		mlx_destroy_window(cub->mlx_connection, cub->mlx_win);
		mlx_destroy_display(cub->mlx_connection);
		free(cub->mlx_connection);
		free(cub);
		exit (0);
	}
	cub->addr = mlx_get_data_addr(
			cub->img,
			&cub->bits_per_pixel,
			&cub->line_length,
			&cub->endian);
	if (!cub->addr)
	{
		ft_printf("Error: Failed to get data address for image.\n");
		mlx_destroy_image(cub->mlx_connection, cub->img);
		mlx_destroy_window(cub->mlx_connection, cub->mlx_win);
		mlx_destroy_display(cub->mlx_connection);
		free(cub->mlx_connection);
		free(cub);
		exit (0);
	}
}
