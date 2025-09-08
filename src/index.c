/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:37:29 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/08 10:55:22 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_index *init_index(void)
{
	t_index *index = malloc(sizeof(t_index));
	if (!index)
		return(NULL);

	index->cub3d= malloc(sizeof(t_cub3d));
	if (!index->cub3d)
	{
		free(index);
		return(NULL);
	}
	mlx_creation(index->cub3d);
	return(index);
}
