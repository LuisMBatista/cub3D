/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:06:38 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/19 16:38:33 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void free_index(t_index *index)
{
	if (!index)
        return;
	if(index->cub3d)
	{
		free(index->cub3d);
		index->cub3d = NULL;
	}
}

void free_map(t_map *map)
{
	int i = 0;

	if (!map || !map->map)
		return;

	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
