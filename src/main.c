/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:14:49 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/11 15:14:19 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int ac, char **av)
{
	if (!arg_validation(ac, av))
		return (ft_putstr_fd("invalid arguments\n", 2),1);
	
	t_index *index = init_index();
	index->map = file_validation(av[1]);
	mlx_key_hook(index->cub3d->mlx_win, handle_key, index);
    mlx_hook(index->cub3d->mlx_win, 17, 0, handle_closing, index);
    mlx_loop(index->cub3d->mlx_connection);
	free(index);
    return(0);
}
void clean_exit(t_index *index)
{
	if (!index || !index->cub3d)
		exit(1);

	mlx_destroy_image(index->cub3d->mlx_connection, index->cub3d->img);
	mlx_destroy_window(index->cub3d->mlx_connection, index->cub3d->mlx_win);
	mlx_destroy_display(index->cub3d->mlx_connection);

	free(index->cub3d->mlx_connection);
	index->cub3d->mlx_connection = NULL;

	free(index->cub3d);
	index->cub3d = NULL;

	free(index);
	exit(0);
}
