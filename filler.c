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
		MAP[i][j + 1] = (char)z;
	if (j > 0 && MAP[i][j - 1] == 0)
		MAP[i][j - 1] = (char)z;
	if (i < X - 1 && MAP[i + 1][j] == 0)
		MAP[i + 1][j] = (char)z;
	if (i > 0 && MAP[i - 1][j] == 0)
		MAP[i - 1][j] = (char)z;
}

static void	check_map(t_f *fill)
{
	int i;
	int j;
	int x;
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

static void	clean_fill(t_f *fill, char freeshka)
{
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
		ft_stralldel(MAP, (size_t)X + 1);
		free(MAP);
		free(fill);	
	}
}

/**************************************************************************/
/*
**	ВЫВОД СОДЕРЖАНИЯ СТРУКТУРЫ
*/
/**************************************************************************/

void		write_info(t_f *fill)
{
	int i;
	int j;

	i = -1;
	dprintf(3, "SYMBL: %d\n", SYMBL);
	dprintf(3, "ENEMY: %d\n", ENEMY);
	dprintf(3, "X: %d\nY: %d\n", X, Y);
	while (++i < X)
	{
		j = -1;
		while (++j < Y)
			dprintf(3, "%3d", MAP[i][j]);
		dprintf(3, "\n");
	}
	dprintf(3, "SIZE_F_X: %d\nSIZE_F_Y: %d\n", SIZE_F_X, SIZE_F_Y);
	i = -1;
	while (++i < SIZE_F_X)
	{
		dprintf(3, "%s", FIGURE[i]);
		dprintf(3, "\n");
	}
}

/**************************************************************************/

int			main(void)
{
	t_f		*fill;

	fill = malloc(sizeof(t_f));
	X = 0;
	Y = 0;
	MAP = NULL;
	SYMBL = 0;
	ENEMY = 0;
	clean_fill(fill, 0);
	open("map", O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
		write_info(fill);
		ft_stralldel(FIGURE, (size_t)SIZE_F_X + 1);
		free(FIGURE);
		clean_fill(fill, 0);
	}
	clean_fill(fill, 1);
	return (0);
}
