/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opavliuk <opavliuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 13:07:52 by opavliuk          #+#    #+#             */
/*   Updated: 2018/05/17 15:03:16 by opavliuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	write_info(t_f *fill)
{
	int i;

	i = -1;
	dprintf(3, "SYMBL: %c\n", SYMBL);
	dprintf(3, "X: %d\nY: %d\n", X, Y);
	while (MAP[++i] != '\0')
		dprintf(3, "%s\n", MAP[i]);
	dprintf(3, "SIZE_F_X: %d\nSIZE_F_Y: %d\n", SIZE_F_X, SIZE_F_Y);
	i = -1;
	while (++i < NUM)
		dprintf(3, "X_F: %d\nY_F: %d\n", X_F[i], Y_F[i]);
}

int		main(void)
{
	t_f		*fill;
	int		i;
	int		fd;

	i = 1;
	fill = malloc(sizeof(t_f));
	X = 0;
	Y = 0;
	X_F = NULL;
	Y_F = NULL;
	NUM = 0;
	MAP = NULL;
	LINE = NULL;
	SYMBL = 0;
	fd = open("map", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	check_input(fill);
	
	write_info(fill);
	ft_stralldel(MAP, X + 1);
	free(X_F);
	free(Y_F);
	free(fill);
	return (0);
}
