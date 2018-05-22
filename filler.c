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

// static void	put_figure(t_f *fill)
// {
// 	int 	i;
// 	int 	j;
// 	int 	x;
// 	char	flag;

// 	i = -1;
// 	flag = 0;
// 	if (SYMBL == 'o')
// 		x = -2;
// 	else
// 	{
// 		x = -1;
// 		flag = 1;
// 	}
// 	while (++i < X)
// 	{
// 		j = -1;
// 		while (++j < Y)
// 		{
// 			if (MAP[i][j] == x && !flag)
// 				check_place(fill);
// 			else
// 			{
// 				()
// 			}

				
// 		}
// 	}
// }

// static void	move_figure(t_f *fill)
// {
	
// }

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
	int x;
	int z;

	z = -1;
	if (SYMBL == 'o')
		x = -2;
	else
		x = -1;
	while (++z < (X + Y))
	{
		i = -1;
		while (++i < X)
		{
			j = -1;
			while (++j < Y)
			{
				if (MAP[i][j] == x)
					work_spy(fill, i, j, 0);
				else if (z > 0 && MAP[i][j] == z)
					work_spy(fill, i, j, z);
			}
		}
	}
}

static void	clean_fill(t_f *fill, char freeshka)
{
	X = 0;
	Y = 0;
	FIGURE = NULL;
	MAP = NULL;
	LINE = NULL;
	SYMBL = 0;
	if (freeshka)
	{
		ft_stralldel(MAP, X + 1);
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
	dprintf(3, "SYMBL: %c\n", SYMBL);
	dprintf(3, "X: %d\nY: %d\n", X, Y);
	while (++i < X)
	{
		j = -1;
		while (++j < Y)
		{
			if (MAP[i][j + 1] < 0)
			{
				dprintf(3, "%d", MAP[i][j]);
				if (j >= 0 && MAP[i][j + 1] < 10)
					dprintf(3, " ");
			}
			else
			{
				if (MAP[i][j + 1] >= 10 ||
					(MAP[i][j] >= 10 && MAP[i][j + 1] < 10))
					dprintf(3, "%d ", MAP[i][j]);
				else
					dprintf(3, "%d  ", MAP[i][j]);
			}
		}
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
	int		i;

	i = 1;
	fill = malloc(sizeof(t_f));
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
		// move_figure(fill);
		// put_figure(fill);
		write_info(fill);
		ft_stralldel(FIGURE, SIZE_F_X + 1);
		free(FIGURE);
	}
	clean_fill(fill, 1);
	return (0);
}
