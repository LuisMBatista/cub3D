/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:27:11 by lumiguel          #+#    #+#             */
/*   Updated: 2025/09/10 17:53:07 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	arg_validation(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2 || !argv[1] || !argv[1][0])
		return (false);
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (ft_strncmp(argv[1] + i, ".cub", 4) != 0)
		return (false);
	return (true);
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
