/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:07:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/16 21:16:04 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void write_coordinates(t_f *fill, int i)
{
	int n;

	n = 0;
	if (LINE && ft_strchr(LINE, '*'))
	{
		while (LINE[n] != '\0')
		{
			if (LINE[n] == '*')
			{
				dprintf(3, "OK!\n");
				X_F[NUM] = i; // Здесь сегфолт! ПОЧЕМУ БЛЯТЬ!!!???
				Y_F[NUM] = n; //
				NUM++;
				dprintf(3, "KO!\n");
			}
			n++;
		}
	}
}

static void	write_figure(t_f *fill)
{
	int i;
	int n;

	i = 0;
	n = 0;
	get_next_line(0, &LINE);
	i = ft_atoi(&(LINE[6]));
	n = ft_atoi(&(LINE[6 + ft_count(i, 10)]));
	free(LINE);
	dprintf(3, "i: %d\nn: %d\n", i, n);
	X_F = malloc(sizeof(int) * ((i * n) + 1));
	Y_F = malloc(sizeof(int) * ((i * n) + 1));
	i = 0;
	while (get_next_line(0, &LINE) > 0)
	{
		write_coordinates(fill, i);
		free(LINE);
		i++;
	}
	dprintf(3, "line: |%s|\n", LINE);
	write_coordinates(fill, i);
	free(LINE);
	i = -1;
	while (++i < NUM)
		dprintf(3, "X_F: %d\nY_F: %d\n", X_F[i], Y_F[i]);
}

static void	write_map(t_f *fill)
{
	int		i;
	int		j;
	int		n;
	char	map[X + 1][Y + 1];

	i = 0;
	get_next_line(0, &LINE);
	free(LINE);
	while (i < X)
	{
		n = -1;
		j = 4;
		ft_bzero(map[i], Y + 1);
		get_next_line(0, &LINE);
		while (++n < Y)
			map[i][n] = LINE[j++];
		dprintf(3, "%s\n", map[i]);
		free(LINE);
		i++;
	}
}

static void check_info(t_f *fill)
{
	get_next_line(0, &LINE);
	if (ft_strstr(LINE, "p1"))
		SYMBL = 'o';
	else
		SYMBL = 'x';
	free(LINE);
	get_next_line(0, &LINE);
	X = ft_atoi(&(LINE[8]));
	Y = ft_atoi(&(LINE[8 + ft_count(X, 10)]));
	dprintf(3, "SYMBL: %c\n", SYMBL);
	dprintf(3, "X: %d\nY: %d\n", X, Y);
	free(LINE);
}

int		main(void)
{
	t_f		*fill;
	int		i;
	int		fd;

	i = 1;
	X = 0;
	Y = 0;
	X_F = 0;
	Y_F = 0;
	NUM = 0;
	LINE = NULL;
	SYMBL = 0;
	fill = malloc(sizeof(t_f));
	fd = open("map", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check_info(fill);
	write_map(fill);
	write_figure(fill);
	free(fill);
	// free(X_F);
	// free(Y_F);
	return (0);
}
