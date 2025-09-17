/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:12:04 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/11 16:54:17 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# define M_PI 3.14159265358979323846
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_cub3d
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_win;
	void	*mlx_connection;
}	t_cub3d;

typedef struct s_map
{
	int		map_length;
	int		map_height;
	char	**map;
}	t_map;

typedef struct s_index
{
	t_cub3d *cub3d;
	t_map	*map;
}	t_index;


void	mlx_creation(t_cub3d *img);
void	mlx_creation2(t_cub3d *img);
int		handle_key(int keycode,t_index *index);
int		handle_closing(t_index *index);
t_index *init_index(void);

//arguments
bool	arg_validation(int argc, char **argv);

//cleanup
void	free_index(t_index *index);
void 	clean_exit(t_index *index);

//error handling
void	ft_putstr_fd(char *s, int fd);

//map 
t_map	*file_validation(char *file);
t_map	*map_validation( int fd, t_map *map);
int		get_lenght(int fd, char *line);

#endif
