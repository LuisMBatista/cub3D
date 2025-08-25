/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:12:04 by lumiguel          #+#    #+#             */
/*   Updated: 2025/08/25 15:26:56 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H


# define M_PI 3.14159265358979323846
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800

typedef struct s_cub3d
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_win;
	void	*mlx_connection;
	int		map_height;
	int		map_length;
}				t_cub3d;

void	mlx_creation(t_cub3d *img);
void	mlx_creation2(t_cub3d *img);

#endif