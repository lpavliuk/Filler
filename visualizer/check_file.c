/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 19:29:39 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/24 19:29:40 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	check_input(t_mlx *mlx)
{
	int i;
	int	n;

	i = 0;
	while (i < 9)
	{
		n = 7;
		get_next_line(0, &LINE);
		if (ft_strstr(LINE, "launched"))
		{
			if (ft_strchr(&LINE[n], '/'))
			{
				while (LINE[n] != '/')
					n++;
			}
			if (i > 6)
				PLYR_X = ft_strdup(&LINE[n + 1]);
			else
				PLYR_O = ft_strdup(&LINE[n + 1]);
		}
		free(LINE);
		i++;
	}
}

void	write_map(t_mlx *mlx)
{
	int x;
	int y;

	get_next_line(0, &LINE);
	free(LINE);
	MAP = (char **)malloc(sizeof(char *) * (I + 1));
	x = -1;
	while (++x < I)
	{
		y = -1;
		MAP[x] = (char *)malloc(sizeof(char) * (J + 1));
		ft_bzero(MAP[x], J + 1);
		get_next_line(0, &LINE);
		while (++y < J)
			MAP[x][y] = LINE[4 + y];
		free(LINE);
	}
	MAP[x] = 0;
}
