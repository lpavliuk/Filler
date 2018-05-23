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
	if ((!SUM || (SUM >= summa)) && FLAG == 1)
	{
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
			return (1);
	}
	else if (MAP[i][j] == ENEMY)
		return (1);
	return (0);
}

static void	check_place_in_map(t_f *fill, int ii, int jj, int summa)
{
	int	a;
	int	b;
	int i;
	int j;

	a = MIN_X - 1;
	i = ii;
	while (++a < SIZE_F_X)
	{
		j = jj;
		b = MIN_Y - 1;
		while (++b < SIZE_F_Y)
		{
			if (FIGURE[a][b] == '*')
			{
				if (check_map(fill, i, j))
					return ;
				if (MAP[i][j] != SYMBL)
					summa += MAP[i][j];
			}
			j++;
		}
		i++;
	}
	check_sum(fill, ii, jj, summa);
}

static void	check_min_max_figure(t_f *fill)
{
	int a;
	int b;
	int flag;

	a = 0;
	flag = 0;
	while (a < SIZE_F_X)
	{
		b = 0;
		while (b < SIZE_F_Y)
		{
			if (FIGURE[a][b] == '*')
			{
				if (!flag++)
				{
					MIN_X = a;
					MIN_Y = b;
				}
				else if (b < MIN_Y)
					MIN_Y = b;
			}
			b++;
		}
		a++;
	}
}

void		work_with_figure(t_f *fill)
{
	int i;
	int a;
	int j;
	int b;

	i = 0;
	a = X;
	check_min_max_figure(fill);
	while (i < a)
	{
		j = 0;
		b = Y;
		while (j < b)
		{
			if (SYMBL == -1)
				check_place_in_map(fill, i, j, 0);
			else
				check_place_in_map(fill, a - 1, b - 1, 0);
			FLAG = 0;
			(SYMBL == -1) ? j++ : b--;
		}
		(SYMBL == -1) ? i++ : a--;
	}
	ft_printf("%d %d\n", (BEST_X), (BEST_Y));
}
