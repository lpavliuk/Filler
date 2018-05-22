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

static void	write_figure(t_f *fill)
{
	int i;
	int n;

	i = 0;
	n = 0;
	get_next_line(0, &LINE);
	SIZE_F_X = ft_atoi(&(LINE[6]));
	SIZE_F_Y = ft_atoi(&(LINE[6 + ft_count(i, 10)]));
	free(LINE);
	FIGURE = (char **)malloc(sizeof(char *) * (SIZE_F_X + 1));
	i = 0;
	while (i < SIZE_F_X)
	{
		n = -1;
		get_next_line(0, &LINE);
		if (LINE[0] == '\0')
			break ;
		FIGURE[i] = (char *)malloc(sizeof(char) * (SIZE_F_Y + 1));
		ft_bzero(FIGURE[i], (size_t)SIZE_F_Y + 1);
		while (++n < SIZE_F_Y)
			FIGURE[i][n] = LINE[n];
		free(LINE);
		i++;
	}
	FIGURE[i] = 0;
}

static void	check_dot_zero(t_f *fill, int i)
{
	int n;
	int j;

	n = 0;
	j = 4;
	while (n < Y)
	{
		if (LINE[j] == '.')
			MAP[i][n] = 0;
		else if (LINE[j] == 'O')
			MAP[i][n] = -1;
		else if (LINE[j] == 'X')
			MAP[i][n] = -2;
		j++;
		n++;
	}
}

void write_map(t_f *fill)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	while (i < X)
	{
		n = -1;
		j = 4;
		get_next_line(0, &LINE);
		check_dot_zero(fill, i);
		free(LINE);
		i++;
	}
	write_figure(fill);
}

void		check_input(t_f *fill)
{
	int i;

	i = -1;
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
	MAP = (char **)malloc(sizeof(char *) * (X + 1));
	while (++i < X)
	{
		MAP[i] = (char *)malloc(sizeof(char) * (Y + 1));
		ft_bzero(MAP[i], (size_t)Y + 1);
	}
	MAP[i] = 0;
}
