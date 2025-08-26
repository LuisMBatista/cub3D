/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_criation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:19:44 by lumiguel          #+#    #+#             */
/*   Updated: 2025/08/26 10:38:49 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mlx_creation(t_cub3d *img)
{
	img->mlx_connection = mlx_init();
	if (!img->mlx_connection)
	{
		ft_printf("Error: Failed to initialize mlx_connection.\n");
		free(img);
		exit (0);
	}
	img->mlx_win = mlx_new_window(
			img->mlx_connection,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			"Quack"
			);
	if (!img->mlx_win)
	{
		ft_printf("Error: Failed to create window.\n");
		mlx_destroy_display(img->mlx_connection);
		free(img->mlx_connection);
		free(img);
		exit (0);
	}
	mlx_creation2(img);
}

void	mlx_creation2(t_cub3d *img)
{
	img->img = mlx_new_image(img->mlx_connection, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img->img)
	{
		ft_printf("Error: Failed to create image.\n");
		mlx_destroy_window(img->mlx_connection, img->mlx_win);
		mlx_destroy_display(img->mlx_connection);
		free(img->mlx_connection);
		free(img);
		exit (0);
	}
	img->addr = mlx_get_data_addr(
			img->img,
			&img->bits_per_pixel,
			&img->line_length,
			&img->endian);
	if (!img->addr)
	{
		ft_printf("Error: Failed to get data address for image.\n");
		mlx_destroy_image(img->mlx_connection, img->img);
		mlx_destroy_window(img->mlx_connection, img->mlx_win);
		mlx_destroy_display(img->mlx_connection);
		free(img->mlx_connection);
		free(img);
		exit (0);
	}
}
