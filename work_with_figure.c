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
	if (!SUM || SUM <= summa)
	{
		BEST_X = i;
		BEST_Y = j;
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
	if (MAP[i][j] == ENEMY)
		return (1);
	else
		return (0);
}

static void	check_place_in_map(t_f *fill, int i, int jj)
{
	int	a;
	int	b;
	int j;
	int summa;

	summa = 0;
	a = MIN_X;
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
				else
					summa += FIGURE[a][b];
			}
			b++;
			j++;
		}
		a++;
		i++;
	}
	check_sum(fill, i - a, jj, summa);
}

static void	check_min_max_figure(t_f *fill)
{
	int a;
	int b;

	a = -1;
	while (++a < SIZE_F_X)
	{
		b = -1;
		while (++b < SIZE_F_Y)
		{
			if (FIGURE[a][b] == '*')
			{
				MIN_X = a;
				MIN_Y = b;
				return ;
			}
		}
	}
}

void		work_with_figure(t_f *fill)
{
	int i;
	int j;

	i = -1;
	check_min_max_figure(fill);
	while (++i < X)
	{
		j = -1;
		while (++j < Y)
		{
			if (MAP[i][j] == SYMBL)
				check_place_in_map(fill, i, j);
		}
	}
	if (SUM)
	{
		ft_printf("%d %d\n", (BEST_X - MIN_X), (BEST_Y - MIN_Y));
		dprintf(3, "%d %d\n", (BEST_X - MIN_X), (BEST_Y - MIN_Y));
	}
	else
		ft_printf("0 0\n");
}
