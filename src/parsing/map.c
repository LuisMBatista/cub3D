/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:06:25 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/11 16:56:22 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_map *file_validation(char *file)
{
	t_map *map;
	int fd;
	
	map = malloc(sizeof(t_map));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	//Salta tudo ate ao mapa para começar por ele;
	map = map_validation( fd, map);
	return( map);
}

t_map *map_validation( int fd, t_map *map)
{
	char *line;
	line = get_next_line(fd);
	while(line[0] != '1')
		line = get_next_line(fd);
	map->map_length = get_lenght(fd, line);
	printf("%s\n", line);
	return(NULL);
}

int get_lenght(int fd, char *line)
{
	int  size;

	size= ft_strlen(line);
	
	while(line)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) > size)
			size = ft_strlen(line);
		printf("SIZE:%d\n",size);
	}
	return( size);
	
}


