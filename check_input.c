/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:57:19 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/17 16:01:46 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	write_coordinates(t_f *fill, int i)
{
	int n;

	n = 0;
	if (LINE && ft_strchr(LINE, '*'))
	{
		while (LINE[n] != '\0')
		{
			if (LINE[n] == '*')
			{
				X_F[NUM] = i;
				Y_F[NUM] = n;
				NUM++;
			}
			n++;
		}
	}
}

static void	write_figure(t_f *fill)
{
	int i;

	i = 0;
	get_next_line(0, &LINE);
	SIZE_F_X = ft_atoi(&(LINE[6]));
	SIZE_F_Y = ft_atoi(&(LINE[6 + ft_count(i, 10)]));
	free(LINE);
	X_F = malloc(sizeof(int) * (SIZE_F_X * SIZE_F_Y + 1));
	Y_F = malloc(sizeof(int) * (SIZE_F_X * SIZE_F_Y + 1));
	ft_bzero(X_F, (SIZE_F_X * SIZE_F_Y + 1));
	ft_bzero(Y_F, (SIZE_F_X * SIZE_F_Y + 1));
	SIZE_F_X--;
	SIZE_F_Y--;
	i = 0;
	while (get_next_line(0, &LINE) > 0)
	{
		write_coordinates(fill, i);
		free(LINE);
		i++;
	}
	free(LINE);
}

static void	write_map(t_f *fill)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	MAP = (char **)malloc(sizeof(char *) * (X + 1));
	get_next_line(0, &LINE);
	free(LINE);
	while (i < X)
	{
		n = -1;
		j = 4;
		MAP[i] = (char *)malloc(sizeof(char) * (Y + 1));
		ft_bzero(MAP[i], Y + 1);
		get_next_line(0, &LINE);
		while (++n < Y)
		{
			if (LINE[j] == '.')
				MAP[i][n] = 0;
				else if (LINE[j] == 'O')
				MAP[i][n] = -1;
			else
				MAP[i][n] = -2;
			j++;
		}
		free(LINE);
		i++;
	}
}

void		check_input(t_f *fill)
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
	free(LINE);
	write_map(fill);
	write_figure(fill);
}
