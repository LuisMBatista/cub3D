/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:59:38 by lumiguel          #+#    #+#             */
/*   Updated: 2025/08/26 11:47:40 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int handle_key(int keycode, t_index *index)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(index->cub3d->mlx_connection, index->cub3d->img);
		mlx_destroy_window(index->cub3d->mlx_connection, index->cub3d->mlx_win);
		mlx_destroy_display(index->cub3d->mlx_connection);
		free(index->cub3d->mlx_connection);
		free_index(index);
		exit(0);
	}
	return(0);
}

int handle_closing(t_index *index)
{
	mlx_destroy_image(index->cub3d->mlx_connection, index->cub3d->img);
	mlx_destroy_window(index->cub3d->mlx_connection, index->cub3d->mlx_win);
	mlx_destroy_display(index->cub3d->mlx_connection);
	free_index(index);
	exit(0);
	return (0);
}

