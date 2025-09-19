/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:06:25 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/19 16:31:31 by lumiguel         ###   ########.fr       */
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
	fd = open(file, O_RDONLY);
	map = map_alloc(map, fd);
	print_map(map);
	return( map);
}

t_map *map_validation( int fd, t_map *map) //TEM DE SER MUDADO, SO PARA COMEÇAR 
{
	char *line;
	line = get_next_line(fd);
	while(line[0] != '1')
		line = get_next_line(fd);
	get_size(fd, line, map);
	return(map);
}

void get_size(int fd, char *line, t_map *map)
{
	int  size;
	int height;

	height = 0;
	size= ft_strlen(line);
	
	while(line)
	{
		if (ft_strlen(line) > size)
		size = ft_strlen(line);
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->map_length = size - 1;
	map->map_height = height;
	return;
}

bool	valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'N'
		|| c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

t_map *map_alloc(t_map *map, int fd)
{
	char *line;
	int len;
	int height;

	height = 0;
	map->map = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map->map)
	{
		fprintf(stderr, "malloc failed for map rows\n");
		return NULL;
	}
	line = get_next_line(fd);
	while (line && line[0] != '1')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && height < map->map_height)
	{
		map->map[height] = malloc(sizeof(char) * (map->map_length + 1));
		if (!map->map[height])
		{
			fprintf(stderr, "malloc failed for row %d\n", height);
			return NULL;
		}
		len = 0;
		while (len < map->map_length && line[len] != '\0' && line[len] != '\n')
		{
			map->map[height][len] = line[len];
			len++;
		}
		while (len < map->map_length)
		{
			map->map[height][len] = ' ';
			len++;
		}
		map->map[height][len] = '\0';
		free(line);
		line = get_next_line(fd);
		height++;
	}
	map->map[height] = NULL;
	return map;
}

// helper to print the full map
void print_map(t_map *map)
{
	int i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
}
