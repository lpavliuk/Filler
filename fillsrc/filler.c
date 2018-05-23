/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:07:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/17 18:12:39 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	work_spy(t_f *fill, int i, int j, int z)
{
	z++;
	if (j < Y - 1 && MAP[i][j + 1] == 0)
		MAP[i][j + 1] = z;
	if (j > 0 && MAP[i][j - 1] == 0)
		MAP[i][j - 1] = z;
	if (i < X - 1 && MAP[i + 1][j] == 0)
		MAP[i + 1][j] = z;
	if (i > 0 && MAP[i - 1][j] == 0)
		MAP[i - 1][j] = z;
}

static void	check_map(t_f *fill)
{
	int i;
	int j;
	int z;

	z = -1;
	if (SYMBL == -1)
		ENEMY = -2;
	else
		ENEMY = -1;
	while (++z < (X + Y))
	{
		i = -1;
		while (++i < X)
		{
			j = -1;
			while (++j < Y)
			{
				if (MAP[i][j] == ENEMY)
					work_spy(fill, i, j, 0);
				else if (z > 0 && MAP[i][j] == z)
					work_spy(fill, i, j, z);
			}
		}
	}
}

static void	clean_fill(t_f *fill, char freeshka, char first)
{
	int n;

	n = -1;
	SIZE_F_X = 0;
	SIZE_F_Y = 0;
	MIN_X = 0;
	MIN_Y = 0;
	BEST_X = 0;
	BEST_Y = 0;
	SUM = 0;
	FLAG = 0;
	FIGURE = NULL;
	LINE = NULL;
	if (freeshka)
	{
		while (++n < X)
			free(MAP[n]);
		free(MAP);
	}
	else if (first)
	{
		X = 0;
		Y = 0;
		ENEMY = 0;
	}
}

int			main(void)
{
	t_f		*fill;

	fill = malloc(sizeof(t_f));
	MAP = NULL;
	SYMBL = 0;
	clean_fill(fill, 0, 1);
	check_input(fill);
	while (get_next_line(0, &LINE) > 0)
	{
		if (!ft_strstr(LINE, "0123456789"))
		{
			free(LINE);
			get_next_line(0, &LINE);
		}
		free(LINE);
		write_map(fill);
		check_map(fill);
		work_with_figure(fill);
		ft_stralldel(FIGURE, (size_t)SIZE_F_X + 1);
		free(FIGURE);
		clean_fill(fill, 0, 0);
	}
	clean_fill(fill, 1, 0);
	free(fill);
	return (0);
}
