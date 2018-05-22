/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_figure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:48:36 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/22 13:48:38 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	check_sum(t_f *fill, int i, int j, int summa)
{
	if ((!SUM || (SUM >= summa && summa)) && FLAG == 1)
	{
		dprintf(3, "summa: %d\n", summa);
		BEST_X = i - MIN_X;
		BEST_Y = j - MIN_Y;
		SUM = summa;
	}
}

static int	check_map(t_f *fill, int i, int j)
{
	if (i >= X || j >= Y)
		return (1);
	if (MAP[i][j] == SYMBL)
	{
		FLAG++;
		if (FLAG > 1)
		{
			FLAG = 0;
			return (1);
		}
	}
	else if (MAP[i][j] == ENEMY)
		return (1);
	return (0);
}

static void	check_place_in_map(t_f *fill, int ii, int jj)
{
	int	a;
	int	b;
	int i;
	int j;
	int summa;

	summa = 0;
	a = MIN_X;
	i = ii;
	while (a < SIZE_F_X)
	{
		b = MIN_Y;
		j = jj;
		while (b < SIZE_F_Y)
		{
			if (FIGURE[a][b] == '*')
			{
				if (check_map(fill, i, j))
					return ;
				else if (MAP[i][j] != SYMBL)
					summa += MAP[i][j];
			}
			b++;
			j++;
		}
		a++;
		i++;
	}
	check_sum(fill, ii, jj, summa);
}

static void	check_min_max_figure(t_f *fill)
{
	int a;
	int b;

	a = 0;
	while (a < SIZE_F_X)
	{
		b = 0;
		while (b < SIZE_F_Y)
		{
			if (FIGURE[a][b] == '*')
			{
				MIN_X = a;
				MIN_Y = b;
				return ;
			}
			b++;
		}
		a++;
	}
}

void		work_with_figure(t_f *fill)
{
	int i;
	int j;

	i = -1;
	check_min_max_figure(fill);
	dprintf(3, "MIN_Y: %d\n", MIN_Y);
	dprintf(3, "MIN_X: %d\n", MIN_X);
	while (++i < X)
	{
		j = 0;
		while (j < Y)
		{
			check_place_in_map(fill, i, j);
			FLAG = 0;
			j++;
		}
	}
	if (SUM)
	{
		ft_printf("%d %d\n", (BEST_X), (BEST_Y));
		dprintf(3, "SUM: %d\n", SUM);
		dprintf(3, "%d %d\n", (BEST_X), (BEST_Y));
		dprintf(3, "%d %d\n", (MIN_X), (MIN_Y));
	}
	else
		ft_printf("0 0\n");
}
