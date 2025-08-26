/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:14:49 by lumiguel          #+#    #+#             */
/*   Updated: 2025/08/26 11:44:05 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main()
{

	t_index *index = malloc(sizeof(t_index));
		if (!index) {
			// handle malloc failure
		}
	index->cub3d = malloc(sizeof(t_cub3d));
		if (!index->cub3d) {
			// handle malloc failure
		}
	t_cub3d *cub3d = index->cub3d;
    cub3d->mlx_connection = mlx_init();
    cub3d->mlx_win = mlx_new_window(cub3d->mlx_connection, 800, 600, "My first window");
	mlx_key_hook(cub3d->mlx_win, handle_key, index);
    mlx_hook(cub3d->mlx_win, 17, 0, handle_closing, index);
    mlx_loop(cub3d->mlx_connection);
    return(0);
	
}
