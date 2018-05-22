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

static void	check_figure_to_map(t_f *fill, int i, int j)
{
	int a;
	int b;

	a = -1;
	while (++a < SIZE_F_X)
	{
		b = -1;
		while (++b < SIZE_F_Y)
		{
			//            if (FIGURE[a][b] == '*')
			//                in_map();
		}
	}
}

void		work_with_figure(t_f *fill)
{
	int i;
	int j;

	i = -1;
	while (++i < X)
	{
		j = -1;
		while (++j < Y)
		{
			if (MAP[i][j] == SYMBL)
				check_figure_to_map(fill, i, j);
		}
	}
}
