/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:07:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/16 17:14:57 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	write_map(t_f *fill)
{
	int		i;
	int		j;
	char	map[X + 1][Y + 1];

	i = 0;
	while (i < X)
	{
		j = 0;
		ft_bzero(map[i], Y + 1);
		while (j < Y)
		{
			map[i][j] = '.';
			j++;
		}
		dprintf(3, "%s\n", map[i]);
		i++;
	}
}

static void check_info(t_f *fill)
{
	char *line;

	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
		SYMBL = 'o';
	else
		SYMBL = 'x';
	free(line);
	get_next_line(0, &line);
	X = ft_atoi(&(line[8]));
	Y = ft_atoi(&(line[8 + ft_count(X, 10)]));
	dprintf(3, "SYMBL: %c\n", SYMBL);
	dprintf(3, "X: %d\nY: %d\n", X, Y);
	free(line);
}

int		main(void)
{
	t_f		*fill;
	int		i;
	int		fd;

	i = 1;
	X = 0;
	Y = 0;
	SYMBL = 0;
	fill = malloc(sizeof(t_f));
	fd = open("map", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check_info(fill);
	write_map(fill);
	free(fill);
	return (0);
}
